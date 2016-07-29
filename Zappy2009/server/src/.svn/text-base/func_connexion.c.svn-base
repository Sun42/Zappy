/*
** func_connexion.c for func_connexion in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:33:05 2009 yavuz yurdusev
** Last update Sat Apr 25 16:24:04 2009 yavuz yurdusev
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "buffer.h"
#include "serv_connexion.h"

int			init_connexion(int port)
{
  int			sock;
  struct sockaddr_in	sin;

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
      perror("Erreur : socket() --> init_connexion()");
      exit(EXIT_FAILURE);
    }
  sin.sin_addr.s_addr = htonl(INADDR_ANY);
  sin.sin_port = htons(port);
  sin.sin_family = AF_INET;
  if (bind(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    {
      perror("Erreur : bind() --> init_connexion()");
      exit(EXIT_FAILURE);
    }
  if (listen(sock, MAX_CLIENTS) < 0)
    {
      perror("Erreur : listen() --> init_connexion()");
      exit(EXIT_FAILURE);
    }
  return (sock);
}

int	new_connexion(int sock)
{
  sock = accept(sock, NULL, NULL);
  if (sock == -1)
    {
      perror("Erreur : accept() --> new_connexion()");
      return (DEAD);
    }
  if (sock >= 1022)
    {
      putstr("SOCK trop grand\n");
      if (close(sock) == -1)
	perror("Erreur : close() -- > new_connexion()");
      return (DEAD);
    }
  putstr("New client connected on the server on the socket ");
  print_nb(sock);
  my_putchar('\n');
  return (sock);
}

void	read_client(t_world *world, t_cli *cli)
{
  int	nbytes;
  char	buffer[BUF_RECV_SEND];

  nbytes = recv(cli->sock, buffer, BUF_RECV_SEND - 1, 0);
  if (nbytes <= 0)
    {
      if (nbytes == -1)
	perror("Erreur : recv() --> read_client()");
      ultra_kill(world, cli);
      return ;
    }
  putstr("\033[32mReceive from client num (");
  print_nb(cli->numero);
  putstr(") Size : ");
  print_nb(nbytes);
  putstr("\033[39m\n");
  save_cmd(cli, buffer, nbytes, 'R');
}

void	write_client(t_world *world, t_cli *cli)
{
  int	nbytes;
  int	len;
  char	*buffer;

  len = access_cmdlen(cli, 'W');
  if (len < 0 || (buffer = access_cmd(cli, 'W')) == NULL)
    return ;
  nbytes = send(cli->sock, buffer, len, 0);
  if (nbytes == -1)
    {
      perror("Erreur : send() --> write_client()");
      ultra_kill(world, cli);
      return ;
    }
  putstr("\033[34mSend to client num (");
  print_nb(cli->numero);
  putstr(") Size : ");
  print_nb(len);
  putstr(" - Sended : ");
  print_nb(nbytes);
  putstr("\033[39m\n");
  unsave_cmd(cli, nbytes, 'W');
  if (cli->statut == WILL_DIE && access_cmdlen(cli, 'W') <= 0)
    ultra_kill(world, cli);
}
