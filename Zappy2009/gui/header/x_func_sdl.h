/*
** x_func_sdl.h for x_func_sdl in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/header
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:31:19 2009 yavuz yurdusev
** Last update Thu Apr 23 20:31:20 2009 yavuz yurdusev
*/

#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_net.h"
#include "SDL/SDL_ttf.h"

#ifndef X_FUNC_SDL_H_
# define X_FUNC_SDL_H_

void		xsdl_blitsurface(SDL_Surface *, SDL_Rect *,
				 SDL_Surface *, SDL_Rect *);
void		xsdl_fillrect(SDL_Surface *, SDL_Rect *, Uint32);
void		xsdl_flip(SDL_Surface *);
SDL_Surface	*img_load(char *);

#endif /*! X_FUNC_SDL_H_ !*/
