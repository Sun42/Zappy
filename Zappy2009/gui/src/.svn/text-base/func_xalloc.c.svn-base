/*
** func_xalloc.c for func_xalloc in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:41:59 2009 yavuz yurdusev
** Last update Sun Apr 26 12:31:29 2009 yavuz yurdusev
*/

#include <stdio.h>
#include <stdlib.h>

#include "map.h"
#include "func_xmemory.h"
#include "command.h"

void	*xmalloc(unsigned int size)
{
  void	*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    perror("Erreur: malloc()");
  return (ptr);
}

void	*xrealloc(void *ptr, unsigned int size)
{
  ptr = realloc(ptr, size);
  if (ptr == NULL)
    perror("Erreur: realloc()");
  return (ptr);
}

char	*my_strndup(char *s, size_t n)
{
  char	*str;

  str = xmalloc(n);
  if (!str)
    return (NULL);
  strncpy(str, s, n);
  return (str);
}
