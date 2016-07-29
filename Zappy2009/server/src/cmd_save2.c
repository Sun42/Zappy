/*
** cmd_save2.c for cmd_save2 in /u/all/yurdus_y/cu/rendu/c/Zappy2009
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:46:39 2009 yavuz yurdusev
** Last update Thu Apr 23 20:46:40 2009 yavuz yurdusev
*/

#include "buffer.h"

/*
** retourne l'indice de la cmd courante
** - 1 si fail
*/
int	get_indice_w(t_cli *my_cli)
{
  int	indice;

  if (my_cli->lcmdw == NULL)
    if (!my_put_in_list(&(my_cli->lcmdw)))
      return (-1);
  indice = get_icur_cmd(my_cli->lcmdw);
  if (indice == -1)
    {
      if (!my_put_in_list(&(my_cli->lcmdw)))
	return (-1);
      indice = get_icur_cmd(my_cli->lcmdw);
    }
  return (indice);
}

int	get_indice_r(t_cli *my_cli)
{
  int	indice;

  if (my_cli->lcmdr == NULL)
    if (!my_put_in_list(&(my_cli->lcmdr)))
      return (-1);
  indice = get_icur_cmd(my_cli->lcmdr);
  if (indice == -1)
    {
      if (!my_put_in_list(&(my_cli->lcmdr)))
	return (-1);
      indice = get_icur_cmd(my_cli->lcmdr);
    }
  return (indice);
}
