
#include <boost/shared_ptr.hpp>
#include <db.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
#include <iostream>
#include <stdexcept>

#include "bites.h"

using namespace std;
using namespace boost;
using namespace google::protobuf;


class DB_ENV_deleter {
  public:
    void operator()(DB_ENV *env) {
      env->close(env, 0);
    }
};

class DB_deleter {
  public:
    void operator()(DB *db) {
      db->close(db, 0);
    }
};


shared_ptr<DB_ENV> bites::init_env(const char *home) {
  DB_ENV *env;
  int ret;
  if (ret = db_env_create(&env, 0))
    throw DBException(ret);
  
  if (ret = env->open(env, home, DB_INIT_CDB | DB_INIT_MPOOL | DB_CREATE, 0))
    throw DBException(ret);

  return shared_ptr<DB_ENV>(env, DB_ENV_deleter());
}

string bites::today() {
  const int MAX_SIZE = 11;
  char buf[MAX_SIZE];

  time_t now = time(NULL);
  const struct tm *now_tm = localtime(&now);
  strftime(buf, MAX_SIZE, "%Y-%m-%d", now_tm);
  return buf;
}

string bites::tablename(shared_ptr<Message> msg) {
  return msg->GetDescriptor()->full_name();
}

bites::ProtoStore::ProtoStore(shared_ptr<DB_ENV> env, string prefix,
                              string name, string suffix,
                              string (*name_factory)(void)) : env(env) {
  if (name == "")
    name = (*name_factory)();

  if (suffix == "")
    path = prefix + '.' + name;
  else
    path = prefix + '.' + name + '.' + suffix;
}

bites::ProtoStore::~ProtoStore() {
  tables.clear();
}

void bites::ProtoStore::init_table(string name) {
  DB *ptr;
  int ret;

  std::cout << "Initializing table " << name << std::endl;

  if (ret = db_create(&ptr, env.get(), 0))
    throw DBException(ret);

  shared_ptr<DB> table(ptr);

  if (ret = table->open(table.get(), NULL, path.c_str(), name.c_str(),
                        DB_BTREE, DB_CREATE, 0))
    throw DBException(ret);

  tables[name] = table;
}

void bites::ProtoStore::get(std::string key, shared_ptr<Message> msg) {
  string name(tablename(msg));

  tables[name];
  if (tables.find(name) == tables.end())
    init_table(name);

  shared_ptr<DB> table = tables[name];

  void *key_buf = malloc(key.size() * sizeof(char*));
  memcpy(key_buf, key.c_str(), key.size() * sizeof(char*));

  DBT db_key = {key_buf, key.size(), 0, 0, 0, NULL, 0};
  DBT db_data = {NULL, 0, 0, 0, 0, NULL, DB_DBT_MALLOC};
  int ret;

  if (ret = table->get(table.get(), NULL, &db_key, &db_data, 0)) {
    free(key_buf);
    throw DBException(ret);
  }

  if (!msg->ParseFromArray(db_data.data, db_data.size)) {
    free(key_buf);
    free(db_data.data);
    throw runtime_error("Parsing error");
  }
  free(key_buf);
  free(db_data.data);
}

void bites::ProtoStore::put(std::string key, shared_ptr<Message> msg) {
  string name(tablename(msg));

  if (tables.find(name) == tables.end())
    init_table(name);

  shared_ptr<DB> table = tables[name];

  void *key_buf = malloc(key.size() * sizeof(char*));
  int data_size = msg->ByteSize();
  void *data_buf = malloc(data_size);
  memcpy(key_buf, key.c_str(), key.size() * sizeof(char*));
  msg->SerializeToArray(data_buf, data_size);

  DBT db_key = {key_buf, key.size(), 0, 0, 0, NULL, 0};
  DBT db_data = {data_buf, data_size, data_size, 0, 0, NULL, DB_DBT_USERMEM};
  int ret;

  if (ret = table->put(table.get(), NULL, &db_key, &db_data, 0)) {
    free(key_buf);
    free(data_buf);
    throw DBException(ret);
  }
  free(key_buf);
  free(data_buf);
}

