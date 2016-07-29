import socket
import sys
import errno
from datetime import datetime, date, time, timedelta
import time
from select import select, error as SelectException
import random


class action:
    def __init__(self, name, time, t):
        self.name = name
        if time == 0:
            self.time = 1
        else:
            self.time = time * (1000000 / t)
        self.moy = -4242
    def time(self):
        return self.time
    def name(self):
        return self.name
    def set_moy(self, val):
        if self.moy == -4242:
            self.moy = val
        else:
            self.moy = (val + self.moy) / 2
    def moy(self):
        return self.moy

def connect_server(team, host, port):
    print "\n\n"+team, host, port
    running = 1
    try:
        server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server.connect((host,port))
        team = team + '\n'
        data = server.recv(1024)
        server.send(team)
        data += server.recv(1024)
        data += server.recv(1024)
        print "Connexion Success\n"
        return server
    except:
        print "\033[31mConnexion Fail\033[39m\n"
        running = 0
        return 0

def timetoint(timestamp):
    val = float(timestamp.seconds * 1000000 + timestamp.microseconds)
    return val


def time_cmd(server, action):
    cmd = action.name
    try:
        cmd = cmd + '\n'
        to = timedelta(microseconds=action.time)
        t1 = datetime.now()
        server.send(cmd)
        data = server.recv(1024)
        if action.name == "incantation":
            data = server.recv(1024)
        tres = datetime.now() - t1
        ecart = str(tres - to)
        ecart_pourc = int((timetoint(tres) / timetoint(to)) * 100) - 100
        action.set_moy(ecart_pourc)
        if (ecart_pourc > 20 or ecart_pourc < -5):
            print "\033[31msend:"+cmd[0:-1]+"\nreceive:"+data[0:-1]+"\ntexec:"+str(tres)+"\ntopti:"+str(to)+"\ntdiff:"+ecart+"("+str(ecart_pourc)+"%)\n\033[39m"
        else:
            print "send:"+cmd[0:-1]+"\ntime: OK("+str(ecart_pourc)+"%)\n"
        return 1
    except:
        print "error send:"+cmd[0:-1]
        return 0


t = 5

tab_action = []
tab_action.append(action("avance", 7, t))
tab_action.append(action("droite", 7, t))
tab_action.append(action("voir", 7, t))
tab_action.append(action("prend linemate", 7, t))
tab_action.append(action("pose linemate", 7, t))
tab_action.append(action("expulse", 7, t))
tab_action.append(action("broadcast deputeddddddddddddddddddddddddddddddddddddddddddddddddddddsssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddffffffffffffffffffffffffffffwwwwwwwwwwwwwwwwwwwwww", 7, t))
tab_action.append(action("broadcast eeeeeeeeeeeeeeeeeeeeeeeeeee", 7, t))
tab_action.append(action("inventaire", 1, t))
tab_action.append(action("incantation", 300, t))
tab_action.append(action("fork", 42, t))
tab_action.append(action("dlamerde", 0, t))
tab_action.append(action("null", -1, t))


u = 0
while u < 1000000:
    server = connect_server("team", "denfert", 42000)
    if server:
        i = 0
        while tab_action[i].time >= 0:
            time_cmd(server, tab_action[i])
            i += 1
        server.close()
    u += 1

i = 0
while tab_action[i].time >= 0:
    print tab_action[i].name+" : "+str(tab_action[i].moy)+"%"
    i += 1
