#include <stdio.h>
#include "buffer.h"

/*
** debug only
*/
void    aff_buf(t_buf *my_buf)
{
  int   i;

  i = 0;
  printf("\033[0;32mBuffer[0...%i], begin %i, end %i \n\033[0;m", BUF_SIZE - 1, my_buf->begin, my_buf->end);
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
      my_buf->buf[indice] = FREED;
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
  printf("Aff list cmd : \n");
  aff_listcmd(my_cli->lcmdr);
  printf("Taille de la liste : %i  \n", my_list_size(my_cli->lcmdr));
  aff_buf(my_cli->bufr);
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
  
  while (cur_cmd != NULL)
    {
      printf("\033[0;35mCommande : %i\n", i);
      aff_cmd(cur_cmd);
      i++;
      cur_cmd = cur_cmd->next;
    }
}

void	aff_cmd(t_cmd *my_cmd)
{
  printf("Indice buffer : %i, ", my_cmd->indice_buf);
  printf("Len : %i , Complet : %i, ", my_cmd->len, my_cmd->is_complet);
  printf("Commande  :%s", my_cmd->cmd);
  printf("\033[0;m\n\n");
}
