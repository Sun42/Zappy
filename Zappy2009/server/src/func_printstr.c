/*
** func_printstr.c for func_printstr in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:30:59 2009 yavuz yurdusev
** Last update Thu Apr 23 20:31:00 2009 yavuz yurdusev
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	my_putchar2(const char c)
{
  if (write(2, &c, 1) == -1)
    perror("Erreur : write() --> my_putchar2()");
}

void	my_putchar(const char c)
{
  if (write(1, &c, 1) == -1)
    my_putchar2(c);
}

void	put_error(const char *str)
{
  int	ret;
  int	size;

  size = strlen(str);
  ret = write(2, str, size);
  if (ret == -1)
    perror("Erreur: write() --> put_error()");
  else
    if (ret != size)
      put_error(str + ret);
}

void	putstr(const char *str)
{
  int	ret;
  int	size;

  size = strlen(str);
  ret = write(1, str, size);
  if (ret == -1)
    {
      perror("Erreur: write() --> putstr()");
      ret = 0;
    }
  if (ret != size)
    put_error(str + ret);
}
