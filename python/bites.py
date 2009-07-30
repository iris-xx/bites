
import bsddb.db as db
import sys

home = None
env = None

def set_home(path):
    global home
    home = str(path)

def init_env():
    global env, home
    if not home:
        raise TypeError('Home directory not set, use set_home(path) first')

    env = db.DBEnv()
    env.open(home, db.DB_INIT_CDB | db.DB_INIT_MPOOL | db.DB_CREATE |
                   db.DB_RECOVER)

