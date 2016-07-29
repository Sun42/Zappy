/*
** buf_utils2.c for buf_utils2 in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:34:39 2009 yavuz yurdusev
** Last update Thu Apr 23 20:34:40 2009 yavuz yurdusev
*/

#include "buffer.h"

void	rewind_buf(t_buf *my_buf)
{
  int	i;

  if (my_buf->begin == my_buf->end)
    {
      my_buf->begin = 0;
      my_buf->end = 0;
      return ;
    }
  i = my_buf->begin;
  while ((i < BUF_SIZE) && (my_buf->buf[i] == FREED))
    {
      if (i == my_buf->end)
	{
	  my_buf->begin = 0;
	  my_buf->end = 0;
	  return ;
	}
      i++;
    }
  if (i >= BUF_SIZE)
    my_buf->begin = 0;
}

/*
** tourne depuis l'indice begin sur une len
*/
void	turn_my_buf(t_buf *my_buf, int indice, int len)
{
  int	cpt;

  cpt = 0;
  while (cpt < len)
    {
      if (indice >= BUF_SIZE)
        indice = 0;
      my_buf->buf[indice] = FREED;
      indice++;
      cpt++;
    }
  if (indice == BUF_SIZE)
    indice = 0;
  my_buf->begin = indice;
}
