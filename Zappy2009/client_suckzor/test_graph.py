import socket
import sys
import errno
from datetime import datetime, date, time, timedelta
import time
from select import select, error as SelectException
import random

def connect_server(team, host, port):
    print "\n\n"+team, host, port
    running = 1
    try:
        server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server.connect((host,port))
        team = team + '\n'
        data = server.recv(1024)
        server.send(team)
        if team == "GRAPHIC\n":
            data = server.recv(1024)
            while data[:3] != "pnw":
                data = server.recv(1024)
                print data[:-1]
        else:
            data += server.recv(1024)
            data += server.recv(1024)
        print "Connexion Success\n"
        return server
    except:
        print "\033[31mConnexion Fail\033[39m\n"
        running = 0
        return 0

def act_pin(server):
    data = server.recv(1024)
    if data[:3] != "pin":
        return 0
    nb = data[4:6]
    print "Test cmd pin sur le client:"+nb
    while 1:
        server.send("pin "+nb+"\n")
        data = server.recv(1024)
        print data[:-1]
        time.sleep(0.01)

t = 1000

server = connect_server("GRAPHIC", "localhost", 42000)

act_pin(server)

server.close()
