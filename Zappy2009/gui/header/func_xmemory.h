/*
** func_xmemory.h for func_xmemory in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/header
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:28:08 2009 yavuz yurdusev
** Last update Sun Apr 26 12:23:49 2009 yavuz yurdusev
*/
#ifndef FUNC_XMEMORY_H_
# define FUNC_XMEMORY_H_

	/* fct xalloc */
void	*xmalloc(unsigned int);
void	*xrealloc(void *, unsigned int );
char	*my_strndup(char *s, size_t n);
void	free_gui(t_on_screen *screen);
void	gui_exit(t_on_screen *screen, const int type_exit);
void	free_map(t_on_screen *screen);
void	free_player(t_on_screen *screen);
void	free_ressources(t_on_screen *screen);
void	free_wood(t_on_screen *screen);
void	free_client(t_on_screen *screen);


# endif /* FUNC_XMEMORY_H_ */
