/*
** func_str.c for func_str in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:30:34 2009 yavuz yurdusev
** Last update Thu Apr 23 20:30:35 2009 yavuz yurdusev
*/

#include <stdio.h>

#include "ia_command.h"

int	char_to_int(char *nbc)
{
  int	i;
  int	nbi;
  int	pow;

  i = 0;
  while (!END_STR(nbc[i]) && nbc[i] != ' ')
    if (nbc[i] < '0' || nbc[i++] > '9')
      return (-1);
  nbi = 0;
  pow = 1;
  while (--i >= 0)
    {
      nbi += ((nbc[i] - 48) * pow);
      pow *= 10;
    }
  return (nbi);
}

int	atio(int nb, char *str)
{
  int	ret;

  ret = sprintf(str, "%d", nb);
  if (ret <= 0)
    {
      perror("Erreur : sprintf() --> atio()");
      str[0] = '0';
      str[1] = '\0';
      ret = 1;
    }
  return (ret);
}

void	print_nb(int nb)
{
  char	str[INT_LEN];

  atio(nb, str);
  putstr(str);
}
