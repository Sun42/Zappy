/*
** ia_command.h for ia_command in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/header
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:20:13 2009 yavuz yurdusev
** Last update Sat Apr 25 10:11:00 2009 yavuz yurdusev
*/

#include "gui_send.h"
#include "buffer.h"

#ifndef IA_COMMAND_H_
# define IA_COMMAND_H_

void	ia_avance(t_world *, t_cli *);
void	ia_birth(t_world *, t_cli *);
void	ia_droite(t_world *, t_cli *);
void	ia_gauche(t_world *, t_cli *);
void	ia_print_content_case(t_res *, t_cli *);
void	ia_voir(t_world *, t_cli *);
void	update_food(t_world *, t_cli *);
void	ia_inventaire(t_world *, t_cli *);
void	ia_prend(t_world *, t_cli *);
void	ia_pose(t_world *, t_cli *);
void	ia_expulse(t_world *, t_cli *);
void	ia_broadcast(t_world *, t_cli *);
char	pre_incantation(t_world *, t_cli *);
void	ia_incantation(t_world *, t_cli *);
void	ia_fork(t_world *, t_cli *);
void	ia_connect_nbr(t_world *, t_cli *);

int	strlen_cmd(const char *);
char	*get_argument(char *, int);
char	cmd_cmp(const char *, const char *);
int	get_nb_arg(const char *);
int	get_num_objet(const char *);
char	*get_name_objet(int, int *);

#endif /* IA_COMMAND_H_ */
