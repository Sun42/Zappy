/*
** broadcast.h for broadcast in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/header
**
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
**
** Started on  Thu Apr 23 20:15:18 2009 yavuz yurdusev
** Last update Thu Apr 23 20:18:40 2009 yavuz yurdusev
*/

#include "struct.h"

#ifndef BROADCAST_H_
# define BROADCAST_H_

/*
** broadcast_func
*/
void	add_direction(t_broadcast *broadcast);
void	get_angle(t_broadcast *broadcast);
int	calc_fastpath(int max, int p1, int p2);
int	calc_case_reception(t_broadcast *broadcast);
int	same_case(t_broadcast *broadcast);

/*
** broadcast_func2.c
*/
int	is_placed(t_card *caze, t_card joueur);

/*
** broadcast_calc1.c
*/
int	calc_xdown_yup(t_broadcast *broadcast);
int	calc_xup_yup(t_broadcast *broadcast);
int	calc_xup_ydown(t_broadcast *broadcast);
int	calc_xdown_ydown(t_broadcast *broadcast);
int	vertical(t_broadcast *broadcast);

/*
** broadcast_calc2.c
*/
int	calc_j2sup(t_broadcast *broadcast);
int	calc_j2ysup(t_broadcast *broadcast);
int	calc_j2inf(t_broadcast *broadcast);
int	calc_j2xsup(t_broadcast *broadcast);
int	horizontal(t_broadcast *broadcast);

# endif /*! BROADCAST_H_ !*/
