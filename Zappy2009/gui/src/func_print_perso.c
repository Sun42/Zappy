/*
** func_print_perso.c for func_print_perso in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:41:47 2009 yavuz yurdusev
** Last update Thu Apr 23 20:41:49 2009 yavuz yurdusev
*/

#include "map.h"
#include "func_xy_max.h"
#include "move_map.h"
#include "x_func_sdl.h"

static void	calc_player_position(t_on_screen *screen,
				     t_cli *list_client)
{
  int		x;
  int		y;

  x = list_client->pos.pos_player.x;
  y = list_client->pos.pos_player.y;
  list_client->pos.mov_player.x = CENTER_X(screen->coor_max.x) +
    (list_client->pos.pos_player.x - screen->world->x_begin)
    * SQUARE + 10;
  list_client->pos.mov_player.y = CENTER_Y(screen->coor_max.y) +
    ((list_client->pos.pos_player.y - screen->world->y_begin)
     * SQUARE);
  if (screen->world->map[y][x].objet[INCANTATION] <= 0)
    xsdl_blitsurface(list_client->mob.player,
		     (screen->world->clip +
		      list_client->mob.i_clip),
		     screen->window, &list_client->pos.mov_player);
}

void		print_perso_on_case(t_on_screen *screen,
				    t_point *coor,
				    int is_camera)
{
  t_cli		*list_client;

  list_client = screen->world->client;
  if (check_in_camera(screen, coor, is_camera))
    while (list_client != NULL)
      {
	if (coor->x == list_client->pos.pos_player.x &&
	    coor->y == list_client->pos.pos_player.y)
	  if (list_client->on_move == 0)
	    calc_player_position(screen, list_client);
	list_client = list_client->next;
      }
}

void		move_perso_from_case(t_on_screen *screen)
{
  t_cli		*list_client;
  t_point	coor;

  list_client = screen->world->client;
  screen->world->loading = 1;
  while (list_client != NULL)
    {
      if (list_client->on_move != 0)
	{
	  screen->world->loading = 0;
	  coor.x = list_client->pos.pos_player.x;
	  coor.y = list_client->pos.pos_player.y;
	  if (check_in_camera(screen, &coor, 0))
	    if (list_client->on_move == 1)
	      move_manager(screen, list_client);
	  if (list_client->on_move > 1)
	    move_teleport(screen, list_client);
	}
      list_client = list_client->next;
    }
}
