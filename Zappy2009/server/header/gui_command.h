/*
** gui_command.h for gui_command in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/header
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:19:40 2009 yavuz yurdusev
** Last update Thu Apr 23 20:19:43 2009 yavuz yurdusev
*/

#include "server.h"

#ifndef GUI_COMMAND_H_
# define GUI_COMMAND_H_

typedef struct	s_cmd_funcg
{
  char		*name_func;
  void		(*f)(t_world *, t_cli *, char *);
  int		nb_arg;
}		t_cmd_funcg;

void	gui_msz(t_world *, t_cli *, char *);
void	gui_bct_bis(t_world *, t_cli *, int, int);
void	gui_bct(t_world *, t_cli *, char *);
void	gui_mct(t_world *, t_cli *, char *);
void	gui_tna(t_world *, t_cli *, char *);
void	gui_ppo(t_world *, t_cli *, char *);
void	gui_plv(t_world *, t_cli *, char *);
void	gui_pin_bis(t_world *, t_cli *, t_cli *);
void	gui_pin(t_world *, t_cli *, char *);
void	gui_sgt(t_world *, t_cli *, char *);


void	gui_print_ressource(t_cli *, t_res *, char [INT_LEN]);

#endif /* GUI_COMMAND_H_ */
