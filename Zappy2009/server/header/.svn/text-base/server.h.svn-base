/*
** server.h for server in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/header
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:21:03 2009 yavuz yurdusev
** Last update Fri Apr 24 11:02:32 2009 Tug
*/

#include "struct.h"

#ifndef SERVER_H_
# define SERVER_H_

	/* functions world */
void	create_world(t_world *);
void	init_map(t_world *);

	/* functions pcli */
t_pcli	*new_pcli(t_cli *);
void	add_pcli(t_pcli **, t_pcli *);
void	remove_pcli(t_pcli **, t_pcli *);

	/* func_client.c */
void	init_position(t_world *, t_cli *);
t_cli	*find_dead_cli(t_world *);
t_cli	*find_egg(t_world *, t_team *);

	/* func_create_cli.c */
void	create_all_clients(t_world *);
t_cli	*create_egg(t_world *, t_cli *);
void	connect_new_client(t_world *);

	/* func_gui.c */
void	set_gui(t_world *, t_cli *);
void	add_buffer_to_guis(t_pcli *, char *, int);

	/* func_ia.c */
void	set_ia_team(t_world *, t_cli *, char *);
t_cli	*get_ia(t_cli *, int);

	/* functions teams */
void	add_new_team(t_team **, char *);
int	get_nb_teams(t_team *, int);
void	print_teams_list(t_team *);

	/* fct xalloc */
void	*xmalloc(unsigned int);
void	*xrealloc(void *, unsigned int );

	/* functions time */
void	set_timeval(t_world *, struct timeval *, int);
int	timecmp(struct timeval *, struct timeval *);
void	setdifftime(struct timeval *, struct timeval *);
void	timeadd(t_world *, struct timeval *, int, struct timeval *);

	/* fct affichage */
void	my_putchar(const char);
void	print_nb(int);
void	put_error(const char *);
void	putstr(const char *);

	/* fct conversion int */
int	char_to_int(char *);
int	atio(int ,char *);

void	run_server(t_world *);
void	stop_server(t_world *);

void	gui_manager(t_world *, t_cli *, char *);

void	ia_manager(t_world *, t_cli *);
void	reinit_statut(t_world *, t_cli *);
void	select_action(t_world *, t_cli *, char *);

void	kill_ia(t_world *, t_cli *);
void	ultra_kill(t_world *, t_cli *);

void	init_inventaire(t_res *);
void	gen_ressource(t_world *);
void	move_ressource(t_world *, int , int );

	/* fct parsage argv */
void	parse_option(int, char **, t_world *);

#endif /* SERVER_H_ */

#ifndef NULL
# define NULL (void*)(0)
#endif /*! NULL !*/
