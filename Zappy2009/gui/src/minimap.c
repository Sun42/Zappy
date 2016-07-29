/*
** minimap.c for minimap in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:43:36 2009 yavuz yurdusev
** Last update Thu Apr 23 20:43:37 2009 yavuz yurdusev
*/

#include "map.h"
#include "minimap.h"
#include "x_func_sdl.h"

static void	mini_line(t_on_screen *screen, int width, int height)
{
  SDL_Surface	*mini_line;
  SDL_Rect	pos;
  int		i;

  mini_line = SDL_CreateRGBSurface(SDL_HWSURFACE, width, 1, 32, 0, 0, 0, 0);
  if (mini_line == NULL)
    perror("map.c: SDL_CreateRGBSurface():");
  i = 0;
  while (i <= screen->world->height)
    {
      pos.x = W_WIN - width;
      pos.y = H_WIN - height + (i * (height / screen->world->height));
      xsdl_fillrect(mini_line, NULL, SDL_MapRGB(screen->window->format,
						0, 0, 0));
      xsdl_blitsurface(mini_line, NULL, screen->window, &pos);
      i++;
    }
  SDL_FreeSurface(mini_line);
}

static void	mini_column(t_on_screen *screen, int width, int height)
{
  SDL_Surface	*mini_colo;
  SDL_Rect	pos;
  int		i;

  mini_colo = SDL_CreateRGBSurface(SDL_HWSURFACE, 1, height, 32, 0, 0, 0, 0);
  if (mini_colo == NULL)
    perror("map.c: SDL_CreateRGBSurface():");
  i = 0;
  while (i <= screen->world->width)
    {
      pos.x = W_WIN - width + (i * (width / screen->world->width));
      pos.y = H_WIN - height;
      xsdl_fillrect(mini_colo, NULL, SDL_MapRGB(screen->window->format,
						0, 0, 0));
      xsdl_blitsurface(mini_colo, NULL, screen->window, &pos);
      i++;
    }
  SDL_FreeSurface(mini_colo);
}

void		camera(t_on_screen *screen, int width, int height)
{
  SDL_Surface	*minicam;
  unsigned int	camw;
  unsigned int	camh;
  SDL_Rect	p;

  p.x = W_WIN - width + screen->world->x_begin *
    (height / screen->world->height);
  p.y = H_WIN - height + screen->world->y_begin *
    (width / screen->world->width);
  camw = (W_WIN / SQUARE) * (height / screen->world->height);
  camh = (H_WIN / SQUARE) * (width / screen->world->width);
  minicam = SDL_CreateRGBSurface(SDL_HWSURFACE, camw, camh, 32, 0, 0, 0, 0);
  if (minicam == NULL)
    perror("map.c: SDL_CreateRGBSurface():");
  xsdl_fillrect(minicam, NULL,
		SDL_MapRGB(screen->window->format, 211, 190, 159));
  xsdl_blitsurface(minicam, NULL, screen->window, &p);
  SDL_FreeSurface(minicam);
}

static void	calc_size_minimap(t_on_screen *screen)
{
  float		temp;

  if (screen->world->width >= screen->world->height)
    {
      screen->world->mini_width = 200;
      temp = ((float)screen->world->height /
	      (float)screen->world->width) * 200;
      screen->world->mini_height = (int)temp;
    }
  else
    {
      screen->world->mini_height = 200;
      temp = ((float)screen->world->width /
	      (float)screen->world->height) * 200;
      screen->world->mini_width = (int)temp;
    }
}

void		init_minimap(t_on_screen *screen)
{
  SDL_Surface	*minimap;
  SDL_Rect	position;

  calc_size_minimap(screen);
  position.x = W_WIN - screen->world->mini_width;
  position.y = H_WIN - screen->world->mini_height;
  minimap = SDL_CreateRGBSurface(SDL_HWSURFACE,
				 screen->world->mini_width,
				 screen->world->mini_height,
				 32, 0, 0, 0, 0);
  SDL_FillRect(minimap, NULL, SDL_MapRGB(minimap->format, 159, 138, 117));
  xsdl_blitsurface(minimap, NULL, screen->window, &position);
  camera(screen, screen->world->mini_width, screen->world->mini_height);
  aff_egg(screen, screen->world->mini_width, screen->world->mini_height);
  aff_ghost(screen, screen->world->mini_width, screen->world->mini_height);
  aff_link(screen, screen->world->mini_width, screen->world->mini_height);
  mini_line(screen, screen->world->mini_width, screen->world->mini_height);
  mini_column(screen, screen->world->mini_width, screen->world->mini_height);
  SDL_FreeSurface(minimap);
}
