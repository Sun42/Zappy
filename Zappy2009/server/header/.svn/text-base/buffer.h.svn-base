/*
** buffer.h for buffer in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/header
**
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
**
** Started on  Thu Apr 23 20:18:54 2009 yavuz yurdusev
** Last update Thu Apr 23 20:19:02 2009 yavuz yurdusev
*/

#include "server.h"

#ifndef BUFFER_H_
# define BUFFER_H_

/*
** buf_init.c
*/
void	init_buf_cli(t_cli *my_cli);
void	reinit_buf_cli(t_cli *my_cli);

/*
** buf_utils.c
*/
void	init_buf(t_buf *my_buf);
int	my_strlenbuf(char *str);
int	get_len_extract(t_buf *my_buf);
void	bufncpy(char *dest, char bufr[], int begin , int n);
void	bufmemset(char bufr[], int begin, int len, char set);

/*
** buf_utils2.c
*/
void	rewind_buf(t_buf *my_buf);
void	turn_my_buf(t_buf *my_buf, int indice, int len);

/*
** buf_add.c
*/
int	add_bufr(t_cli *my_cli,t_cmd *my_cmd ,char *text, int len);
int	add_bufw(t_cli *my_cli,t_cmd *my_cmd ,char *text, int len);


/*
** cmd_access.c
*/
char	*access_cmd(t_cli *my_cli, char mode);
int	access_cmdlen(t_cli *my_cli, char mode);

/*
** cmd_save.c
*/
void	save_cmd(t_cli *my_cli, char *str, int size, char mode);
void	add_cmdr(t_cli *my_cli, char *str, int size, int is_complet);
void	add_cmdw(t_cli *my_cli, char *str, int size, int is_complet);

/*
** cmd_save2.c
*/
int	get_indice_r(t_cli *my_cli);
int	get_indice_w(t_cli *my_cli);

/*
** buf_add_overflow
*/
int	add_overflow_r(t_cli *my_cli, t_cmd *my_cmd, char *text, int len);
int	add_overflow_w(t_cli *my_cli, t_cmd *my_cmd, char *text, int len);
int	add_overflow_old(t_cmd *my_cmd, char *text, int len);
/*
** buf_add_onbuf
*/
int	can_add_endbuf(t_buf *my_buf, int len);
int	can_add_begbuf(t_buf *my_buf, int len);
int	add_endbuf(t_buf *my_buf, char *text, int len);
int	add_begbuf(t_buf *my_buf, char *text, int len);

/*
** utils_cmdlist.c
*/
int	my_put_in_list(t_cmd **begin);
int	my_list_size(t_cmd *begin);
t_cmd	*get_cmd(t_cmd *my_cmd, int indice);
int	get_icur_cmd(t_cmd *my_cmd);
void	free_allcmd(t_cmd *my_cmd);

/*
** cmd_list2.c
*/
int	list_full(t_cmd *my_list);
int	count_cmd(char *str, int size, int *complete);

/*
** cmd_list.c
*/
void	free_cmd(t_cmd *my_cmd);
int	is_new(t_cmd *my_cmd);
int	is_onbuf(t_cmd *my_cmd);
void	init_cmd(t_cmd *my_cmd);

/*
** cmd_access.c
*/
char	*access_cmd(t_cli *my_cli, char mode);
int	access_cmdlen(t_cli *my_cli, char mode);

/*
** unsave_cmd.c
*/
void	unsave_cmd(t_cli *my_cli, int len, char mode);
void	remove_cmd(t_cmd **my_list, int indice);

#endif /* BUFFER_H_*/
