#include <stdio.h>
#include "buffer.h"

/*
** debug only
*/
void    aff_buf(t_buf *my_buf)
{
  int   i;

  i = 0;
  printf("\033[0;32mVbuffer[0...%i], begin %i, end %i \n\033[0;m", BUF_SIZE - 1, my_buf->begin, my_buf->end);
  while (i < BUF_SIZE)
    {
      printf("\033[0;31m[%c]\033[0;m", my_buf->buf[i]);
      i++;
    }
  printf("\n");
}

/*
** == del_buf
*/
void            turn_my_buf(t_buf *my_buf, int indice, int len)
{
  int           cpt;

  printf("Turn my_buff %i \n", len);
  cpt = 0;
  while (cpt < len)
    {
      if (indice >= BUF_SIZE)
        indice = 0;
      my_buf->buf[indice] = '0';
      indice++;
      cpt++;
    }
  if (indice == BUF_SIZE)
    indice = 0;
  my_buf->begin = indice;
}

/*
**debug only
*/
void	aff_cli(t_cli *my_cli)
{
  aff_buf(my_cli->bufr);
  /*
  aff_listcmd(my_cli->listr);
  */
}

/*
** debug only
*/
void    aff_listcmd(t_cmd *my_cmd)
{
  int   i;
  t_cmd *cur_cmd;

  cur_cmd = my_cmd;
  i = 0;
  printf("\033[0;34mCommande : %i, indice buffer : %i ", i, cur_cmd->indice_buf);
  printf("len %i , complet : %i", cur_cmd->len, cur_cmd->is_complet);
  printf("\033[0;m\n");
  while (cur_cmd->next != NULL)
    {
      printf("\033[0;34mCommande : %i, indice buffer : %i ", i, cur_cmd->indice_buf);
      printf("len %i , complet : %i", cur_cmd->len, cur_cmd->is_complet);
      printf("\033[0;m\n");
      i++;
      cur_cmd = cur_cmd->next;
    }
}
