/*
** serv_connexion.h for serv_connexion in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/header
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:20:51 2009 yavuz yurdusev
** Last update Thu Apr 23 20:20:52 2009 yavuz yurdusev
*/

#include <sys/select.h>

#include "server.h"

#ifndef SERV_CONNEXION_H_
# define SERV_CONNEXION_H_

/* generale */
int	init_connexion(int);
int	new_connexion(int);
void	read_client(t_world *, t_cli *);
void	write_client(t_world *, t_cli *);

/* init select */
t_cli	*init_select(t_world *, fd_set [], int *, struct timeval *);

/* select read write */
void	select_read_write(fd_set [], t_world *, int );

#endif /* SERV_CONNEXION_H_ */
