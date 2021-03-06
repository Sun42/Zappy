#include <stdio.h>
#include "buffer.h"
/*
** ajoute un text au buffer, penser a faire un can_add
** return values
** 1 ajoute en fin de buffer
** 2 ajoute en debut de buffer
** 3 ajoute en liste chainee tampon
** -1 pas pu etre ajoutee (liste chainee > 10)
*/

static void	add_begbuf(t_buf *my_buf, char *text);
static void	add_endbuf(t_buf *my_buf, char *text);
static int	can_add_endbuf(t_buf *my_buf, int len);
static int	can_add_begbuf(t_buf *my_buf, int len);


int	add_buf(t_buf *my_buf, char *text)
{
  if (can_add_endbuf(my_buf, my_strlenbuf(text) + 1))
    {
      add_endbuf(my_buf, text);
      printf("add_end buffer, %s \n", text);
      return (1);
    }
  my_buf->end = 0;
  if (can_add_begbuf(my_buf, my_strlenbuf(text) + 1))
    {
      add_begbuf(my_buf, text);
      printf("add_begin buffer, %s \n", text);
      return (2);
    }
  printf("Error add_buf, %s \n", text);
  return (-1);
}

/*
**ajoute en debut de buffer
*/

static void     add_begbuf(t_buf *my_buf, char *text)
{
  int   len;
  int   i;

  len = my_strlenbuf(text) + 1;
  i = my_buf->end;
  while (i < len)
    {
      my_buf->buf[i] = text[i];
      i++;
    }
  my_buf->end = i - 1;
}

/*
** ajoute en fin de buffer (a la suite)
*/
static void	add_endbuf(t_buf *my_buf, char *text)
{
  int		cpt;
  int		end;
  int		len;

  cpt = 0;
  end = my_buf->end;
  len = my_strlenbuf(text) + 1;
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
}
/*
** bool assez de place dans la fin du buffer ?
** checker aussi si end nempiete pas sur begin
*/
static int	can_add_endbuf(t_buf *my_buf, int len)
{
  if ((BUF_SIZE - my_buf->end) < len)
    return (0);
  if ((my_buf->buf[my_buf->end] == '0') && (my_buf->end >= my_buf->begin))
    return (1);
  return (0);
}

/*
** bool peut-on placer le text en debut de buffer ?
*/
static int	can_add_begbuf(t_buf *my_buf, int len)
{
  int		i;

  if (BUF_SIZE < len)
    return (0);
  if (len > my_buf->begin)
    return (0);
  i = my_buf->end;;
  while (i < len)
    {
      if (my_buf->buf[i] != '0')
        return (0);
    }
  return (1);
}

