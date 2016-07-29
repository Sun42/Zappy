/*
** serv_cmd.c for serv_cmd in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:42:00 2009 yavuz yurdusev
** Last update Thu Apr 23 20:42:02 2009 yavuz yurdusev
*/

#include <string.h>

#include "define.h"
#include "command.h"

int	strlen_cmd(const char *cmd)
{
  int	i;

  i = 0;
  while (!END_STR(cmd[i]) && cmd[i] != ' ')
    i++;
  return (i);
}

char	cmd_cmp(const char *cmd, const char *ref)
{
  int	i;

  i = 0;
  while (!END_STR(cmd[i]) && cmd[i] != ' ' && !END_STR(ref[i]))
    {
      if (cmd[i] != ref[i])
	return (0);
      i++;
    }
  return (((int)strlen_cmd(cmd) == i && (int)strlen(ref) == i) ? 1 : 0);
}

char	*get_argument(char *buffer, int num_arg)
{
  int	i;
  int	cpt;
  char	bool;

  i = 0;
  cpt = 0;
  bool = 1;
  while (!END_STR(buffer[i]))
    {
      if (buffer[i] == ' ' || buffer[i] == '\t')
	bool = 1;
      else
	{
	  if (bool)
	    {
	      ++cpt;
	      if (cpt == num_arg)
		return (buffer + i);
	    }
	  bool = 0;
	}
      i++;
    }
  return (NULL);
}

int	get_nb_arg(const char *cmd)
{
  int	i;
  int	cpt;
  char	bool;

  i = 0;
  cpt = 0;
  bool = 1;
  while (!END_STR(cmd[i]))
    {
      if (cmd[i] == ' ' || cmd[i] == '\t')
	bool = 1;
      else
	{
	  if (bool)
	    cpt++;
	  bool = 0;
	}
      i++;
    }
  return (cpt);
}

int	is_valid_case(int x, int y, t_on_screen *screen)
{
  if (VALID_CAZE(x, screen->world->width))
    if (VALID_CAZE(y, screen->world->height))
      return (1);
  return (0);
}
