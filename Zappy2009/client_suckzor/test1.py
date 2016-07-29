import socket
import sys
import errno
from select import select, error as SelectException
import random


def connect_server(team, host, port):
    print team, host, port
    running = 1
    try:
        server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server.connect((host,port))
        data = server.recv(1024)
        team = team + '\n'
        data += server.recv(1024)
    except:
        print 'Server name or port is incorrect'
        running = 0
        return 0

connect_server("team", "odeon", 42000)
