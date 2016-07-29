/*
** move_teleport.c for move_teleport in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:42:31 2009 yavuz yurdusev
** Last update Thu Apr 23 20:42:31 2009 yavuz yurdusev
*/

#include "SDL/SDL.h"

#include "map.h"
#include "move_map.h"
#include "func_xy_max.h"
#include "func_init_perso.h"
#include "x_func_sdl.h"

/*
** Creer un portal de teleportation
** d'une case a l'autre pour un joueur donnees
*/

static void	init_position(SDL_Rect *rect,
			      t_point *pos,
			      t_on_screen *screen,
			      t_cli *one_client)
{
  rect->x = CENTER_X(screen->coor_max.x) +
    (one_client->pos.pos_player.x - screen->world->x_begin) * SQUARE;
  rect->y = CENTER_Y(screen->coor_max.y) +
    (one_client->pos.pos_player.y - screen->world->y_begin) * SQUARE;
  pos->x = one_client->pos.pos_player.x;
  pos->y = one_client->pos.pos_player.y;
}

void		move_teleport(t_on_screen *screen, t_cli *one_client)
{
  SDL_Rect	rect;
  t_point	pos;

  one_client->on_move += 1;
  if (check_in_camera(screen, &(one_client->pos.old_pos), 0))
    {
      rect.x = one_client->pos.mov_player.x - 10;
      rect.y = one_client->pos.mov_player.y;
      xsdl_blitsurface(screen->world->portal, NULL, screen->window, &rect);
      if (one_client->on_move < 4)
	xsdl_blitsurface(one_client->mob.player,
			 (screen->world->clip + one_client->mob.i_clip),
			 screen->window, &one_client->pos.mov_player);
    }
  init_position(&rect, &pos, screen, one_client);
  if (check_in_camera(screen, &pos, 0))
    {
      xsdl_blitsurface(screen->world->portal, NULL, screen->window, &rect);
      if (one_client->on_move > 4)
	xsdl_blitsurface(one_client->mob.player,
			 (screen->world->clip + one_client->mob.i_clip),
			 screen->window, &rect);
    }
  if (one_client->on_move == 8)
    one_client->on_move = 0;
}
