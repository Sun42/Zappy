/*
** parse_options.c for parse_options in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:22:29 2009 yavuz yurdusev
** Last update Thu Apr 23 20:22:30 2009 yavuz yurdusev
*/

#include <stdlib.h>
#include <string.h>

#include "parse_options.h"
#include "server.h"

static const t_ptrfunc	gl_tabfunc[] =
  {
    {'p', set_port},
    {'x', set_width},
    {'y', set_height},
    {'c', set_max_client},
    {'t', set_speed},
    {'n', set_teams},
    {0, 0}
  };

void	set_port(int ac, char **av, t_world *world, int *i)
{
  world->port = atoi(av[*i]);
  if (world->port < 1)
    usage();
  while (*i < ac && av[*i][0] != '-')
    (*i)++;
}

void	usage(void)
{
  put_error("Usage :");
  put_error(USAGE);
  exit(EXIT_FAILURE);
}

static void	set_opt(int ac, char **av, int *i, t_world *world)
{
  int		z;

  z = 0;
  while (gl_tabfunc[z].option)
    {
      if (gl_tabfunc[z].option == av[*i][1])
	{
	  (*i)++;
	  gl_tabfunc[z].f(ac, av, world, i);
	  break;
	}
      z++;
    }
}

static int	check_opt(int ac, char **av)
{
  int		i;
  char		bool;

  i = 1;
  bool = 0;
  while (i < ac)
    {
      if (av[i][0] == '-')
	{
	  if (strlen(av[i]) != 2 || strstr(OPTIONS, &av[i][1]) == NULL)
	    return (0);
	  else
	    if ((ac -1) == i || (i + 1 != ac - 1 && av[i + 1][0] == '-'))
	      return (0);
	  if (av[i][1] == 'n')
	    bool = 1;
	}
      i++;
    }
  return ((bool) ? 1 : 0);
}

void	parse_option(int ac, char **av, t_world *world)
{
  int	i;

  if (ac >= MIN_ARGC && check_opt(ac, av))
    {
      create_world(world);
      i  = 1;
      while (i < ac)
	{
	  if (av[i][0] == '-')
	    set_opt(ac, av, &i, world);
	  else
	    i++;
	}
    }
  else
    usage();
}
