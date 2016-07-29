/*
** serv_seg.c for serv_seg in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:39:23 2009 yavuz yurdusev
** Last update Thu Apr 23 20:39:23 2009 yavuz yurdusev
*/

#include "command.h"
#include "x_func_sdl.h"
#include "func_xmemory.h"

static void	send_team(t_on_screen *screen,
			  char *team,
			  SDL_Rect *pos,
			  SDL_Color *color)
{
  TTF_Font	*police;
  SDL_Surface	*text;

  police = TTF_OpenFont("images/CaslonBold.ttf", 70);
  pos->x = (W_WIN / 2) - (strlen(team) * 22);
  pos->y = 100;
  text = TTF_RenderText_Blended(police, team, *color);
  xsdl_blitsurface(text, NULL, screen->window, pos);
  SDL_FreeSurface(text);
  TTF_CloseFont(police);
}

void		serv_seg(t_on_screen *screen, char *msg)
{
  char		*team;
  SDL_Color	color;
  SDL_Rect	pos;
  SDL_Surface	*victory;

  pos.x = 0;
  pos.y = 0;
  team = get_argument(msg, 2);
  team[n_strlen(team, 1)] = '\0';
  victory = img_load("images/victory.png");
  xsdl_blitsurface(victory, NULL, screen->window, &pos);
  if (TTF_Init() != -1)
    {
      color.r = 250;
      color.g = 250;
      color.b = 0;
      send_team(screen, team, &pos, &color);
      TTF_Quit();
    }
  SDL_FreeSurface(victory);
  xsdl_flip(screen->window);
  SDL_Delay(10000);
}
