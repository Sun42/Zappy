#include <stdio.h>
#include "buffer.h"


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

  printf("Bufncpy begin=>%i, %i, ", begin, n);
  cpt = 0;
  i = begin;
  while (cpt < n)
    {
      if (i == BUF_SIZE)
	i = 0;
      if (bufr[i] == FREED)
	{
          i++;
          continue ;
        }
      printf("[%c]", bufr[i]);
      dest[cpt] = bufr[i];
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

  i = begin;
  cpt = 0;
  while (cpt < len)
    {
      if (i == BUF_SIZE)
	i = 0;
      if (bufr[i] == set)
	{
          i++;
          continue ;
        }
      bufr[i] = set;
      cpt++;
      i++;
    }
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
      if (my_buf->buf[i] == ENDCMD)
        return (cpt + 1);
      i++;
      cpt++;
    }
  return (-1);
}

int	count_cmd(char *str, int size, int *complete)
{
  int	i;
  int	cpt;
  int	flag;

  flag = 0;
  cpt = 1;
  i = 0;
  *complete = 0;
  if (size < 1)
    return (0);
  while (i < size)
    {
      if (flag)
	{
	  flag = 0;
	  cpt++;
	}
      if (str[i] == ENDCMD)
	flag = 1;
      i++;
    }
  if (flag)
    *complete = 1;
  /*printf("RETURN OF COUNT %i \n", cpt);*/
  return (cpt);
}


void		remove_at(t_cmd **begin, int indice)
{
  t_cmd         *tmp;
  t_cmd         *prev;
  t_cmd         *save;

  tmp = *begin;
  prev = tmp;
  while (*cpt == indice)
    {
      save = (*begin)->next;
      (*begin) = save;
      *cpt = (*cpt) + 1;
    }
  while (tmp != 0)
    {
      if (*cpt == indice)
        {
          prev->next = tmp->next;
          free(tmp);
        }
      prev = ((*cpt) == (indice) ? (prev) : (tmp));
      tmp = (*tmp).next;
      *cpt = (*cpt) + 1;
    }
  return (*begin);
*/
