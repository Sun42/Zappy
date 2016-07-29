/*
** map.c for map in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:43:09 2009 yavuz yurdusev
** Last update Thu Apr 23 20:43:10 2009 yavuz yurdusev
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SDL/SDL.h"
#include "map.h"
#include "broadcast.h"
#include "minimap.h"
#include "func_object.h"
#include "inventaire.h"
#include "func_print_perso.h"
#include "func_xmemory.h"
#include "func_xy_max.h"
#include "x_func_sdl.h"
#include "wood.h"
#include "func_init_ghost.h"

void		init_map_value(t_on_screen *screen)
{
  int		y;
  SDL_Surface	*loading;
  SDL_Rect	pos;

  pos.x = 0;
  pos.y = 0;
  screen->world->x_begin = 0;
  screen->world->y_begin = 0;
  screen->world->map = xmalloc(sizeof(t_res *) * (screen->world->height));
  if (screen->world->map == NULL)
    gui_exit(screen, EXIT_FAILURE);
  y = 0;
  while (y < screen->world->height)
    {
      screen->world->map[y] =
	xmalloc(sizeof(t_res) * (screen->world->width));
      if (screen->world->map[y] == NULL)
	gui_exit(screen, EXIT_FAILURE);
      y++;
    }
  init_map_content(screen);
  loading = img_load("images/loading.png");
  xsdl_blitsurface(loading, NULL, screen->window, &pos);
  SDL_FreeSurface(loading);
  xsdl_flip(screen->window);
}

static void	line(t_on_screen *screen)
{
  SDL_Surface	*line;
  SDL_Rect	pos;
  int		i;

  line = SDL_CreateRGBSurface(SDL_HWSURFACE,
			      (screen->coor_max.x * SQUARE),
			      1, 32, 0, 0, 0, 0);
  if (line == NULL)
    perror("map.c: SDL_CreateRGBSurface():");
  i = 0;
  while (i <= screen->coor_max.y)
    {
      pos.x = CENTER_X(screen->coor_max.x);
      pos.y = CENTER_Y(screen->coor_max.y) + i * SQUARE;
      xsdl_fillrect(line, NULL, SDL_MapRGB(screen->window->format,
					   153, 153, 153));
      xsdl_blitsurface(line, NULL, screen->window, &pos);
      i++;
    }
  SDL_FreeSurface(line);
}

static void	column(t_on_screen *screen)
{
  SDL_Surface	*colo;
  SDL_Rect	pos;
  int		i;

  colo = SDL_CreateRGBSurface(SDL_HWSURFACE, 1,
			      (screen->coor_max.y * SQUARE),
			      32, 0, 0, 0, 0);
  if (colo == NULL)
    perror("map.c: SDL_CreateRGBSurface()");
  i = 0;
  while (i <= screen->coor_max.x)
    {
      pos.x = CENTER_X(screen->coor_max.x) + i * SQUARE;
      pos.y = CENTER_Y(screen->coor_max.y);
      xsdl_fillrect(colo, NULL, SDL_MapRGB(screen->window->format,
					   153, 153, 153));
      xsdl_blitsurface(colo, NULL, screen->window, &pos);
      i++;
    }
  SDL_FreeSurface(colo);
}

void		print_map(t_on_screen *screen)
{
  t_point	coor;

  coor.x = screen->world->x_begin;
  while (coor.x < (screen->coor_max.x + screen->world->x_begin))
    {
      coor.y= screen->world->y_begin;
      while (coor.y < (screen->coor_max.y + screen->world->y_begin))
	{
	  print_object_on_case(screen, &coor, 0);
	  print_ghost_on_case(screen, &coor, 0);
	  if (screen->world->client != NULL)
	    print_perso_on_case(screen, &coor, 0);
	  print_wood_on_map(screen, &coor, 0);
	  coor.y++;
	}
      coor.x++;
    }
  if (screen->world->client != NULL)
    blit_invent(screen);
  display_broadcast(screen);
  if (screen->show_minimap == 1)
    init_minimap(screen);
}

void		init_map(t_on_screen *screen)
{
  SDL_Rect	pos;

  screen->map = img_load("images/Desert.jpg");
  pos.x = 0;
  pos.y = 0;
  xsdl_blitsurface(screen->map, NULL, screen->window, &pos);
  SDL_FreeSurface(screen->map);
  line(screen);
  column(screen);
  print_map(screen);
  move_perso_from_case(screen);
  expulse(screen);
}
