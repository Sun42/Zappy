/*
** func_gui.c for func_gui in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:32:33 2009 yavuz yurdusev
** Last update Fri Apr 24 20:03:45 2009 yavuz yurdusev
*/

#include <string.h>

#include "buffer.h"
#include "gui_send.h"
#include "gui_command.h"

void		add_buffer_to_guis(t_pcli *list_gui, char *msg, int len_msg)
{
  t_pcli	*list_guis;

  list_guis = list_gui;
  while (list_guis != NULL)
    {
      save_cmd(list_guis->lcli, msg, len_msg, 'W');
      list_guis = list_guis->next;
    }
}

static void	welcome_protocol(t_world *world, t_cli *gui)
{
  t_cli		*list_ia;

  gui_msz(world, gui, "");
  gui_sgt(world, gui, "");
  gui_mct(world, gui, "");
  gui_tna(world, gui, "");
  list_ia = world->client;
  while (list_ia != NULL)
    {
      if (list_ia->statut != GUI && list_ia->statut != DEAD
	  && list_ia->statut != NOTEAM)
	{
	  if (list_ia->statut == EGG)
	    gui_enw(gui, list_ia, 0);
	  else
	    gui_pnw(gui, list_ia);
	  gui_pin_bis(world, gui, list_ia);
	}
      list_ia = list_ia->next;
    }
}

void	set_gui(t_world *world, t_cli *gui)
{
  gui->statut = GUI;
  add_pcli(&(world->pgui), gui->pcli);
  welcome_protocol(world, gui);
  putstr("\033[36mNew gui connected on socket :");
  print_nb(gui->sock);
  putstr("\033[39m\n");
}
