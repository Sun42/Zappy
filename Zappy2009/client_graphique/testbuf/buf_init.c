#include <stdlib.h>
#include "buffer.h"

void	init_buf_msg(t_msg *my_msg)
{
  if ((my_msg->lcmdr = malloc(sizeof(*my_msg->lcmdr))) == NULL)
    return ;
  if ((my_msg->lcmdw = malloc(sizeof(*my_msg->lcmdw))) == NULL)
    return ;
  init_buf(&(my_msg->bufr));
  init_cmd(&(my_msg->lcmdr));
  my_msg->lcmdr->next = NULL;
  init_buf(&(my_msg->bufw));
  init_cmd(&(my_msg->lcmdw));
  my_msg->lcmdw->next = NULL;
}
