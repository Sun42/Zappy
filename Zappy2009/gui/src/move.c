/*
** move.c for move in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:42:48 2009 yavuz yurdusev
** Last update Thu Apr 23 20:42:49 2009 yavuz yurdusev
*/

#include "SDL/SDL.h"

#include "map.h"
#include "func_xy_max.h"
#include "func_init_perso.h"
#include "x_func_sdl.h"

static void	move_up(t_on_screen *screen, t_cli *one_client)
{
  one_client->pos.mov_player.y += (screen->velocity * -1);
  xsdl_blitsurface(one_client->mob.player,
		   (screen->world->clip + one_client->mob.i_clip),
		   screen->window, &one_client->pos.mov_player);
  if (one_client->pos.mov_player.y <= (CENTER_Y(screen->coor_max.y)
      + ((one_client->pos.pos_player.y - screen->world->y_begin)
	 * SQUARE)))
    {
      one_client->on_move = 0;
      init_face(one_client);
    }
  else
    if (one_client->mob.i_clip == 2)
      one_client->mob.i_clip = 0;
    else
      one_client->mob.i_clip += 1;
}

static void	move_down(t_on_screen *screen, t_cli *one_client)
{
  one_client->pos.mov_player.y += screen->velocity;
  xsdl_blitsurface(one_client->mob.player,
		   (screen->world->clip + one_client->mob.i_clip),
		   screen->window, &one_client->pos.mov_player);
  if (one_client->pos.mov_player.y >= (CENTER_Y(screen->coor_max.y)
      + ((one_client->pos.pos_player.y - screen->world->y_begin)
	 * SQUARE)))
    {
      one_client->on_move = 0;
      init_face(one_client);
    }
  else
    if (one_client->mob.i_clip == 8)
      one_client->mob.i_clip = 6;
    else
      one_client->mob.i_clip += 1;
}

static void	move_left(t_on_screen *screen, t_cli *one_client)
{
  one_client->pos.mov_player.x += (screen->velocity * -1);
  xsdl_blitsurface(one_client->mob.player,
		   (screen->world->clip + one_client->mob.i_clip),
		   screen->window, &one_client->pos.mov_player);
  if (one_client->pos.mov_player.x <= (CENTER_X(screen->coor_max.x)
      + ((one_client->pos.pos_player.x - screen->world->x_begin)
	 * SQUARE) + 15))
    {
      one_client->on_move = 0;
      init_face(one_client);
    }
  else
    if (one_client->mob.i_clip == 11)
      one_client->mob.i_clip = 9;
    else
      one_client->mob.i_clip += 1;
}

static void	move_right(t_on_screen *screen, t_cli *one_client)
{
  one_client->pos.mov_player.x += screen->velocity;
  xsdl_blitsurface(one_client->mob.player,
		   (screen->world->clip + one_client->mob.i_clip),
		   screen->window, &one_client->pos.mov_player);
  if (one_client->pos.mov_player.x >= (CENTER_X(screen->coor_max.x)
      + ((one_client->pos.pos_player.x - screen->world->x_begin)
	 * SQUARE) + 10))
    {
      one_client->on_move = 0;
      init_face(one_client);
    }
  else
    if (one_client->mob.i_clip == 5)
      one_client->mob.i_clip = 3;
    else
      one_client->mob.i_clip += 1;
}

static const t_way_to_move	gl_move_func[] =
  {
    {MOVE_UP, move_up},
    {MOVE_RIGHT, move_right},
    {MOVE_DOWN, move_down},
    {MOVE_LEFT, move_left},
    {0, NULL}
  };

int	move_manager(t_on_screen *screen, t_cli *one_client)
{
  int	i;

  i = 0;
  while (gl_move_func[i].way != 0)
    {
      if (gl_move_func[i].way == one_client->pos.direction)
	{
	  gl_move_func[i].f(screen, one_client);
	  return (1);
	}
      i++;
    }
  return (0);
}
