/*
** buffer.h for buffer in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/header
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:24:08 2009 yavuz yurdusev
** Last update Thu Apr 23 20:24:09 2009 yavuz yurdusev
*/

#ifndef BUFFER_H_
# define BUFFER_H_

/*
** buffer.h
*/
typedef struct	s_buff
{
  char		buf[BUF_SIZE];
  int		begin;
  int		end;
}		t_buf;

typedef struct	s_cmd
{
  struct s_cmd	*next;
  char		*cmd;
  int		indice_buf;
  int		len;
  char		is_complet;
  int		sended;
}		t_cmd;

typedef	struct	s_msg
{
  t_buf		bufr;
  t_cmd		*lcmdr;
  t_buf		bufw;
  t_cmd		*lcmdw;
}		t_msg;

/*
** buf_init.c
*/
void	init_buf_msg(t_msg *my_msg);

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
int	add_bufr(t_msg *my_msg,t_cmd *my_cmd ,char *text, int len);
int	add_bufw(t_msg *my_msg,t_cmd *my_cmd ,char *text, int len);

/*
** buf_add_overflow
*/
int	add_overflow_r(t_msg *my_msg, t_cmd *my_cmd, char *text, int len);
int	add_overflow_w(t_msg *my_msg, t_cmd *my_cmd, char *text, int len);
int	add_overflow_old(t_cmd *my_cmd, char *text, int len);
/*
** buf_add_onbuf
*/
int	can_add_endbuf(t_buf *my_buf, int len);
int	can_add_begbuf(t_buf *my_buf, int len);
int	add_endbuf(t_buf *my_buf, char *text, int len);
int	add_begbuf(t_buf *my_buf, char *text, int len);

/*
** buf_debug.c
*/
void	aff_buf(t_buf my_buf);
void	aff_cli(t_msg *my_msg);
void	aff_listcmd(t_cmd *my_cmd);
void	aff_cmd(t_cmd *my_cmd);

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
char	*access_cmd(t_msg *my_msg, char mode);
int	access_cmdlen(t_msg *my_msg, char mode);

/*
** unsave_cmd.c
*/
void	unsave_cmd(t_msg *my_msg, int len, char mode);
void	remove_cmd(t_cmd **my_list, int indice);

/*
** cmd_save.c
*/
void	save_cmd(t_msg *my_msg, char *str, int size, char mode);
void	add_cmdr(t_msg *my_msg, char *str, int size, int is_complet);
void	add_cmdw(t_msg *my_msg, char *str, int size, int is_complet);

#endif /* BUFFER_H_ */

#ifndef NULL
# define NULL (void*)(0)
#endif /*! NULL !*/
