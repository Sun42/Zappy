/*
** serv_pnw.c for serv_pnw in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:39:42 2009 yavuz yurdusev
** Last update Sun Apr 26 12:22:31 2009 yavuz yurdusev
*/

# define _GNU_SOURCE 1
#include <stdlib.h>
#include <string.h>

#include "map.h"
#include "command.h"
#include "func_xmemory.h"
#include "func_init_perso.h"

static t_cli	*create_client(t_on_screen *screen)
{
  t_cli		*new_client;

  if ((new_client = xmalloc(sizeof(*new_client))) == NULL)
    return (NULL);
  new_client->next = screen->world->client;
  screen->world->client = new_client;
  return (new_client);
}

void	init_invent_client(t_cli *my_cli)
{
  int	i;

  i = 0;
  while (i < NB_OBJETS)
    {
      my_cli->invent.objet[i] = 0;
      i++;
    }
}

void	serv_pnw(t_on_screen *screen, char *msg)
{
  t_cli	*my_cli;

  if ((my_cli = create_client(screen)) == NULL)
    return ;
  my_cli->num = atoi(get_argument(msg, 2));
  my_cli->pos.pos_player.x = atoi(get_argument(msg, 3));
  my_cli->pos.pos_player.y = atoi(get_argument(msg, 4));
  my_cli->pos.mov_player.x = CENTER_X(screen->coor_max.x) +
    (my_cli->pos.pos_player.x - screen->world->x_begin)
    * SQUARE + 10;
  my_cli->pos.mov_player.y = CENTER_Y(screen->coor_max.y) +
    ((my_cli->pos.pos_player.y - screen->world->y_begin)
     * SQUARE);
  my_cli->pos.direction = atoi(get_argument(msg, 5));
  my_cli->lvl = atoi(get_argument(msg, 6));
  my_cli->team = my_strndup(get_argument(msg, 7),
			    strlen_cmd(get_argument(msg, 7)) + 1);
  my_cli->on_move = 0;
  init_perso(screen, my_cli);
  init_face(my_cli);
  init_invent_client(my_cli);
  screen->world->loading = 0;
}
