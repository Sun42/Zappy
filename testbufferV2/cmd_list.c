#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include "buffer.h"

char	*strdup(const char *s);
char	*strndup(const char *s, size_t n);

/*
** free the list! :)
*/
/*
void		my_free_list(t_cmd **begin)
{
  t_cmd		*buffer;

  while (*begin)
    {
      tmp = (*begin)->next;
      free((*begin)->data);
      free(*begin);
      *begin = tmp;
    }
}
*/

int	get_icur_cmd(t_cmd *my_cmd)
{
  int	i;
  t_cmd *cur_cmd;

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

/*
** remplace les infos d'une commande
** a lindice donne par la structure info
*/

void	set_cmd(t_cmd *my_cmd, int indice, t_cmd *info)
{
  int	i;
  t_cmd *cur_cmd;
  
  cur_cmd = my_cmd;
  i = 0;
  while (i < indice)
    {
      i++;
      cur_cmd = cur_cmd->next;
    }
  cur_cmd->len = info->len;
  cur_cmd->is_complet = info->is_complet;
  cur_cmd->timeval = info->timeval;
  cur_cmd->indice_buf = info->indice_buf;
  cur_cmd->cmd = info->cmd;
}


/*
** initialise les infos d'une commande par defaut
*/
void    init_cmd(t_cmd *my_cmd)
{
  my_cmd->timeval = -1;
  my_cmd->indice_buf = -1;
  my_cmd->len = -1;
  my_cmd->cmd = NULL;
  my_cmd->is_complet = 0;
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

int		my_put_in_list(t_cmd **begin)
{
  t_cmd		*new_elem;

  if ((new_elem = malloc(sizeof(*new_elem))) == NULL)
    return (0);
  new_elem->next = *begin;
  init_cmd(new_elem);
  init_cmd(new_elem);
  *begin = new_elem;
  return (1);
}

int             my_list_size(t_cmd *begin)
{
  int           i;

  i = 0;
  while (begin != NULL)
    {
      begin = begin->next;
      i = i + 1;
    }
  return (i);
}

int	is_new(t_cmd *my_cmd)
{
  if (my_cmd->len == -1)
    return (1);
  else
    return (0);
}

int	is_onbuf(t_cmd *my_cmd)
{
  if (my_cmd->indice_buf == -1)
    return (0);
  else
    return (1);
}
/*
int	my_rev_list(t_cmd **begin)
{
  t_cmd		*next;
  t_cmd        *prec;

  next = 0;
  prec = begin[0]->next;
  while (prec != 0)
    {
      begin[0]->next = next;
      next = *begin;
      *begin = prec;
      prec = begin[0]->next;
    }
  begin[0]->next = next;
}
*/
