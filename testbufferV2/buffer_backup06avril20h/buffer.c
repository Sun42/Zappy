#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include "buffer.h"



void	init_listcmd(t_cmd *my_cmd)
{
  my_cmd->timeval = -1;
  my_cmd->indice_buf = -1;
  my_cmd->len = -1;
  my_cmd->cmd = NULL;
  my_cmd->is_complet = 0;
  my_cmd->next = NULL;
}


int	main()
{
  t_cli	*my_cli;

  my_cli = malloc(sizeof(t_cli *));
  my_cli->bufr = malloc(sizeof(t_buf *));
  my_cli->listr = malloc(sizeof(t_cmd *));
  my_cli->bufr->end = 0;
  init_buf(my_cli->bufr);
  init_listcmd(my_cli->listr);
  add_buf(my_cli, "1n");
  aff_cli(my_cli);
  return (0);
}

/*
int	main(int ac, char **av)
{
  t_buf	my_buf;

  init_buf(&my_buf);
  add_buf(&my_buf, "1n");
  aff_buf(&my_buf);
  add_buf(&my_buf, "2n");
  aff_buf(&my_buf);
  add_buf(&my_buf, "3n");
  aff_buf(&my_buf);
  add_buf(&my_buf, "4n");
  aff_buf(&my_buf);
  add_buf(&my_buf, "5n");
  aff_buf(&my_buf);
  turn_my_buf(&my_buf, 4, 2);
  aff_buf(&my_buf);
  add_buf(&my_buf, "yn");
  aff_buf(&my_buf);
 turn_my_buf(&my_buf, 6, 2);
  aff_buf(&my_buf);
  turn_my_buf(&my_buf, 8, 2);
  aff_buf(&my_buf);
  return (0);
}
*/
