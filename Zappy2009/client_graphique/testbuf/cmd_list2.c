#include <stdio.h>
#include "buffer.h"

/*
** bool => true si liste pleine
*/
int	list_full(t_cmd *my_list)
{
  int	last;
  t_cmd	*my_cmd;

  last = my_list_size(my_list) - 1;
  my_cmd = get_cmd(my_list, last);
  if ((last == 9) && (my_cmd->is_complet))
    return (1);
  return (0);
}

/*
** retourne le nombre de cmd dans une string
*/
int	count_cmd(char *str, int size, int *complete)
{
  int	i;
  int	cpt;
  int	flag;

  flag = 0;
  cpt = 1;
  i = 0;
  *complete = 0;
  if (size < 1)
    return (0);
  while (i < size)
    {
      if (flag)
	{
	  flag = 0;
	  cpt++;
	}
      if (str[i] == ENDCMD)
	flag = 1;
      i++;
    }
  if (flag)
    *complete = 1;
  return (cpt);
}
