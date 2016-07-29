/*
** ia_voir.c for ia_voir in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:23:03 2009 yavuz yurdusev
** Last update Sat Apr 25 21:24:59 2009 yavuz yurdusev
*/

#include "ia_command.h"

static void	alter_position(int *xy, int max)
{
  if (*xy < 0)
    *xy += max;
  else
    if (*xy >= max)
      *xy -= max;
  if (*xy < 0 || *xy >= max)
    alter_position(xy, max);
 }

static void	check_position(t_world *world, int *y, int *x, char direction)
{
  if (direction % 2)
    alter_position(x, world->width);
  else
    alter_position(y, world->height);
}

/*
** Quand on arrive en fin de lvl on incremente ou decremente de incr case
*/
static void	select_incr(t_world *world, t_card *pos, int incr)
{
  pos->x += (pos->direction % 2) ?
    (pos->direction == NORD) ? -incr : incr  :
    (pos->direction == EST) ? 1 : -1 ;
  pos->y += (pos->direction % 2) ?
    (pos->direction == NORD) ? -1 : 1 :
    (pos->direction == EST) ? -incr : incr;
  check_position(world, &(pos->y), &(pos->x), (pos->direction % 2) ?
		 OUEST : NORD);
}

/*
** Boucle sur une rangee
*/
static void	look_rank(t_world *world, t_card *pos, int nb_case, t_cli *ia)
{
  int		k;

  k = 0;
  while (k < nb_case)
    {
      if (nb_case != 1 || k)
	save_cmd(ia, MSG_INTER_VOIR, LEN_INTER_VOIR, 'W');
      check_position(world, &(pos->y), &(pos->x), pos->direction);
      ia_print_content_case(&(world->map[pos->y][pos->x]), ia);
      if (pos->direction % 2)
	pos->x += (pos->direction == NORD) ? 1 : -1;
      else
	pos->y += (pos->direction == OUEST) ? -1 : 1;
      k++;
    }
}

void		ia_voir(t_world *world, t_cli *ia)
{
  int		i;
  t_card	pos;
  int		nb_case;

  putstr("\033[33mClient numero : ");
  print_nb(ia->numero);
  putstr(" voir\n\033[39m");
  pos.y = ia->pos.y;
  pos.x = ia->pos.x;
  pos.direction = ia->pos.direction;
  save_cmd(ia, MSG_DEB_VOIR, LEN_DEB_VOIR, 'W');
  i = 0;
  nb_case = 1;
  while (i <= ia->lvl)
    {
      look_rank(world, &pos, nb_case, ia);
      select_incr(world, &pos, nb_case + 1);
      nb_case += CASE_PER_LEVEL;
      i++;
    }
  save_cmd(ia, MSG_FIN_VOIR, LEN_FIN_VOIR, 'W');
}
