/*
** cmd_access.c for cmd_access in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:34:31 2009 yavuz yurdusev
** Last update Thu Apr 23 20:34:32 2009 yavuz yurdusev
*/

#include "buffer.h"

/*
** check si place dispo dans le buffer
*/
static int	check_integrity(char *buf, int ibuf, int len)
{
  int		cpt;

  cpt = 0;
  while (len && ((ibuf + cpt) < BUF_SIZE) && (buf[ibuf + cpt] != FREED))
    cpt++;
  return (cpt);
}

/*
** return ptr sur la commande
*/
static char	*access_cmd2(t_cmd *my_list, t_buf *buf)
{
  int		ifirst;
  t_cmd		*my_cmd;
  char		*cmd;
  char		*buffer;

  buffer = buf->buf;
  ifirst = my_list_size(my_list) - 1;
  my_cmd = get_cmd(my_list, ifirst);
  cmd = my_cmd->cmd;
  if (!my_cmd->is_complet)
    return (NULL);
  if (my_cmd->cmd != NULL)
    return (cmd + my_cmd->sended);
  else if (my_cmd->indice_buf != -1)
    return ((char *)(buffer + my_cmd->indice_buf));
  return (NULL);
}

/*
** return la taille de la cmd
*/
static int	access_cmdlen2(t_cmd *my_list, t_buf *buf)
{
  int		ifirst;
  t_cmd		*my_cmd;

  ifirst = my_list_size(my_list) - 1;
  my_cmd = get_cmd(my_list, ifirst);
  if (!my_cmd->is_complet)
    return (-1);
  if (my_cmd->cmd != NULL)
    return (my_cmd->len - my_cmd->sended);
  else if (my_cmd->indice_buf != -1)
   {
     if ((my_cmd->indice_buf + my_cmd->len) < BUF_SIZE)
       return (my_cmd->len);
     else
       return (check_integrity(buf->buf, my_cmd->indice_buf, my_cmd->len));
   }
  return (-1);
}

/*
** entry point get une cmd en R / W
** R / W
*/
char	*access_cmd(t_cli *my_cli, char mode)
{
  if (mode == 'R')
    return (access_cmd2(my_cli->lcmdr, &(my_cli->bufr)));
  if (mode == 'W')
    return (access_cmd2(my_cli->lcmdw, &(my_cli->bufw)));
  return (NULL);
}

/*
** retourne la taille dispo pour la cmd courante
*/
int	access_cmdlen(t_cli *my_cli, char mode)
{
  if (mode == 'R')
    return (access_cmdlen2(my_cli->lcmdr, &(my_cli->bufr)));
  if (mode == 'W')
    return (access_cmdlen2(my_cli->lcmdw, &(my_cli->bufw)));
  return (-1);
}
