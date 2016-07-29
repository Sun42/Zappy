/*
** cmd_save.c for cmd_save in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:38:51 2009 yavuz yurdusev
** Last update Thu Apr 23 20:38:52 2009 yavuz yurdusev
*/

#include "define.h"
#include "buffer.h"

static void	add_complete_cmd(t_msg *my_msg, char *str, int len, char mode)
{
  if (mode == 'R')
    {
      add_cmdr(my_msg , str, len, 1);
    }
  if (mode == 'W')
    {
      add_cmdw(my_msg , str, len, 1);
    }
}

static void	add_uncomplete_cmd(t_msg *my_msg, char *str, int len, char mode)
{
  if (mode == 'R')
    {
      add_cmdr(my_msg , str, len, 0);
    }
  if (mode == 'W')
    {
      add_cmdw(my_msg , str, len, 0);
    }
}

/*
** entry point
** decoupe le buffer en commandes
*/
void	save_cmd(t_msg *my_msg, char *str, int size, char mode)
{
  int	nbcmd;
  int	complete;
  int	taillecmd;
  int	sum;

  sum = 0;
  nbcmd = count_cmd(str, size, &complete);
  while (nbcmd)
    {
      taillecmd = MIN(my_strlenbuf(str) + 1, size);
      if (nbcmd == 1 && !complete)
	add_uncomplete_cmd(my_msg, str, (size - sum), mode);
      else
	add_complete_cmd(my_msg, str, taillecmd, mode);
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
void	add_cmdr(t_msg *my_msg, char *str, int size, int is_complet)
{
  int	indice;
  t_cmd	*info;

  if (my_msg->lcmdr == NULL)
    my_put_in_list(&(my_msg->lcmdr));
  indice = get_icur_cmd(my_msg->lcmdr);
  if (indice == -1)
    {
      my_put_in_list(&(my_msg->lcmdr));
      indice = get_icur_cmd(my_msg->lcmdr);
    }
  info = get_cmd(my_msg->lcmdr, indice);
  info->is_complet = is_complet;
  if (is_new(info))
    {
      info->indice_buf = add_bufr(my_msg, info, str, size);
      info->len = size;
    }
  else
    {
      add_bufr(my_msg, info, str, size);
      info->len += size;
    }
}

/*
** todo checker retour de addbuf
*/
void	add_cmdw(t_msg *my_msg, char *str, int size, int is_complet)
{
  int	indice;
  t_cmd	*info;

  if (my_msg->lcmdw == NULL)
    my_put_in_list(&(my_msg->lcmdw));
  indice = get_icur_cmd(my_msg->lcmdw);
  if (indice == -1)
    {
      my_put_in_list(&(my_msg->lcmdw));
      indice = get_icur_cmd(my_msg->lcmdw);
    }
  info = get_cmd(my_msg->lcmdw, indice);
  info->is_complet = is_complet;
  if (is_new(info))
    {
      info->indice_buf = add_bufw(my_msg, info, str, size);
      info->len = size;
    }
  else
    {
      add_bufw(my_msg, info, str, size);
      info->len += size;
    }
}
