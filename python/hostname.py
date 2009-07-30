#!/usr/bin/env python

__doc__ = ''' \
Simple utility to determine the host machine's hostname.

Tries in order:
  * socket.gethostname
  * /etc/hostname
  * the `hostname` command
'''


try:
    import socket
    hostname = socket.gethostname()
except ImportError:
    try:
        hostname = file('/etc/hostname').read().strip()
    except IOError:
        try:
            import os
            hostname = os.open2('hostname')[1].read().strip()
        except:
            raise ImportError("Could not resolve hostname")

if __name__ == '__main__':
    print hostname

