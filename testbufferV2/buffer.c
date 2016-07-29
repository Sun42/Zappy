#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <string.h>
#include "buffer.h"

char	*strdup(const char *s);
char *strndup(const char *s, size_t n);
void	pop_cmd(t_cli *my_cli);


void	add_cmd(t_cli *my_cli, char *str, int size, int is_complet);

int	main()
{
  t_cli	*my_cli;
  char	*cmd;
  t_cmd	*info;

  my_cli = malloc(sizeof(t_cli *));
  my_cli->bufr = malloc(sizeof(t_buf *));
  my_cli->lcmdr = malloc(sizeof(t_cmd *));
  my_cli->bufr->end = 0;
  init_buf(my_cli->bufr);
  my_cli->lcmdr = NULL;
  cmd = "cm";
  parse_cmd(my_cli, cmd, strlen(cmd));
  cmd = "d1ncmd2";
  parse_cmd(my_cli, cmd, strlen(cmd));
  cmd = "fin";
  parse_cmd(my_cli, cmd, strlen(cmd));
  /*
  init_cmd(info);
  set_cmd(my_cli->lcmdr, 10, info);
  */
  /*
  info = get_cmd(my_cli->lcmdr, 0);
  aff_cmd(info);
  */
  pop_cmd(my_cli);
  aff_cli(my_cli);
  return (0);
}

void	pop_cmd(t_cli *my_cli)
{
  int	icmd;
  t_cmd	*my_cmd;

  icmd = my_list_size(my_cli);
  my_cmd = get_cmd(my_cli, indice);
  /*remove_at*/
}

/*
** decoupe le buffer en commandes
*/
void	parse_cmd(t_cli *my_cli, char *str, int size)
{
  int	nbcmd;
  int	complete;
  int	taillecmd;
  int	sum;

  sum = 0;
  nbcmd = count_cmd(str, size, &complete);
  printf("Nombre de cmd %i, taille totale %i \n", nbcmd, size);
  if (!complete)
    printf("commande pas finie\n");
  while (nbcmd)
    {
      taillecmd = my_strlenbuf(str) + 1;
      printf("Taille de la cmd [%i] \n", taillecmd);
      if (nbcmd == 1 && !complete)
	{
	  printf("size[%i] - sum[%i] = [%i]\n", size, sum, (size - sum));
	  add_cmd(my_cli , str, size - sum, 0);
	}
      else
	add_cmd(my_cli, str, taillecmd, 1);
      str += taillecmd;
      sum += taillecmd;
      nbcmd--;
    }
}

/*
** recoit la commande decoupee
** et se charge de la placer correctement
** dans la liste des commandes
** faire un control list = 10 and indice 10 == is_complet 
*/
void	add_cmd(t_cli *my_cli, char *str, int size, int is_complet)
{
  int	indice;
  t_cmd *info;

  indice = get_icur_cmd(my_cli->lcmdr);
  if (indice == -1)
    {
      my_put_in_list(&(my_cli->lcmdr));
      indice = get_icur_cmd(my_cli->lcmdr);
    }
  info = get_cmd(my_cli->lcmdr, indice);
  if (is_new(info))
    {
      info->is_complet = is_complet;
      info->indice_buf = add_buf(my_cli, info, str, size);
      info->len = size;
    }
  else
    {
      info->is_complet = is_complet;
      /*printf ("\033[0;33mPas encore fait !\n\033[0;m");*/
      add_buf(my_cli, info, str, size); /* ici checker if ad buff = -1*/
      info->len += size;
    }
  printf("Indice de la commande a setter : %i", indice);
}

/*
int	main(int ac, char **av)
{
  t_buf	my_buf;

  init_buf(&my_buf);
  add_buf(&my_buf, "1n");
  aff_buf(&my_buf);
  add_buf(&my_buf, "2\n");
  aff_buf(&my_buf);
  add_buf(&my_buf, "3n");
  aff_buf(&my_buf);
  add_buf(&my_buf, "4n");
  aff_buf(&my_buf);
  add_buf(&my_buf, "5n");
  aff_buf(&my_buf);
  turn_my_buf(&my_buf, 4, 2);
  aff_buf(&my_buf);
  add_buf(&my_buf, "yn");
  aff_buf(&my_buf);
  turn_my_buf(&my_buf, 6, 2);
  aff_buf(&my_buf);
  turn_my_buf(&my_buf, 8, 2);
  aff_buf(&my_buf);
  return (0);
}
*/


/*
 * cas ou la commande nes tpas fini
 * cas ou la commande ne tiens pas sur le buffer
 * cas ou buffer plein
 * cas ou moitie de commande sur le buffer, seconde moitie sur le buffer malloce
 ** cas ou la moitie de la commande est en fin de buffer et lautre en debut => coriace celui la, gerer ca a lextraction, au pire mallocer
*/
