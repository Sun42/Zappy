#include "buf.h"


/*
** initialise le buffer et les variables a zero
*/
void	init_buf(t_buf *my_buf)
{
  int	i;

  i = 0;
  /*bzero(my_buf->buf, BUF_SIZE);*/
  while (i < BUF_SIZE)
    {
      my_buf->buf[i] = '0';
      i++;
    }
  my_buf->begin = 0;
  my_buf->end = 0;
}

int	my_strlenbuf(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 'n' && str[i + 1] != '\0')
    i++;
  return (i);
}

int	get_len_extract(t_buf *my_buf)
{
  int	cpt;
  int	next;
  int	i;

  cpt = 0;
  i = my_buf->begin;
  while (cpt < BUF_SIZE)
    {
      if (i == BUF_SIZE)
        i = 0;
      next = i + 1;
      if (next == BUF_SIZE)
        next = 0;
      if (my_buf->buf[i] == 'n')
        return (cpt + 1);
      i++;
      cpt++;
    }
  return (-1);
}
