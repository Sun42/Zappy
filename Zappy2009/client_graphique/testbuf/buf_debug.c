#include <stdio.h>
#include "buffer.h"

/*
** debug only
*/
void	aff_buf(t_buf my_buf)
{
  int	i;

  i = 0;
  printf("\033[0;32mBuffer[0...%i], begin %i, end %i \n\033[0;m", BUF_SIZE - 1, my_buf.begin, my_buf.end);
  while (i < BUF_SIZE)
    {
      printf("\033[0;31m[%c]\033[0;m", my_buf.buf[i]);
      i++;
    }
  printf("\n");
}

/*
**debug only
*/
void	aff_cli(t_msg *my_msg)
{
  printf("Aff list cmd R: \n");
  aff_listcmd(my_msg->lcmdr);
  printf("Taille de la liste R: %i  \n", my_list_size(my_msg->lcmdr));
  printf("Buffr \n");
  aff_buf(my_msg->bufr);
  /*
  printf("Aff list cmdWR: \n");
  aff_listcmd(my_msg->lcmdw);
  printf("Taille de la liste W: %i  \n", my_list_size(my_msg->lcmdw));
  aff_buf(my_msg->bufw);
  */
}

/*
** debug only
*/
void	aff_listcmd(t_cmd *my_cmd)
{
  int	i;
  t_cmd	*cur_cmd;

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
  printf("\nIndice buffer : %i, ", my_cmd->indice_buf);
  printf("\nLen : %i , Complet : %i, ", my_cmd->len, my_cmd->is_complet);
  printf("\nCommande  :%s", my_cmd->cmd);
  printf("\nPTR Commande  :%p", my_cmd->cmd);
  printf("\nOctets sended %i", my_cmd->sended);
  printf("\nNext : %p", (void *)my_cmd->next);
  printf("\033[0;m\n\n");
}
