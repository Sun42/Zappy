#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include "buffer.h"

int	my_put_in_list(t_cmd **begin)
{
  t_cmd	*new_elem;

  if ((new_elem = malloc(sizeof(*new_elem))) == NULL)
    return (0);
  new_elem->next = *begin;
  init_cmd(&(new_elem));
  *begin = new_elem;
  return (1);
}

int	my_list_size(t_cmd *begin)
{
  int	i;

  i = 0;
  while (begin != NULL)
    {
      begin = begin->next;
      i = i + 1;
    }
  return (i);
}

/*
**recupere la commande alindice voulu
*/
t_cmd	*get_cmd(t_cmd *my_cmd, int indice)
{
  int	i;
  t_cmd	*cur_cmd;

  i = 0;
  cur_cmd = my_cmd;
  while (i < indice)
    {
      cur_cmd = cur_cmd->next;
      i++;
    }
  return (cur_cmd);
}

/*
** retourne l'indice de la commande en cours
** -1 si tt les cmd sont completes
*/
int	get_icur_cmd(t_cmd *my_cmd)
{
  int	i;
  t_cmd	*cur_cmd;

  cur_cmd = my_cmd;
  i = 0;
  while (cur_cmd != NULL)
    {
      if (cur_cmd->is_complet == 0)
	return (i);
      cur_cmd = cur_cmd->next;
      i++;
    }
  return (-1);
}

void	free_allcmd(t_cmd *my_cmd)
{
  t_cmd	*save_cmd;
  t_cmd	*cur_cmd;

  save_cmd = cur_cmd;
  cur_cmd = my_cmd;
  while (cur_cmd != NULL)
    {
      save_cmd = cur_cmd;
      cur_cmd = cur_cmd->next;
      free_cmd(save_cmd);
    }
}
