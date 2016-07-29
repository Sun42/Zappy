#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "buffer.h"


int	main(int ac, char **av)
{
  char	*cmd;
  t_msg	*my_msg;
  int	len;

  my_msg = malloc(sizeof(t_msg));
  init_buf_msg(my_msg);
  aff_cli(my_msg);
  cmd = strdup("jesuisunechainede20char\n");
  len = strlen(cmd);
  while (len > 2)
    {
      cmd[len - 1] = '\n';
      save_cmd(my_msg, cmd, len, 'R');
      aff_cli(my_msg);
      unsave_cmd(my_msg, len, 'R');
      len--;
      
    }
  return (0);
}
