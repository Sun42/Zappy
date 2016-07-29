#include <stdio.h>
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
  while ((my_buf->buf[i] == FREED) && (i < BUF_SIZE))
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
