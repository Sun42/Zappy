/*
** x_func_sdl.c for x_func_sdl in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:38:23 2009 yavuz yurdusev
** Last update Thu Apr 23 20:38:23 2009 yavuz yurdusev
*/

#include <stdio.h>

#include "SDL/SDL_image.h"
#include "SDL/SDL.h"

void	xsdl_blitsurface(SDL_Surface *object, SDL_Rect *srcrect,
			 SDL_Surface *screen, SDL_Rect *position)
{
  if (SDL_BlitSurface(object, srcrect, screen, position) == -1)
    perror("x_func_sdl: SDL_BlitSurface()");
}

void	xsdl_fillrect(SDL_Surface *dst,
		      SDL_Rect *dstrect, Uint32 color)
{
  if (SDL_FillRect(dst, dstrect, color) == -1)
    perror("x_func_sdl: SDL_FillRect()");
}

void	xsdl_flip(SDL_Surface *screen)
{
  if (SDL_Flip(screen) == -1)
    perror("x_func_sdl: SDL_Flip()");
}

SDL_Surface	*img_load(char *filepath)
{
  SDL_Surface	*temp;

  temp = IMG_Load(filepath);
  if (temp == NULL)
    {
      perror("x_func_sdl.c: img_load(): ERROR");
      exit(EXIT_FAILURE);
    }
  return (temp);
}
