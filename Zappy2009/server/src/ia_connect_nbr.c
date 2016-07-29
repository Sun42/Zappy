/*
** ia_connect_nbr.c for ia_connect_nbr in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:24:50 2009 yavuz yurdusev
** Last update Thu Apr 23 20:24:51 2009 yavuz yurdusev
*/

#include <string.h>

#include "ia_command.h"

void	ia_connect_nbr(t_world *world __attribute__((unused)),
		       t_cli *ia)
{
  char	nb[INT_LEN];
  int	len_nb;

  len_nb = atio(ia->team->nb_client, nb);
  save_cmd(ia, nb, len_nb, 'W');
  save_cmd(ia, MSG_END, LEN_END, 'W');
}
