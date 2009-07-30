
import vision_pb2
import bites

HOME = '../home'
ACTIONS = ('store', 'load')

def print_image(img):
    lines = str(img).strip().split('\n')
    for line in lines:
        print '    ' + line

if __name__ == '__main__':

    import sys

    action = ACTIONS[0]
    if len(sys.argv) > 1:
        action = sys.argv[1]

    if action not in ACTIONS:
        print >>sys.stderr, "Usage:  %s [%s|%s]" % (sys.argv[0],
                                                    ACTIONS[0],
                                                    ACTIONS[1])
        sys.exit(-1)

    env = bites.init_env('../home')
    store = bites.ProtoStore(env)

    key = raw_input('key? ')

    image = vision_pb2.Image()

    if action == ACTIONS[0]:
        image.encoding = vision_pb2.Image.YUV422
        image.width = 320
        image.height = 240
        image.data = 'hello world'
        print "Image '%s':" % key
        print_image(image)
        store.put(key, image)
        print '--> Stored'

    else:
        store.get(key, image)
        print "--> Retrieved"
        print "Image '%s':" % key
        print_image(image)

