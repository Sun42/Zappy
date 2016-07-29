/*
** parse_options2.c for parse_options2 in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:22:21 2009 yavuz yurdusev
** Last update Thu Apr 23 20:22:21 2009 yavuz yurdusev
*/

#include <stdlib.h>

#include "ia_command.h"
#include "parse_options.h"

void	set_height(int ac, char **av, t_world *world, int *i)
{
  world->height = atoi(av[*i]);
  if (world->height < 1)
    usage();
  while (*i < ac && av[*i][0] != '-')
    (*i)++;
}

void	set_width(int ac, char **av, t_world *world, int *i)
{
  world->width = atoi(av[*i]);
  if (world->width < 1)
    usage();
  while (*i < ac && av[*i][0] != '-')
    (*i)++;
}

void	set_max_client(int ac, char **av, t_world *world, int *i)
{
  world->max_client = atoi(av[*i]);
  if (world->max_client < 1)
    usage();
  while (*i < ac && av[*i][0] != '-')
    (*i)++;
}

void	set_speed(int ac, char **av, t_world *world, int *i)
{
  world->speed = atoi(av[*i]);
  if (world->speed < 1 || world->speed > 100000)
    usage();
  world->speed = 1000000 / world->speed;
  while (*i < ac && av[*i][0] != '-')
    (*i)++;
}

void	set_teams(int ac, char **av, t_world *world, int *i)
{
  while (*i < ac && av[*i][0] != '-')
    {
      if (cmd_cmp(av[*i], KEY_GUI))
	  usage();
      add_new_team(&(world->team), av[*i]);
      (*i)++;
    }
}
