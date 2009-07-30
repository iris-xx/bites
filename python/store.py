
import bites
import bsddb.db as db
import datetime
import hostname

def tablename(cls):
    return cls.DESCRIPTOR.full_name

class ProtoStore(object):
    def __init__(self, prefix=hostname.hostname,
                       name=None,
                       suffix=None,
                       name_factory=datetime.date.today):
        if not name:
            name = name_factory()
        if suffix:
            self.path = '.'.join((str(prefix), str(name), str(suffix)))
        else:
            self.path = '.'.join((str(prefix), str(name)))

        self.env = bites.env
        self.tables = {}

    def init_table(self, cls):
        table = db.DB(self.env)
        table.open(self.path, tablename(cls), db.DB_BTREE, db.DB_CREATE)
        self.tables.setdefault(cls, table)

    def get(self, cls, key):
        if not self.tables.has_key(tablename(cls)):
            self.init_table(cls)
        obj = cls()
        obj.ParseFromString(self.tables[cls].get(key))
        return obj

    def put(self, key, obj):
        name = tablename(cls)
        if not self.tables.has_key(name):
            self.init_table(cls)
        self.tables[name].put(key, obj.SerializeToString())

