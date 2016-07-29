/*
** parse_options.h for parse_options in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/header
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:20:32 2009 yavuz yurdusev
** Last update Thu Apr 23 20:20:34 2009 yavuz yurdusev
*/

#include "server.h"

#ifndef PARSE_OPTIONS_H_
# define PARSE_OPTIONS_H_

# define MIN_ARGC	3

# define DEFAULT_PORT	42000
# define DEFAULT_SPEED	10000 /*(1000000 usec / 100 pers  */
# define DEFAULT_X	20
# define DEFAULT_Y	20
# define DEFAULT_MC	10

# define MAX_CLIENTS	100
# define OPTIONS	"pxyctn"
# define USAGE		" [-p PORT] [-x LARGEUR_MONDE > 0] [-y HAUTEUR_MONDE > 0] [-c NB_MAX_CLIENT] [-t DELAI] -n EQUIPE ...\n"

typedef struct s_ptrfunc
{
  char		option;
  void		(*f)(int, char **, t_world *, int *);
}		t_ptrfunc;

void	set_port(int, char **, t_world *, int *);
void	set_height(int, char **, t_world *, int *);
void	set_width(int, char **, t_world *, int *);
void	set_max_client(int, char **, t_world *, int *);
void	set_speed(int, char **, t_world *, int *);
void	set_teams(int, char **, t_world *, int *);
void	usage(void);

#endif /*! PARSE_OPTIONS_H_ !*/
