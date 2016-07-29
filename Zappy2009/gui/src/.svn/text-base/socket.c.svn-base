/*
** socket.c for socket in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:38:32 2009 yavuz yurdusev
** Last update Sun Apr 26 12:32:16 2009 yavuz yurdusev
*/

#include "map.h"
#include "func_xmemory.h"
#include "socket.h"
#include "buffer.h"

static void	init_select(SDLNet_SocketSet *set, t_on_screen *screen)
{
  *set = SDLNet_AllocSocketSet(1);
  if (!*set)
    {
      fprintf(stdout, "socket.c:init_select(): SDLNet_AllocSocketSet: %s\n",
	      SDLNet_GetError());
      gui_exit(screen, EXIT_FAILURE);
    }
  if (SDLNet_TCP_AddSocket(*set, screen->sock_server) != 1)
    {
      fprintf(stdout, "socket.c: init_select(): SDLNet_TCP_AddSocket: %s\n",
	      SDLNet_GetError());
      gui_exit(screen, EXIT_FAILURE);
    }
}

static void	do_read(t_on_screen *screen)
{
  int		len;
  char		buf[BUF_SIZE];

  len = SDLNet_TCP_Recv(screen->sock_server, buf, BUF_SIZE);
  if (len <= 0)
    {
      fprintf(stdout, "Connection closed by SERVER\n");
      SDLNet_TCP_Close(screen->sock_server);
      gui_exit(screen, EXIT_FAILURE);
    }
  if (len > 0)
    save_cmd(&(screen->my_msg) , buf, len, 'R');
}

void		init_net(char *host,
			 unsigned int port,
			 SDLNet_SocketSet *set,
			 t_on_screen *screen)
{
  IPaddress	address;

  if (SDLNet_Init() == -1)
    {
      fprintf(stdout, "socket.c: init_net(): SDLNet_Init: %s\n",
	      SDLNet_GetError());
      gui_exit(screen, EXIT_FAILURE);
    }
  if (SDLNet_ResolveHost(&address, host, port) == -1)
    {
      fprintf(stdout, "socket.c: init_net(): SDLNet_ResolveHost: %s\n",
	      SDLNet_GetError());
      SDLNet_Quit();
      gui_exit(screen, EXIT_FAILURE);
    }
  screen->sock_server = SDLNet_TCP_Open(&address);
  if (!screen->sock_server)
    {
      fprintf(stdout, "socket.c: init_net(): SDLNet_TCP_Open: %s\n",
	      SDLNet_GetError());
      SDLNet_Quit();
      gui_exit(screen, EXIT_FAILURE);
    }
  init_select(set, screen);
}

void	do_select(t_on_screen *screen,
		  SDLNet_SocketSet *set)
{
  int	ready;

  ready = SDLNet_CheckSockets(*set, 1);
  if (ready < 0)
    {
      fprintf(stdout, "socket.c: do_select(): SDLNet_CheckSockets: %s\n",
	      SDLNet_GetError());
      gui_exit(screen, EXIT_FAILURE);
    }
  if (!ready)
    return ;
  if (SDLNet_SocketReady(screen->sock_server))
    do_read(screen);
}

void	do_write(t_on_screen *screen)
{
  int	len;
  int	sended;
  char	*tosend;

  if ((len = (access_cmdlen(&(screen->my_msg), 'W'))) > 0)
    {
      tosend = access_cmd(&(screen->my_msg), 'W');
      sended = SDLNet_TCP_Send(screen->sock_server, (void *)tosend, len);
      if (sended < len)
	{
	  fprintf(stdout, "Connection closed by server\n");
	  SDLNet_TCP_Close(screen->sock_server);
	  gui_exit(screen, EXIT_FAILURE);
	}
      unsave_cmd(&(screen->my_msg), len, 'W');
    }
}
