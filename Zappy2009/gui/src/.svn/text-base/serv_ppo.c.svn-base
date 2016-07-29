/*
** serv_ppo.c for serv_ppo in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:39:35 2009 yavuz yurdusev
** Last update Thu Apr 23 20:39:35 2009 yavuz yurdusev
*/

#include "command.h"
#include "inventaire.h"
#include "func_init_perso.h"

static t_cli	*get_player(t_cli *listcli, int num)
{
  t_cli		*client;

  client = listcli;
  while (client != NULL)
    {
      if (client->num == num)
	return (client);
      client = client->next;
    }
  return (NULL);
}

static void	check_move(t_on_screen *screen, t_cli *client)
{
  if (client->on_move)
    {
      client->pos.mov_player.x = CENTER_X(screen->coor_max.x) +
	(client->pos.pos_player.x - screen->world->x_begin)
	* SQUARE + 10;
      client->pos.mov_player.y = CENTER_Y(screen->coor_max.y) +
	((client->pos.pos_player.y - screen->world->y_begin) * SQUARE);
      if (screen->velocity < 20)
	screen->velocity += 2;
    }
}

static void	what_move(t_on_screen *screen, t_cli *client, t_point *old)
{
  if (((old->x - client->pos.pos_player.x) < -1 ||
       (old->x - client->pos.pos_player.x) > 1) ||
      ((old->y - client->pos.pos_player.y) < -1 ||
       (old->y - client->pos.pos_player.y) > 1))
    {
      client->pos.old_pos.x = old->x;
      client->pos.old_pos.y = old->y;
      client->on_move = 2;
      move_teleport(screen, client);
    }
  else
    {
      client->on_move = 1;
      move_manager(screen, client);
    }
}

void		serv_ppo(t_on_screen *screen, char *msg)
{
  t_cli		*client;
  t_point	old;

  client = get_player(screen->world->client, atoi(get_argument(msg, 2)));
  if (client == NULL)
    return ;
  old.x = client->pos.pos_player.x;
  old.y = client->pos.pos_player.y;
  client->pos.pos_player.x = atoi(get_argument(msg, 3));
  client->pos.pos_player.y = atoi(get_argument(msg, 4));
  client->pos.direction = atoi(get_argument(msg, 5));
  if (old.x != client->pos.pos_player.x || old.y != client->pos.pos_player.y)
    {
      check_move(screen, client);
      what_move(screen, client, &old);
    }
  else
    init_face(client);
  screen->world->loading = 0;
}
