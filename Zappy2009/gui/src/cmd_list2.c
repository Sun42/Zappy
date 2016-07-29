/*
** cmd_list2.c for cmd_list2 in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:38:37 2009 yavuz yurdusev
** Last update Thu Apr 23 20:38:38 2009 yavuz yurdusev
*/

#include "define.h"
#include "buffer.h"

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
