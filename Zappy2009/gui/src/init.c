/*
** init.c for init in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:42:32 2009 yavuz yurdusev
** Last update Thu Apr 23 20:42:33 2009 yavuz yurdusev
*/

#include "map.h"
#include "func_xmemory.h"
#include "init.h"
#include "socket.h"

static void	init_invent(t_on_screen *screen)
{
  screen->info_bag->font = NULL;
  screen->info_bag->bag = NULL;
  screen->info_bag->info_invent = NULL;
  screen->info_bag->heros = NULL;
  screen->info_bag->play = NULL;
  screen->info_bag->have_invent = 0;
}

void	init_screen(t_on_screen *screen)
{
  screen->velocity = 3;
  screen->pos->x = 0;
  screen->pos->y = 0;
  screen->show_minimap = 1;
  screen->brdcast.brdcast_img = NULL;
  screen->brdcast.brdcast_txt = NULL;
  screen->brdcast.broadcast = NULL;
  screen->brdcast.brdcast_time = 1;
  screen->window = NULL;
  screen->map = NULL;
  screen->world->map = NULL;
  screen->world->loading = 2;
  screen->world->client = NULL;
  screen->world->ressources = NULL;
  screen->world->mini_width = 0;
  screen->world->mini_height = 0;
  screen->world->wood = NULL;
  screen->world->player = NULL;
  screen->world->portal = NULL;
  screen->world->ghost.player = NULL;
  screen->world->time_expulse = 0;
  init_invent(screen);
}

static void	set_video_mode(t_on_screen *screen)
{
  screen->window = SDL_SetVideoMode
    ((W_WIN), (H_WIN), 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (screen->window == NULL)
    {
      fprintf(stderr, "Init.c: SDL_SetVideoMode(): %s\n", SDL_GetError());
      gui_exit(screen, EXIT_FAILURE);
    }
}

void	init_sdl(t_on_screen *screen)
{
  int	ret_init;

  ret_init = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
  if (ret_init == -1)
    {
      fprintf(stderr, "Init.c: SDL_Init(): %s\n", SDL_GetError());
      gui_exit(screen, EXIT_FAILURE);
    }
  set_video_mode(screen);
  SDL_WM_SetCaption("Zappy-Defcon", NULL);
  init_clip(screen);
}
