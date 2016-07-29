/*
** read_server.c for read_server in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:42:24 2009 yavuz yurdusev
** Last update Sun Apr 26 12:32:57 2009 yavuz yurdusev
*/

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_thread.h"
#include "struct_ptr_func.h"
#include "map.h"
#include "socket.h"
#include "command.h"
#include "buffer.h"

static	const	t_cmd_func gl_cmd_func[] =
  {
    {"msz", serv_msz, 3},
    {"bct", serv_bct, 10},
    {"tna", serv_tna, 2},
    {"pnw", serv_pnw, 7},
    {"ppo", serv_ppo, 5},
    {"pdi", serv_pdi, 2},
    {"pbc", serv_pbc, 0},
    {"pic", serv_pic, 0},
    {"pin", serv_pin, 11},
    {"enw", serv_enw, 5},
    {"eht", serv_eht, 2},
    {"edi", serv_edi, 2},
    {"pdr", serv_pdr, 3},
    {"pgt", serv_pgt, 3},
    {"pie", serv_pie, 4},
    {"plv", serv_plv, 3},
    {"ebo", serv_ebo, 2},
    {"seg", serv_seg, 2},
    {"pex", serv_pex, 2},
    {"BIENVENUE", serv_bvn, 1},
    {NULL, NULL, 0}
  };

void	read_command(t_on_screen *screen)
{
  char	*cmd;
  int	len;
  int	i;

  i = 0;
  if ((len = access_cmdlen(&(screen->my_msg), 'R')) > 0)
    cmd = access_cmd(&(screen->my_msg), 'R');
  else
    return ;
  while (gl_cmd_func[i].name_func != NULL)
    {
      if (cmd_cmp(cmd, gl_cmd_func[i].name_func))
	{
	  if ((i == 6 && get_argument(cmd, 2) == NULL) ||
	      (i == 7 && get_argument(cmd, 4) == NULL) ||
	      (gl_cmd_func[i].nb_arg &&
	       gl_cmd_func[i].nb_arg != get_nb_arg(cmd)))
	    break ;
	  gl_cmd_func[i].f(screen, cmd);
	}
      i++;
    }
  unsave_cmd(&(screen->my_msg), len, 'R');
}
