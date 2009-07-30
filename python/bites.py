
import bsddb.db as db
import datetime
import hostname
import sys

from structs_pb2 import Point, Rectangle
import vision_pb2 as vision

def init_env(home):
    env = db.DBEnv()
    env.open(home, db.DB_INIT_CDB | db.DB_INIT_MPOOL | db.DB_CREATE)
    return env

def tablename(msg):
    return msg.__class__.DESCRIPTOR.full_name

class ProtoStore(object):
    def __init__(self, env, prefix=hostname.hostname,
                            name=None,
                            suffix=None,
                            name_factory=datetime.date.today):
        self.env = env

        if not name:
            name = name_factory()
        if suffix:
            self.path = '.'.join((str(prefix), str(name), str(suffix)))
        else:
            self.path = '.'.join((str(prefix), str(name)))

        self.tables = {}

    def init_table(self, name):
        table = db.DB(self.env)
        table.open(self.path, name, db.DB_BTREE, db.DB_CREATE)
        self.tables.setdefault(name, table)

    def get(self, key, msg):
        name = tablename(msg)
        if not self.tables.has_key(name):
            self.init_table(name)
        msg.ParseFromString(self.tables[name].get(key))
        return msg

    def put(self, key, msg):
        name = tablename(msg)
        if not self.tables.has_key(name):
            self.init_table(name)
        self.tables[name].put(key, msg.SerializeToString())

