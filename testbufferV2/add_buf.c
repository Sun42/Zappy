#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "buffer.h"

char *strndup(const char *s, size_t n);

/*
** return values
** 1 ajoute en fin de buffer
** 2 ajoute en debut de buffer
** 3 ajoute en liste chainee tampon
** -1 pas pu etre ajoutee (liste chainee > 10)
*/

static void	add_begbuf(t_buf *my_buf, char *text, int len);
static int	add_endbuf(t_buf *my_buf, char *text, int len);
static int	can_add_endbuf(t_buf *my_buf, int len);
static int	can_add_begbuf(t_buf *my_buf, int len);
static int	add_overflow(t_cli *my_cli, t_cmd *my_cmd, char *text, int len);

/*
** ajoute dans le buffer et retourne l'indice_buf
** 0 =>add begin_buffer, -1 ajout en malloc car buffer full
*/
int	add_buf(t_cli *my_cli, t_cmd *my_cmd, char *text, int len)
{
  int	indice_buf;

  if (can_add_endbuf(my_cli->bufr, len))
    {
      indice_buf = add_endbuf(my_cli->bufr, text, len);
      /*printf("add_end buffer, %s \n", text);*/
      return (indice_buf);
    }
  my_cli->bufr->end = 0;
  if (can_add_begbuf(my_cli->bufr, len))
    {
      add_begbuf(my_cli->bufr, text, len);
      /*printf("add_begin buffer, %s \n", text);*/
      return (0);
    }
  if (add_overflow(my_cli, my_cmd, text, len) == -1)
    return (-1);
  else
    return (3);
}

static int add_overflow(t_cli *my_cli, t_cmd *my_cmd, char *text, int len)
{
  printf("\033[0;33mAdd overfloW \n");
  aff_cmd(my_cmd);
  if (is_new(my_cmd))
    {
      printf("\033[0;33mIS new cmd \n");
      if ((my_cmd->cmd = malloc(sizeof(char) * len + 1)) == NULL)
	return (-1);
      my_cmd->cmd = strndup(text, len);
    }
  else
    {
      printf("\033[0;33mIs not new cmd \n");
      if (is_onbuf(my_cmd))
	{
	  printf("\033[0;33mIs on buf \n");
	  if ((my_cmd->cmd = malloc(sizeof(char) * (my_cmd->len + len + 1))) == NULL)
	    return (-1);
	  bufncpy(my_cmd->cmd , my_cli->bufr->buf, my_cmd->indice_buf, my_cmd->len);
	  my_cmd->cmd[my_cmd->len] = '\0';
	  strncat(my_cmd->cmd, text, len);
	  bufmemset(my_cli->bufr->buf, my_cmd->indice_buf, my_cmd->len, FREED);
	}
      else
	{
	  printf("\033[0;33mIs on heap \n");
	  if ((my_cmd->cmd = realloc(my_cmd->cmd, sizeof(char) * (len + my_cmd->len + 1))) == NULL)
	    return (-1);
	  strncat(my_cmd->cmd, text, len);
	}
    }
  printf("\033[0;m");
}

/*
**ajoute en debut de buffer
*/
static void	add_begbuf(t_buf *my_buf, char *text, int len)
{
  int		i;

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
** retourne lindice de debut dajout soit lancien my_buf->end 
*/
  static int	add_endbuf(t_buf *my_buf, char *text, int len)
{
  int		cpt;
  int		end;
  int		ret;
  
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
/*
** bool assez de place dans la fin du buffer ?
** checker aussi si end nempiete pas sur begin
*/
static int	can_add_endbuf(t_buf *my_buf, int len)
{
  if ((BUF_SIZE - my_buf->end) < len)
    return (0);
  if ((my_buf->buf[my_buf->end] == FREED) && (my_buf->end >= my_buf->begin))
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
      if (my_buf->buf[i] != FREED)
        return (0);
    }
  return (1);
}

