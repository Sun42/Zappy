/*
** func_team.c for func_team in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:30:28 2009 yavuz yurdusev
** Last update Thu Apr 23 20:30:29 2009 yavuz yurdusev
*/

#include "server.h"

void		add_new_team(t_team **teams, char *team_name)
{
  t_team	*new_team;

  if ((new_team = xmalloc(sizeof(*new_team))) != NULL)
    {
      new_team->name = team_name;
      new_team->nb_lvl_max = 0;
      new_team->next = (*teams);
      (*teams) = new_team;
    }
}

void	print_teams_list(t_team *teams)
{
  while (teams != NULL)
    {
      putstr("\n\t - ");
      putstr(teams->name);
      teams = teams->next;
    }
}

/*
** Donne le nb de teams et set le nb maximum de client pouvant se connecter
*/
int	get_nb_teams(t_team *teams, int max_client)
{
  int	sum;

  sum = 0;
  while (teams != NULL)
    {
      teams->nb_client = max_client;
      teams = teams->next;
      sum++;
    }
  return (sum);
}
