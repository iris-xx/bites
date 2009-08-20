
import cProfile
#import pickle
import cPickle as pickle
import cStringIO
import struct

import bites

class DistanceBearing(object):
    def __init__(self):
        self.distance = 0.
        self.bearing = 0.
        self.distance_sd = 0.
        self.breaing_sd = 0.

class Detection(object):
    def __init__(self):
        self.x = 0
        self.y = 0
        self.width = 0.
        self.height = 0.
        self.center_x = 0
        self.center_y = 0
        self.angle_x = 0.
        self.angle_y = 0.
        self.foc_dist = 0.
        self.elevation = 0.

        self.db = DistanceBearing()

class Ball(object):
    def __init__(self):
        self.detect = Detection()
        self.radius = 0.
        self.confidence = 0


def init_Ball(ball):
    ball.radius = 0.
    ball.confidence = 0
    detect = ball.detect
    detect.x = 0
    detect.y = 0
    detect.width = 0.
    detect.height = 0.
    detect.center_x = 0
    detect.center_y = 0
    detect.angle_x = 0.
    detect.angle_y = 0.
    detect.foc_dist = 0.
    detect.elevation = 0.
    db = detect.db
    db.distance = 0.
    db.bearing = 0.
    db.distance_sd = 0.
    db.bearing_sd = 0.



def pickle_balls(f, n):
    p = pickle.Pickler(f, 2)
    for i in xrange(n):
        ball = Ball()
        p.dump(ball)
        
def buffer_balls(f, n):
    Ball = bites.vision.Ball
    for i in xrange(n):
        ball = Ball()
        init_Ball(ball)
        s = ball.SerializeToString()
        f.write(struct.pack("<i", len(s)) + s)


def unpickle_balls(f, n):
    l = []
    up = pickle.Unpickler(f)
    for i in xrange(n):
        l.append(up.load())
    return l

def unbuffer_balls(f, n):
    l = []
    Ball = bites.vision.Ball
    for i in xrange(n):
        len = struct.unpack("<i", f.read(4))[0]
        ball = Ball()
        ball.ParseFromString(f.read(len))
        l.append(ball)
    return l


def test_pickle(n):
    s = cStringIO.StringIO()
    pickle_balls(s, n)
    print 'Length of stream is', .tell()
    s.seek(0)
    l = unpickle_balls(s, n)

def test_buffer(n):
    s = cStringIO.StringIO()
    buffer_balls(s, n)
    print 'Length of stream is', s.tell()
    s.seek(0)
    l = unbuffer_balls(s, n)

if __name__ == '__main__':
    import sys
    if len(sys.argv) != 2:
        print >>sys.stderr, "Usage:  %s NBALLS" % sys.argv[0]
        sys.exit(-1)
    n = int(sys.argv[1])

    cProfile.run("test_pickle(%i)" % n)
    cProfile.run("test_buffer(%i)" % n)
    

