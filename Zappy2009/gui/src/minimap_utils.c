/*
** minimap_utils.c for minimap_utils in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:42:55 2009 yavuz yurdusev
** Last update Thu Apr 23 20:44:39 2009 yavuz yurdusev
*/

#include "map.h"
#include "minimap.h"
#include "x_func_sdl.h"

void		aff_link(t_on_screen *screen, int width, int height)
{
  SDL_Surface	*link;
  SDL_Rect	p;
  t_cli		*list_link;

  list_link = screen->world->client;
  while (list_link != NULL)
    {
      p.x = W_WIN - width + list_link->pos.pos_player.x *
        (height / screen->world->height);
      p.y = H_WIN - height + list_link->pos.pos_player.y *
        (width / screen->world->width);
      link = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, 5, 32, 0, 0, 0, 0);
      if (link == NULL)
        perror("map.c: SDL_CreateRGBSurface():");
      xsdl_fillrect(link, NULL,
                    SDL_MapRGB(screen->window->format, 255, 36, 0));
      xsdl_blitsurface(link, NULL, screen->window, &p);
      list_link = list_link->next;
      SDL_FreeSurface(link);
    }
}

static void	blit_in_minimap(t_on_screen *screen, SDL_Rect *p, int color)
{
  SDL_Surface	*p_color;

  p_color = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, 5, 32, 0, 0, 0, 0);
  if (p_color == NULL)
    perror("map.c: SDL_CreateRGBSurface():");
  if (color)
    xsdl_fillrect(p_color, NULL, SDL_MapRGB(screen->window->format,
					  76, 254, 123));
  else
    xsdl_fillrect(p_color, NULL, SDL_MapRGB(screen->window->format,
					  0, 0, 255));
  xsdl_blitsurface(p_color, NULL, screen->window, p);
  SDL_FreeSurface(p_color);
}

void		aff_egg(t_on_screen *screen, int width, int height)
{
  SDL_Rect	p;
  int		x;
  int		y;

  y = 0;
  while (y < screen->world->height)
    {
      x = 0;
      while (x < screen->world->width)
        {
	  if (screen->world->map[y][x].objet[OEUF] > 0)
	    {
	      p.x = W_WIN - width + x * (height / screen->world->height);
	      p.y = H_WIN - height + y * (width / screen->world->width);
	      blit_in_minimap(screen, &p, 1);
	    }
	  x++;
	}
      y++;
    }
}

void		aff_ghost(t_on_screen *screen, int width, int height)
{
  SDL_Rect	p;
  int		x;
  int		y;

  y = 0;
  while (y < screen->world->height)
    {
      x = 0;
      while (x < screen->world->width)
        {
	  if (screen->world->map[y][x].nb_ghost > 0)
	    {
	      p.x = W_WIN - width + x * (height / screen->world->height);
	      p.y = H_WIN - height + y * (width / screen->world->width);
	      blit_in_minimap(screen, &p, 0);
	    }
	  x++;
	}
      y++;
    }
}

int	display_mini(t_on_screen *screen, int i __attribute__((unused)))
{
  if (screen->show_minimap == 0)
    screen->show_minimap = 1;
  else
    screen->show_minimap = 0;
  return (1);
}
