/*
** func_world.c for func_world in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:30:12 2009 yavuz yurdusev
** Last update Thu Apr 23 21:25:46 2009 yavuz yurdusev
*/

#include <stdlib.h>

#include "server.h"
#include "parse_options.h"

void	init_map(t_world *world)
{
  int	x;
  int	y;

  if ((world->map = xmalloc(sizeof(t_res *) * world->height)) == NULL)
    exit(EXIT_FAILURE);
  y = 0;
  while (y < world->height)
    {
      if ((world->map[y] = xmalloc(sizeof(t_res) * world->width)) == NULL)
	exit(EXIT_FAILURE);
      y++;
    }
  y = 0;
  while (y < world->height)
    {
      x = 0;
      while (x < world->width)
	{
	  init_inventaire(&(world->map[y][x]));
	  world->map[y][x].pcli = NULL;
	  x++;
	}
      y++;
    }
}

static void	init_tab_first(t_res *elevation,
			       int nb_joueur,
			       int linemate,
			       int deraumere)
{
  elevation->nb_joueur = nb_joueur;
  elevation->objet[LINEMATE] = linemate;
  elevation->objet[DERAUMERE] = deraumere;
}

static void	init_tab_second(t_res *elevation,
				int sibur,
				int mendiane,
				int phiras)
{
  elevation->objet[SIBUR] = sibur;
  elevation->objet[MENDIANE] = mendiane;
  elevation->objet[PHIRAS] = phiras;
}

static void	init_tab_elevation(t_world *world)
{
  init_tab_first(&(world->tab_elevation[0]), 1, 1, 0);
  init_tab_second(&(world->tab_elevation[0]), 0, 0, 0);
  world->tab_elevation[0].objet[THYSTAME] = 0;
  init_tab_first(&(world->tab_elevation[1]), 2, 1, 1);
  init_tab_second(&(world->tab_elevation[1]), 1, 0, 0);
  world->tab_elevation[1].objet[THYSTAME] = 0;
  init_tab_first(&(world->tab_elevation[2]), 2, 2, 0);
  init_tab_second(&(world->tab_elevation[2]), 1, 0, 2);
  world->tab_elevation[2].objet[THYSTAME] = 0;
  init_tab_first(&(world->tab_elevation[3]), 4, 1, 1);
  init_tab_second(&(world->tab_elevation[3]), 2, 0, 1);
  world->tab_elevation[3].objet[THYSTAME] = 0;
  init_tab_first(&(world->tab_elevation[4]), 4, 1, 2);
  init_tab_second(&(world->tab_elevation[4]), 1, 3, 0);
  world->tab_elevation[4].objet[THYSTAME] = 0;
  init_tab_first(&(world->tab_elevation[5]), 6, 1, 2);
  init_tab_second(&(world->tab_elevation[5]), 3, 0, 1);
  world->tab_elevation[5].objet[THYSTAME] = 0;
  init_tab_first(&(world->tab_elevation[6]), 6, 2, 2);
  init_tab_second(&(world->tab_elevation[6]), 2, 2, 2);
  world->tab_elevation[6].objet[THYSTAME] = 1;
}

void	create_world(t_world *world)
{
  int	i;

  world->port = DEFAULT_PORT;
  world->speed = DEFAULT_SPEED;
  world->max_client = DEFAULT_MC;
  world->height = DEFAULT_Y;
  world->width = DEFAULT_X;
  world->client = NULL;
  world->team = NULL;
  world->victory_team = NULL;
  world->pgui = NULL;
  i = -1;
  while (++i < 7)
    init_inventaire(&(world->tab_elevation[i]));
  init_tab_elevation(world);
}

