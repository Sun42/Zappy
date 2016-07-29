/*
** func_pcli.c for func_pcli in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:31:08 2009 yavuz yurdusev
** Last update Thu Apr 23 20:31:08 2009 yavuz yurdusev
*/

#include "server.h"

t_pcli		*new_pcli(t_cli *ia)
{
  t_pcli	*new;

  new = xmalloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  new->lcli = ia;
  return (new);
}

/*
** Ajouter le ptr d'un client a une case
*/
void	add_pcli(t_pcli **begin, t_pcli *cur)
{
  cur->next = (*begin);
  (*begin) = cur;
}

/*
** supprimer le ptr d'un client d'une case
*/
void		remove_pcli(t_pcli **begin, t_pcli *the_cli)
{
  t_pcli	*save;
  t_pcli	*list;

  list = (*begin);
  save = NULL;
  while (list != NULL)
    {
      if (list == the_cli)
	break;
      save = list;
      list = list->next;
    }
  if (save == NULL)
    (*begin) = the_cli->next;
  else
    save->next = the_cli->next;
}
