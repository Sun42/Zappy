/*
** struct_ptr_func.h for struct_ptr_func in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/header
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:30:40 2009 yavuz yurdusev
** Last update Thu Apr 23 20:30:41 2009 yavuz yurdusev
*/

#include "map.h"

#ifndef STRUCT_PTR_FUNC_H_
# define STRUCT_PTR_FUNC_H_

typedef struct	s_cmd_func
{
  char		*name_func;
  void		(*f)(t_on_screen *screen, char *msg);
  int		nb_arg;
}		t_cmd_func;

#endif /*! STRUCT_PTR_FUNC_H_ !*/
