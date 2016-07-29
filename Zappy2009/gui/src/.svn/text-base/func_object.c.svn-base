/*
** func_object.c for func_object in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:41:27 2009 yavuz yurdusev
** Last update Thu Apr 23 20:41:28 2009 yavuz yurdusev
*/

#include "x_func_sdl.h"
#include "map.h"
#include "func_xmemory.h"
#include "func_xy_max.h"
#include "move_map.h"
#include "wood.h"
#include "func_init_object.h"

/*
** initialise le contenu de la map a 0
*/
void	init_map_content(t_on_screen *screen)
{
  int	x;
  int	y;
  int	i;

  y = 0;
  while (y < screen->world->height)
    {
      x = 0;
      while (x < screen->world->width)
	{
	  i = 0;
	  while (i < NB_OBJETS)
	    {
	      screen->world->map[y][x].objet[i] = 0;
	      i++;
	    }
	  init_wood_on_map(screen, x, y);
	  screen->world->map[y][x].oeuf_num = NULL;
	  screen->world->map[y][x].ghost_num = NULL;
	  screen->world->map[y][x].nb_ghost = 0;
	  x++;
	}
      y++;
    }
  init_ressources(screen);
}

static void	place_incantation(SDL_Rect *rect, int i)
{
  rect->h = 0;
  rect->w = 0;
  if (i == INCANTATION)
    {
      rect->x -= 5;
      rect->y -= 17;
    }
}

static SDL_Rect	place_element_on_case(int indice_objet)
{
  SDL_Rect	rect;
  int		taille_souscase;

  taille_souscase = SQUARE / 4;
  rect.x = taille_souscase / 2;
  rect.y = taille_souscase / 2;
  if (indice_objet < 3)
    rect.x += (taille_souscase * indice_objet);
  else
    if (indice_objet < 5)
      {
	rect.x += (taille_souscase * 3);
	rect.y += (taille_souscase * ((indice_objet % 3) + 1));
      }
    else
      if (indice_objet < 7)
	{
	  rect.y += (taille_souscase * 3);
	  rect.x += (taille_souscase * (indice_objet % 4));
	}
      else
	rect.y += taille_souscase;
  place_incantation(&rect, indice_objet - 1);
  return (rect);
}

void		print_object_on_case(t_on_screen *screen,
				     t_point *coor,
				     int is_camera)
{
  SDL_Rect	rect_cur;
  int		i;
  int		x_map;
  int		y_map;

  x_map = coor->x - screen->world->x_begin;
  y_map = coor->y - screen->world->y_begin;
  i = 0;
  if (check_in_camera(screen, coor, is_camera))
    while (i < NB_OBJETS)
      {
	if (screen->world->map[coor->y][coor->x].objet[i] > 0)
	  {
	    rect_cur = place_element_on_case(i + 1);
	    rect_cur.x += CENTER_X(screen->coor_max.x) +
	      (x_map * SQUARE);
	    rect_cur.y += CENTER_Y(screen->coor_max.y) +
	      (y_map * SQUARE);
	    xsdl_blitsurface(screen->world->ressources[i], NULL,
			     screen->window, &rect_cur);
	  }
	i++;
      }
}

void	fill_case(t_on_screen *screen, t_point *coor, t_res *caze)
{
  int	i;

  i = 0;
  while (i < NB_OBJETS - 2)
    {
      screen->world->map[coor->y][coor->x].objet[i] = caze->objet[i];
      i++;
    }
}
