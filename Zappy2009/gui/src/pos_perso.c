/*
** pos_perso.c for pos_perso in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Sun Apr 26 12:05:46 2009 yavuz yurdusev
** Last update Sun Apr 26 22:22:32 2009 yavuz yurdusev
*/

#include "map.h"
#include "move_map.h"
#include "command.h"
#include "event.h"
#include "socket.h"
#include "define.h"
#include "func_xy_max.h"
#include "x_func_sdl.h"
#include "command.h"
#include "buffer.h"
#include "inventaire.h"

void		color_line(t_on_screen *screen,
			   int herosX,
			   int herosY,
			   t_cli *client)
{
  int		i;
  SDL_Surface	*borderline;
  SDL_Rect	pos_l;

  borderline = SDL_CreateRGBSurface(SDL_HWSURFACE, SQUARE, 1, 32, 0, 0, 0, 0);
  if (borderline == NULL)
    {
      perror("pos_perso.c: SDL_CreateRGBSurface():");
      return ;
    }
  pos_l.x = herosX + SQUARE * (client->pos.pos_player.x -
			       screen->world->x_begin);
  pos_l.y = herosY + SQUARE * (client->pos.pos_player.y -
			       screen->world->y_begin);
  i = 0;
  while (i <= 1)
    {
      pos_l.x = pos_l.x;
      pos_l.y = pos_l.y + i * SQUARE;
      xsdl_fillrect(borderline, NULL,
		    SDL_MapRGB(screen->window->format, 255, 0, 0));
      xsdl_blitsurface(borderline, NULL, screen->window, &pos_l);
      i++;
    }
  SDL_FreeSurface(borderline);
}

void		color_column(t_on_screen *screen,
			     int herosX,
			     int herosY,
			     t_cli *client)
{
  int		i;
  SDL_Surface	*bordercol;
  SDL_Rect	pos_c;

  bordercol = SDL_CreateRGBSurface(SDL_HWSURFACE, 1, SQUARE, 32, 0, 0, 0, 0);
  if (bordercol == NULL)
    {
      perror("pos_perso.c: SDL_CreateRGBSurface()");
      return ;
    }
  pos_c.x = herosX + SQUARE * (client->pos.pos_player.x -
			       screen->world->x_begin);
  pos_c.y = herosY + SQUARE * (client->pos.pos_player.y -
			       screen->world->y_begin);
  i = 0;
  while (i <= 1)
    {
      pos_c.x = pos_c.x + i * SQUARE;
      pos_c.y = pos_c.y;
      xsdl_fillrect(bordercol, NULL,
		    SDL_MapRGB(screen->window->format, 255, 0, 0));
      xsdl_blitsurface(bordercol, NULL, screen->window, &pos_c);
      i++;
    }
  SDL_FreeSurface(bordercol);
}

static void	call_invent(t_on_screen *screen)
{
  char		temp[15];
  char		bol[15];
  int		num_cli;

  num_cli = screen->info_bag->heros->num;
  atio(num_cli, temp);
  bol[0] = '\0';
  strcat(bol, "pin ");
  strcat(bol, temp);
  strcat(bol, "\n");
  save_cmd(&(screen->my_msg), bol, strlen(bol), 'W');
  do_write(screen);
}

int		click_perso(t_on_screen *screen, t_cli *client, SDL_Event *event)
{
  int		herosX;
  int		herosY;

  herosX = CENTER_X(get_x_max(screen));
  herosY = CENTER_Y(get_y_max(screen));
  if (event->button.x <= (herosX + SQUARE * (client->pos.pos_player.x -
					     screen->world->x_begin) + SQUARE) &&
      event->button.x >= (herosX + SQUARE * (client->pos.pos_player.x -
					     screen->world->x_begin)) &&
      event->button.y <= (herosY + SQUARE * (client->pos.pos_player.y -
					     screen->world->y_begin) + SQUARE) &&
      event->button.y >= (herosY + SQUARE * (client->pos.pos_player.y -
					     screen->world->y_begin)))
    {
      screen->info_bag->heros = client;
      call_invent(screen);
      color_line(screen, herosX, herosY, screen->info_bag->heros);
      color_column(screen, herosX, herosY, screen->info_bag->heros);
      left_click(screen);
      return (1);
    }
  return (0);
}
