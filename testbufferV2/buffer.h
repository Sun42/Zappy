#ifndef __H_BUF_H__
#define __H_BUF_H__
#define BUF_SIZE 10
#define ENDCMD 'n'
#define FREED '0'

typedef struct  s_buff
{
  char  buf[BUF_SIZE];
  int   begin;
  int   end;
} t_buf;

typedef struct  s_cmd
{
  struct s_cmd  *next;
  char          *cmd;
  int           timeval;
  int           indice_buf;
  int           len;
  char          is_complet;
}               t_cmd;

typedef struct   s_cli
{
  t_buf         *bufr;
  t_cmd         *lcmdr;
  int           t_cur_cmd;
  struct s_cli  *next;
}               t_cli;


/*
**utils_buf.c
*/
void	init_buf(t_buf *my_buf);
int	my_strlenbuf(char *str);
int	get_len_extract(t_buf *my_buf);
int	count_cmd(char *str, int size, int *complete);
void	bufncpy(char *dest, char bufr[], int begin , int n);
void    bufmemset(char bufr[], int begin, int len, char set);

/*
** add_buf.c
*/
int	add_buf(t_cli *my_cli,t_cmd *my_cmd ,char *text, int len);

/*
**debug_buf.c
*/
void	 aff_buf(t_buf *my_buf);
void	turn_my_buf(t_buf *my_buf, int indice, int len);
void	aff_cli(t_cli *my_cli);
void	aff_listcmd(t_cmd *my_cmd);
void	aff_cmd(t_cmd *my_cmd);

/*
**list_cmd
*/
int     my_put_in_list(t_cmd **begin);
int	my_list_size(t_cmd *begin);
void	init_cmd(t_cmd *my_cmd);
int	get_icur_cmd(t_cmd *my_cmd);
void	set_cmd(t_cmd * my_cmd, int indice, t_cmd *info);
t_cmd	*get_cmd(t_cmd *my_cmd, int indice);
int	is_new(t_cmd *my_cmd);
int	is_onbuf(t_cmd *my_cmd);

/*
**buf.c
*/

void	parse_cmd(t_cli *my_cli, char *str, int size);

#endif /*__H_BUF_H__*/
