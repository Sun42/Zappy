/*
** cmd_save.c for cmd_save in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:33:49 2009 yavuz yurdusev
** Last update Thu Apr 23 20:33:50 2009 yavuz yurdusev
*/

#include "buffer.h"

static void	add_complete_cmd(t_cli *my_cli, char *str, int len, char mode)
{
  if (mode == 'R')
    {
      if (list_full(my_cli->lcmdr))
	return ;
      add_cmdr(my_cli , str, len, 1);
    }
  if (mode == 'W')
    {
      add_cmdw(my_cli , str, len, 1);
    }
}

static void	add_uncomplete_cmd(t_cli *my_cli, char *str, int len, char mode)
{
  if (mode == 'R')
    {
      if (list_full(my_cli->lcmdr))
	return ;
      add_cmdr(my_cli , str, len, 0);
    }
  if (mode == 'W')
    {
      add_cmdw(my_cli , str, len, 0);
    }
}

/*
** entry point
** decoupe le buffer en commandes
*/
void	save_cmd(t_cli *my_cli, char *str, int size, char mode)
{
  int	nbcmd;
  int	complete;
  int	taillecmd;
  int	sum;

  sum = 0;
  if (size < 1)
    return ;
  nbcmd = count_cmd(str, size, &complete);
  while (nbcmd)
    {
      taillecmd = MIN(my_strlenbuf(str) + 1, size);
      if (nbcmd == 1 && !complete)
	add_uncomplete_cmd(my_cli, str, (size - sum), mode);
      else
	add_complete_cmd(my_cli, str, taillecmd, mode);
      str += taillecmd;
      sum += taillecmd;
      nbcmd--;
    }
}

/*
** recoit la commande decoupee
** et se charge de la placer correctement
** dans la liste des commandes
*/
void	add_cmdr(t_cli *my_cli, char *str, int size, int is_complet)
{
  int	indice;
  t_cmd	*info;
  int	i;

  if ((indice = get_indice_r(my_cli)) == -1)
    return ;
  info = get_cmd(my_cli->lcmdr, indice);
  info->is_complet = is_complet;
  i = add_bufr(my_cli, info, str, size);
  if (i == -42)
    {
      remove_cmd(&(my_cli->lcmdr), indice);
      return ;
    }
  if (is_new(info))
    {
      info->indice_buf = i;
      info->len = size;
    }
  else
    info->len += size;
}

/*
**
*/
void	add_cmdw(t_cli *my_cli, char *str, int size, int is_complet)
{
  int	indice;
  t_cmd	*info;
  int	i;

  if ((indice = get_indice_w(my_cli)) == -1)
    return ;
  info = get_cmd(my_cli->lcmdw, indice);
  info->is_complet = is_complet;
  i = add_bufw(my_cli, info, str, size);
  if (i == -42)
    {
      remove_cmd(&(my_cli->lcmdw), indice);
      return ;
    }
  if (is_new(info))
    {
      info->indice_buf = i;
      info->len = size;
    }
  else
    info->len += size;
}
