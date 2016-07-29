/*
** ia_voir_content.c for ia_voir_content in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:22:54 2009 yavuz yurdusev
** Last update Sat Apr 25 15:41:17 2009 yavuz yurdusev
*/

#include <string.h>

#include "ia_command.h"

static void	print_ressource(int num_objet, int quantite, t_cli *ia)
{
  char		*name_objet;
  int		len;

  name_objet = get_name_objet(num_objet, &len);
  while (quantite--)
    {
      save_cmd(ia, MSG_SEP, LEN_SEP, 'W');
      save_cmd(ia, name_objet, len, 'W');
    }
}

void	ia_print_content_case(t_res *caz, t_cli *ia)
{
  int	i;

  print_ressource(PLAYER, caz->nb_joueur, ia);
  i = -1;
  while (++i < NB_OBJETS)
    print_ressource(i, caz->objet[i], ia);
}
