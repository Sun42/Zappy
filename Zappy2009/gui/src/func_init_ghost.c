/*
** func_init_ghost.c for func_init_ghost in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:40:39 2009 yavuz yurdusev
** Last update Thu Apr 23 21:54:00 2009 yavuz yurdusev
*/

#include "map.h"
#include "x_func_sdl.h"
#include "move_map.h"

void	init_ghost(t_on_screen *screen)
{
  screen->world->ghost.player = img_load("images/link_ghost.png");
  screen->world->ghost.i_clip = 7;
}

static void	del_ghost(t_on_screen *screen, t_point *pos, int i)
{
  int		nb_ghost;

  nb_ghost = screen->world->map[pos->y][pos->x].nb_ghost;
  if (nb_ghost > 1)
    {
      nb_ghost -= 1;
      screen->world->map[pos->y][pos->x].ghost_num[i] =
	screen->world->map[pos->y][pos->x].ghost_num[nb_ghost];
    }
  else
    {
      free(screen->world->map[pos->y][pos->x].ghost_num);
      screen->world->map[pos->y][pos->x].ghost_num = NULL;
    }
}

t_point		ghost_killer(t_on_screen *screen, int ghost_num)
{
  int		i;
  t_point	pos;

  pos.x = 0;
  pos.y = 0;
  while (pos.y < screen->world->height)
    {
      pos.x = 0;
      while (pos.x < screen->world->width)
	{
	  i = 0;
	  while (i < screen->world->map[pos.y][pos.x].nb_ghost)
	    {
	      if (screen->world->map[pos.y][pos.x].ghost_num[i] == ghost_num)
		{
		  del_ghost(screen, &pos, i);
		  return (pos);
		}
	      i++;
	    }
	  pos.x += 1;
	}
      pos.y += 1;
    }
  return (pos);
}

void		print_ghost_on_case(t_on_screen *screen,
				    t_point *coor,
				    int is_camera)
{
  SDL_Rect	rect_cur;
  int		i;

  i = 0;
  if (check_in_camera(screen, coor, is_camera))
    if (screen->world->map[coor->y][coor->x].nb_ghost > 0)
      {
	rect_cur.x = CENTER_X(screen->coor_max.x) +
	  (coor->x - screen->world->x_begin) * SQUARE + 10;
	rect_cur.y = CENTER_Y(screen->coor_max.y) +
	  (coor->y - screen->world->y_begin) * SQUARE;
	xsdl_blitsurface(screen->world->ghost.player,
			 (screen->world->clip +
			  (unsigned)screen->world->ghost.i_clip),
			 screen->window, &rect_cur);
      }
}
