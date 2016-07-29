/*
** broadcast.c for broadcast in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:34:17 2009 yavuz yurdusev
** Last update Thu Apr 23 20:34:18 2009 yavuz yurdusev
*/

# define _GNU_SOURCE 1
#include <string.h>
#include <unistd.h>

#include "map.h"
#include "x_func_sdl.h"
#include "broadcast.h"

void		expulse(t_on_screen *screen)
{
  SDL_Surface	*expulse;

  if (screen->world->time_expulse != 0)
    {
      expulse = img_load("images/expulse.png");
      if (expulse != NULL)
	{
	  xsdl_blitsurface(expulse, NULL, screen->window,
			   &screen->world->pos_expulse);
	  SDL_FreeSurface(expulse);
	}
      screen->world->time_expulse -= 1;
    }
}

static int	brdcast_len(t_on_screen *screen,
			    int i,
			    int endlen)
{
  endlen = strlen(screen->brdcast.broadcast + (unsigned int)(i * 90));
  if (!i)
    endlen += 7;
  if (endlen > 89)
    endlen = 90;
  return (endlen);
}

static void	send_text(t_on_screen *screen,
			  SDL_Rect *pos,
			  SDL_Color *color,
			  int i)
{
  int		text_size;
  TTF_Font	*police;
  char		my_text[100];
  int		endlen;
  SDL_Surface	*text;

  bzero(my_text, 100);
  police = TTF_OpenFont("images/CaslonBold.ttf", 12);
  text_size = strlen(screen->brdcast.broadcast) / 90;
  strcat(my_text, "Player ");
  strncat(my_text, screen->brdcast.broadcast, 90);
  while (i <= text_size)
    {
      if (i)
	strncpy(my_text, screen->brdcast.broadcast + (unsigned int)(i * 90), 90);
      endlen = brdcast_len(screen, i, endlen);
      my_text[endlen] = '\0';
      text = TTF_RenderText_Blended(police, my_text, *color);
      xsdl_blitsurface(text, NULL, screen->window, pos);
      SDL_FreeSurface(text);
      pos->y += 12;
      i++;
    }
  TTF_CloseFont(police);
}

void		display_broadcast(t_on_screen *screen)
{
  SDL_Rect	pos;
  SDL_Color	color;

  if (screen->brdcast.brdcast_time == 0)
    screen->brdcast.brdcast_time = 10;
  if (screen->brdcast.brdcast_time > 1)
    {
      color.r = 0;
      color.g = 0;
      color.b = 0;
      screen->brdcast.brdcast_img = img_load("images/broadcast.png");
      pos.x = 200;
      pos.y = H_WIN - 100;
      xsdl_blitsurface(screen->brdcast.brdcast_img, NULL,
		       screen->window, &pos);
      pos.x += 15;
      pos.y += 15;
      if (TTF_Init() != -1)
	{
	  send_text(screen, &pos, &color, 0);
	  TTF_Quit();
	}
      SDL_FreeSurface(screen->brdcast.brdcast_img);
      screen->brdcast.brdcast_time -= 1;
    }
}
