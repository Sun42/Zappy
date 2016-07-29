/*
** func_init_ghost.h for func_init_ghost in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/header
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:26:24 2009 yavuz yurdusev
** Last update Thu Apr 23 20:26:25 2009 yavuz yurdusev
*/

#ifndef FUNC_INIT_GHOST_H_
# define FUNC_INIT_GHOST_H_

void	init_ghost(t_on_screen *screen);
t_point	ghost_killer(t_on_screen *screen, int ghost_num);
void	print_ghost_on_case(t_on_screen *screen, t_point *coor, int is_camera);

#endif /*! FUNC_INIT_GHOST_H_ !*/
