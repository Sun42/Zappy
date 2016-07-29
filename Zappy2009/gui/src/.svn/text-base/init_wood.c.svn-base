/*
** init_wood.c for init_wood in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:42:44 2009 yavuz yurdusev
** Last update Thu Apr 23 22:06:34 2009 yavuz yurdusev
*/

#include "x_func_sdl.h"
#include "map.h"
#include "func_xy_max.h"
#include "move_map.h"
#include "struct.h"
#include "wood.h"
#include "func_object.h"
#include "func_xmemory.h"

static const t_init	gl_init[] =
  {
    {1, "images/arbre1.png"},
    {2, "images/arbre2.png"},
    {3, "images/buisson.png"},
    {4, "images/sapin.png"},
    {5, "images/souche.png"},
    {0, NULL}
  };

void	init_wood_img(t_on_screen *screen)
{
  int	i;

  screen->world->wood = xmalloc(sizeof(SDL_Surface *) * 6);
  if (screen->world->wood == NULL)
    gui_exit(screen, EXIT_FAILURE);
  i = 0;
  while (gl_init[i].id != 0)
    {
      screen->world->wood[i] = img_load(gl_init[i].imagefile);
      i++;
    }
}

static int	my_random(int limit)
{
  return ((int)((limit + 1.0) * rand() / (RAND_MAX + 1.0) - 1));
}

void	init_wood_on_map(t_on_screen *screen, int x, int y)
{
  int	i;

  i = my_random(NB_WOOD);
  screen->world->map[y][x].id_wood = i;
}

void		print_wood_on_map(t_on_screen *screen,
				  t_point *coor,
				  int is_camera)
{
  SDL_Rect	rect;
  int		num_wood;

  if (check_in_camera(screen, coor, is_camera))
    {
      rect.y = CENTER_Y(screen->coor_max.y) +
	((coor->y - screen->world->y_begin)
	 * SQUARE);
      rect.x = CENTER_X(screen->coor_max.x) +
	(coor->x - screen->world->x_begin)
	* SQUARE + 10;
      num_wood = screen->world->map[coor->y][coor->x].id_wood;
      if (num_wood > 0 && num_wood < 6)
	{
	  xsdl_blitsurface(screen->world->wood[num_wood - 1],
			   NULL, screen->window, &rect);
	}
    }
}
