#include <stdlib.h>
#include "buffer.h"

/*
** initialise les infos d'une commande par defaut
*/
void	init_cmd(t_cmd **my_cmd)
{
  (*my_cmd)->indice_buf = -1;
  (*my_cmd)->len = -1;
  (*my_cmd)->cmd = NULL;
  (*my_cmd)->is_complet = 0;
  (*my_cmd)->sended = 0;
}

int	is_new(t_cmd *my_cmd)
{
  if (my_cmd->len == -1)
    return (1);
  return (0);
}

int	is_onbuf(t_cmd *my_cmd)
{
  if ((my_cmd->indice_buf == -1))
    return (0);
  return (1);
}

void	free_cmd(t_cmd *my_cmd)
{
  if (my_cmd->cmd != NULL)
    free(my_cmd->cmd);
  free(my_cmd);
}
