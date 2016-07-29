/*
** func_xalloc.c for func_xalloc in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:30:07 2009 yavuz yurdusev
** Last update Thu Apr 23 20:30:07 2009 yavuz yurdusev
*/

#include <stdio.h>
#include <stdlib.h>

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
