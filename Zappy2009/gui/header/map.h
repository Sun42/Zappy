/*
** map.h for map in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/header
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:29:10 2009 yavuz yurdusev
** Last update Thu Apr 23 20:29:14 2009 yavuz yurdusev
*/

#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_net.h"
#include "SDL/SDL_ttf.h"

#include "struct.h"

#ifndef MAP_H_
# define MAP_H_

typedef	struct	s_way_to_move
{
  int		way;
  void		(*f)(t_on_screen *, t_cli *);
}		t_way_to_move;

typedef	struct	s_init
{
  int		id;
  char		*imagefile;
}		t_init;

typedef struct	s_key_manage
{
  SDLKey	key;
  int		(*f)(t_on_screen *, int);
}		t_key_manage;

void	init_map(t_on_screen *);
void	init_map_value(t_on_screen *);
int	move_manager(t_on_screen *, t_cli *);
void	move_teleport(t_on_screen *, t_cli *);
void	init_clip(t_on_screen *);

#endif /*! MAP_H_ !*/
