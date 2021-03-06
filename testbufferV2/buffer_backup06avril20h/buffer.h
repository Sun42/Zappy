#ifndef __H_BUF_H__
#define __H_BUF_H__
#define BUF_SIZE 10

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
  t_cmd         *listr;
  int           t_cur_cmd;
  struct s_cli  *next;
}               t_cli;


/*
**utils_buf.c
*/
void    init_buf(t_buf *my_buf);
int     my_strlenbuf(char *str);
int     get_len_extract(t_buf *my_buf);

/*
** add_buf.c
*/
int	add_buf(t_buf *my_buf, char *text);

/*
**debug_buf.c
*/
void	 aff_buf(t_buf *my_buf);
void	turn_my_buf(t_buf *my_buf, int indice, int len);
void	aff_cli(t_cli *my_cli);
void	aff_listcmd(t_cmd *my_cmd);


/*
**buf.c
*/
void    init_listcmd(t_cmd *my_cmd);
#endif /*__H_BUF_H__*/
