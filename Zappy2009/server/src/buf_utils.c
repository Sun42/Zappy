/*
** buf_utils.c for buf_utils in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:35:10 2009 yavuz yurdusev
** Last update Thu Apr 23 20:35:10 2009 yavuz yurdusev
*/

#include "buffer.h"

/*
** initialise le buffer et les variables a zero
*/
void	init_buf(t_buf *my_buf)
{
  int	i;

  i = 0;
  while (i < BUF_SIZE)
    {
      my_buf->buf[i] = FREED;
      i++;
    }
  my_buf->begin = 0;
  my_buf->end = 0;
}

int	my_strlenbuf(char *str)
{
  int	i;

  i = 0;
  while (str[i] != ENDCMD && str[i + 1] != '\0')
    i++;
  return (i);
}

void	bufncpy(char *dest, char bufr[], int begin, int n)
{
  int	i;
  int	cpt;
  int	noinf;

  noinf = 0;
  cpt = 0;
  i = begin;
  while (cpt < n)
    {
      if (noinf > BUF_SIZE)
	return ;
      if (i == BUF_SIZE)
	i = 0;
      if (bufr[i] == FREED)
	{
	  noinf++;
	  i++;
          continue ;
        }
      dest[cpt] = bufr[i];
      noinf++;
      i++;
      cpt++;
    }
}

/*
** set a zero n chars qui netaient pas deja a set
*/
void	bufmemset(char bufr[], int begin, int len, char set)
{
  int	i;
  int	cpt;
  int	noinf;

  i = begin;
  cpt = 0;
  noinf = 0;
  while (cpt < len)
   {
     if (noinf > BUF_SIZE)
       return ;
     if (i == BUF_SIZE)
       i = 0;
     if (bufr[i] == set)
       {
	 i++;
	 noinf++;
	 continue ;
       }
     bufr[i] = set;
     cpt++;
     i++;
     noinf++;
   }
}
