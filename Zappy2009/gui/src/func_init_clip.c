/*
** func_init_clip.c for func_init_clip in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:40:27 2009 yavuz yurdusev
** Last update Thu Apr 23 20:40:29 2009 yavuz yurdusev
*/

#include "map.h"
#include "func_init_perso.h"

static SDL_Rect	*init_up(SDL_Rect *clip)
{
  clip[0].x = 0;
  clip[0].y = 0;
  clip[0].w = SHEET_WIDTH / 3;
  clip[0].h = SHEET_HEIGHT / 4;
  clip[1].x = SHEET_WIDTH / 3;
  clip[1].y = 0;
  clip[1].w = SHEET_WIDTH / 3;
  clip[1].h = SHEET_HEIGHT / 4;
  clip[2].x = SHEET_WIDTH / 3 * 2;
  clip[2].y = 0;
  clip[2].w = SHEET_WIDTH / 3;
  clip[2].h = SHEET_HEIGHT / 4;
  return (clip);
}

static SDL_Rect	*init_right(SDL_Rect *clip)
{
  clip[3].x = 0;
  clip[3].y = SHEET_HEIGHT / 4;
  clip[3].w = SHEET_WIDTH / 3;
  clip[3].h = SHEET_HEIGHT / 4;
  clip[4].x = SHEET_WIDTH / 3;
  clip[4].y = SHEET_HEIGHT / 4;
  clip[4].w = SHEET_WIDTH / 3;
  clip[4].h = SHEET_HEIGHT / 4;
  clip[5].x = SHEET_WIDTH / 3 * 2;
  clip[5].y = SHEET_HEIGHT / 4;
  clip[5].w = SHEET_WIDTH / 3;
  clip[5].h = SHEET_HEIGHT / 4;
  return (clip);
}

static SDL_Rect	*init_down(SDL_Rect *clip)
{
  clip[6].x = 0;
  clip[6].y = SHEET_HEIGHT / 4 * 2;
  clip[6].w = SHEET_WIDTH / 3;
  clip[6].h = SHEET_HEIGHT / 4 - 5;
  clip[7].x = SHEET_WIDTH / 3;
  clip[7].y = SHEET_HEIGHT / 4 * 2;
  clip[7].w = SHEET_WIDTH / 3;
  clip[7].h = SHEET_HEIGHT / 4;
  clip[8].x = SHEET_WIDTH / 3 * 2;
  clip[8].y = SHEET_HEIGHT / 4 * 2;
  clip[8].w = SHEET_WIDTH / 3;
  clip[8].h = SHEET_HEIGHT / 4;
  return (clip);
}

static SDL_Rect	*init_left(SDL_Rect *clip)
{
  clip[9].x = 0;
  clip[9].y = SHEET_HEIGHT / 4 * 3;
  clip[9].w = SHEET_WIDTH / 3;
  clip[9].h = SHEET_HEIGHT / 4;
  clip[10].x = SHEET_WIDTH / 3;
  clip[10].y = SHEET_HEIGHT / 4 * 3;
  clip[10].w = SHEET_WIDTH / 3;
  clip[10].h = SHEET_HEIGHT / 4;
  clip[11].x = SHEET_WIDTH / 3 * 2;
  clip[11].y = SHEET_HEIGHT / 4 * 3;
  clip[11].w = SHEET_WIDTH / 3;
  clip[11].h = SHEET_HEIGHT / 4;
  return (clip);
}

void	init_clip(t_on_screen *screen)
{
  init_up(screen->world->clip);
  init_right(screen->world->clip);
  init_down(screen->world->clip);
  init_left(screen->world->clip);
}
