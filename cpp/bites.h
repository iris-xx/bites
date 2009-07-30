
#ifndef __bites_h_DEFINED
#define __bites_h_DEFINED

#include <boost/shared_ptr.hpp>
#include <db.h>
#include <exception>
#include <google/protobuf/message.h>
#include <map>

namespace bites {

  class DBException : public std::exception {
    public :
      DBException(int err) : dberr(err) { }

      virtual const char* what() {
        return db_strerror(dberr);
      }
    private:
      int dberr;
  };

  boost::shared_ptr<DB_ENV> init_env(const char *home);

  static std::string determine_hostname() {
    char buf[256];
    gethostname(buf, 256);
    return buf;
  }
  static std::string hostname(determine_hostname());

  std::string today();
  std::string tablename(boost::shared_ptr<google::protobuf::Message> msg);

  class ProtoStore {
    public:
      ProtoStore(boost::shared_ptr<DB_ENV> env,
                 std::string prefix = hostname,
                 std::string name = "",
                 std::string suffix = "",
                 std::string (*name_factory)(void) = &today);
      ~ProtoStore();

      void init_table(std::string name);
      void get(std::string key,
               boost::shared_ptr<google::protobuf::Message> msg);
      void put(std::string key,
               boost::shared_ptr<google::protobuf::Message> msg);

    private:
      boost::shared_ptr<DB_ENV> env;
      std::string path;
      std::map<std::string, boost::shared_ptr<DB> > tables;
  };

}

#endif
