/*
** main.c for  in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:42:52 2009 yavuz yurdusev
** Last update Sun Apr 26 12:07:11 2009 yavuz yurdusev
*/

#include <unistd.h>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_thread.h"
#include "map.h"
#include "socket.h"
#include "inventaire.h"
#include "command.h"
#include "buffer.h"
#include "minimap.h"
#include "init.h"
#include "event.h"
#include "x_func_sdl.h"
#include "func_xmemory.h"
#include "signal.h"

t_on_screen	gl_screen;

void	refresh(t_on_screen *screen)
{
  init_map(screen);
  xsdl_flip(screen->window);
}

void	free_all()
{
  free_gui(&gl_screen);
  exit(EXIT_FAILURE);
}

int			main(int argc, char **argv)
{
  SDL_Rect		pos;
  t_world		new_world;
  t_bag			new_bag;
  SDLNet_SocketSet	set;

  if (signal(SIGINT, free_all) == SIG_ERR)
    exit(EXIT_FAILURE);
  if (argc != 3)
    write(2, USAGE, strlen(USAGE));
  else
    {
      init_buf_msg(&(gl_screen.my_msg));
      gl_screen.info_bag = &new_bag;
      gl_screen.pos = &pos;
      gl_screen.world = &new_world;
      init_screen(&gl_screen);
      init_net(argv[1], (unsigned)atoi(argv[2]), &set, &gl_screen);
      init_sdl(&gl_screen);
      events(&gl_screen, &set);
      SDLNet_FreeSocketSet(set);
      SDLNet_TCP_Close(gl_screen.sock_server);
      free_gui(&gl_screen);
    }
  return (EXIT_SUCCESS);
}
