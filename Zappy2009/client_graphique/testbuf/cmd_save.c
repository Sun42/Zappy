#include <stdlib.h>
#include <stdio.h>
#include "buffer.h"

static void	add_uncomplete_cmd(t_msg *my_msg, char *str, int len, char mode);
static void	add_complete_cmd(t_msg *my_msg, char *str, int len, char mode);

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
	add_complete_cmd(my_msg, str, (size - sum), mode);
      str += taillecmd;
      sum += taillecmd;
      nbcmd--;
    }
}

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
  printf("Indice de la cmd courante %i\n", indice);
  if (indice == -1)
    {
      my_put_in_list(&(my_msg->lcmdr));
      indice = get_icur_cmd(my_msg->lcmdr);
    }
  info = get_cmd(my_msg->lcmdr, indice);
  info->is_complet = is_complet;
  if (is_new(info))
    {
      printf("New \n");
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
