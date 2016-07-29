/*
** func_client.c for func_client in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:33:13 2009 yavuz yurdusev
** Last update Fri Apr 24 22:55:03 2009 yavuz yurdusev
*/

#include <stdlib.h>

#include "gui_send.h"
#include "server.h"

void	init_position(t_world *world, t_cli *ia)
{
  ia->pos.x = rand() % world->width;
  ia->pos.y = rand() % world->height;
  ia->pos.direction = rand() % 4 + 1;
  add_pcli(&(world->map[ia->pos.y][ia->pos.x].pcli), ia->pcli);
  if (world->map[ia->pos.y][ia->pos.x].elevation && world->pgui != NULL)
    gui_pie(world, ia->pos.y, ia->pos.x, '0');
  world->map[ia->pos.y][ia->pos.x].elevation = 0;
  world->map[ia->pos.y][ia->pos.x].nb_joueur += 1;
}

t_cli	*find_dead_cli(t_world *world)
{
  t_cli	*cli;

  cli = world->client;
  while (cli != NULL)
    {
      if (cli->statut == DEAD)
	return (cli);
      cli = cli->next;
    }
  return (NULL);
}

t_cli	*find_egg(t_world *world, t_team *team)
{
  t_cli	*cli;

  cli = world->client;
  while (cli != NULL)
    {
      if (cli->statut == GHOST)
	if (cli->team == team)
	  return (cli);
      cli = cli->next;
    }
  return (NULL);
}
