/*
** buf_add_onbuf.c for buf_add_onbuf in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:36:16 2009 yavuz yurdusev
** Last update Thu Apr 23 20:36:16 2009 yavuz yurdusev
*/

#include "buffer.h"

/*
** bool assez de place dans la fin du buffer ?
** checker aussi si end nempiete pas sur begin
*/
int	can_add_endbuf(t_buf *my_buf, int len)
{
  if ((BUF_SIZE - my_buf->end) < len)
    return (0);
  if ((my_buf->end >= my_buf->begin) && (my_buf->buf[my_buf->end] == FREED))
    return (1);
  return (0);
}

/*
** bool peut-on placer le text en debut de buffer ?
*/
int	can_add_begbuf(t_buf *my_buf, int len)
{
  int	i;

  if (BUF_SIZE < len)
    return (0);
  if (len > my_buf->begin)
    return (0);
  i = 0;
  while ((i < my_buf->begin) && (my_buf->buf[i] != FREED))
    i++;
  while (len)
    {
      if (my_buf->buf[i] != FREED)
        return (0);
      i++;
      len--;
    }
  if (i >= my_buf->begin)
    return (0);
  return (1);
}

/*
** ajoute en debut de buffer
*/
int	add_begbuf(t_buf *my_buf, char *text, int len)
{
  int	i;
  int	j;
  int	ret;

  i = 0;
  j = 0;
  while (my_buf->buf[i] != FREED && (i < my_buf->begin))
    i++;
  ret = i;
  while (j < len)
    {
      my_buf->buf[i] = text[j];
      j++;
      i++;
    }
  my_buf->end = i;
  return (ret);
}

/*
** ajoute en fin de buffer (a la suite)
** retourne lindice de debut dajout soit lancien my_buf->end
*/
int	add_endbuf(t_buf *my_buf, char *text, int len)
{
  int	cpt;
  int	end;
  int	ret;

  cpt = 0;
  ret = end = my_buf->end;
  while (cpt < len)
    {
      if (end == BUF_SIZE)
        end = 0;
      my_buf->buf[end] = text[cpt];
      cpt++;
      end++;
    }
  if (end == BUF_SIZE)
    my_buf->end = 0;
  else
    my_buf->end = end;
  return (ret);
}
