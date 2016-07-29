/*
** socket.h for socket in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/header
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:29:55 2009 yavuz yurdusev
** Last update Thu Apr 23 20:29:56 2009 yavuz yurdusev
*/

#include <SDL/SDL.h>
#include <SDL/SDL_net.h>

#ifndef SOCKET_H_
# define SOCKET_H_

void	init_net(char *host,
		 unsigned port,
		 SDLNet_SocketSet *set,
		 t_on_screen *screen);
void	do_select(t_on_screen *screen,
		  SDLNet_SocketSet *set);
void	do_write(t_on_screen *screen);

#endif /*! SOCKET_H_ !*/
