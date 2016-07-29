/*
** gui_manager.c for gui_manager in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:29:26 2009 yavuz yurdusev
** Last update Thu Apr 23 20:29:27 2009 yavuz yurdusev
*/

#include "buffer.h"
#include "gui_command.h"
#include "ia_command.h"

/* trie par odre du plus utilise au moins */
static const t_cmd_funcg	gl_cmd_func[] =
  {
    {"msz", gui_msz, 1},
    {"bct", gui_bct, 3},
    {"mct", gui_mct, 1},
    {"tna", gui_tna, 1},
    {"ppo", gui_ppo, 2},
    {"plv", gui_plv, 2},
    {"pin", gui_pin, 2},
    {"sgt", gui_sgt, 1},
    {NULL, NULL, 0}
  };

void	gui_manager(t_world *world, t_cli *gui, char *cmd)
{
  int	i;

  i = 0;
  while (gl_cmd_func[i].name_func != NULL)
    {
      if (cmd_cmp(cmd, gl_cmd_func[i].name_func))
	{
	  if (gl_cmd_func[i].nb_arg != get_nb_arg(cmd))
	    save_cmd(gui, GUI_SBP, GUI_SBPL, 'W');
	  else
	    gl_cmd_func[i].f(world, gui, cmd);
	  return ;
	}
      i++;
    }
  save_cmd(gui, GUI_SUC, GUI_SUCL, 'W');
}
