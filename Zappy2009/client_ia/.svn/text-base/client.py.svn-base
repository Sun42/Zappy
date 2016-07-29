#!/usr/bin/env python

import socket
import sys
import treat_command
import errno
from select import select, error as SelectException
import random
import buffer
import param
import parse_option


def select_server(input, trantor, running):
  size = 4096
  time_to_wait = 0.1
  try:
    inputready,outputready,exceptready = select(input,[],[], time_to_wait)
    if inputready == [] and outputready == [] and exceptready == []:
        if buffer.send_buffer(trantor) == 0:
            return 0
    else:
        for s in inputready:
            if s == trantor['server']:
              data = s.recv(size)
              if len(data) <= 0:
                print 'Server disconnected'
                return 0
              buffer.buf_recv(trantor, data)
  except SelectException , Err_Info:
      print 'Select: Error in select()'
      return 0
  return 1


def connect_server(team, host, port):
  print team, host, port
  running = 1
  try:
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.connect((host,port))
    team = team + '\n'
    data = server.recv(1024)
    server.send(team)
    nb_cli = server.recv(1024)
    map_size = server.recv(1024)
  except:
    print 'Server name or port is incorrect'
    running = 0
    return 0
  trantor = param.init_trantor(team, server)
  input = [server]
  if running:
    while running:
      running = select_server(input, trantor, running)
    server.close()


def main():
  try:
    team, host, port = parse_option.verif_args()
  except:
    print 'Usage -t TEAM -h HOST -p PORT'
  if port != '' and team != '':
    connect_server(team, host, int(port))

main()
