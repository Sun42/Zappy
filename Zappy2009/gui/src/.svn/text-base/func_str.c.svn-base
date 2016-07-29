/*
** func_str.c for func_str in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:39:40 2009 yavuz yurdusev
** Last update Thu Apr 23 20:39:42 2009 yavuz yurdusev
*/

#include <stdio.h>

void	atio(int nb, char *str)
{
  if (sprintf(str, "%i", nb) < 0)
    {
      perror("Erreur : sprintf() --> atio()");
      str[0] = '0';
      str[1] = '\0';
    }
}

int	n_strlen(char *str, int space)
{
  int	i;

  i = 0;
  if (!space)
    while (str[i] != '\0' && str[i] != '\n')
      i++;
  else
    while (str[i] != '\0' && str[i] != '\n' && str[i] != ' ')
      i++;
  return (i);
}
