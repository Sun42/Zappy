/*
** main.c for main in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:22:35 2009 yavuz yurdusev
** Last update Thu Apr 23 21:29:16 2009 yavuz yurdusev
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

#include "serv_connexion.h"
#include "server.h"

static t_world		*get_set_world(t_world *world, char action)
{
  static t_world	*ptr_world;

  if (action)
    ptr_world = world;
  return (ptr_world);
}

void	exiter(int sig __attribute__((unused)))
{
  putstr("Arret du serveur\nFermeture de toutes les sockets\n");
  stop_server(get_set_world(NULL, 0));
}

void	handler(int sig)
{
  if (signal(sig, handler) == SIG_ERR)
    perror("Erreur : signal()");
  putstr("SIGNAL SIGPIPE recu!\n");
}

static void	print_config_world(t_world *world)
{
  putstr("\033[32mServer port : ");
  print_nb(world->port);
  putstr("\nMap Size : ");
  print_nb(world->width);
  putstr(" x ");
  print_nb(world->height);
  putstr("\nAction time : ");
  print_nb(1000000 / world->speed);
  putstr("\nTeams :");
  print_teams_list(world->team);
  putstr("\nMax clients per teams : ");
  print_nb(world->max_client);
  putstr("\nServer running\033[39m\n");
}

int		main(int argc, char **argv)
{
  t_world	world;

  if (signal(SIGINT, exiter) == SIG_ERR)
    perror("Erreur : signal()");
  if (signal(SIGPIPE, handler) == SIG_ERR)
    perror("Erreur : signal()");
  srand(time(0));
  parse_option(argc, argv, &world);
  create_all_clients(&world);
  print_config_world(&world);
  world.sock_serv = init_connexion(world.port);
  init_map(&world);
  get_set_world(&world, 1);
  run_server(&world);
  return (EXIT_SUCCESS);
}
