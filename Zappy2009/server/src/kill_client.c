/*
** kill_client.c for kill_client in /u/all/yurdus_y/cu/rendu/c/Zappy2009/server/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:22:44 2009 yavuz yurdusev
** Last update Sat Apr 25 12:07:03 2009 yavuz yurdusev
*/

#include <stdio.h>
#include <unistd.h>

#include "buffer.h"
#include "ia_command.h"

static void	kill_ia_bis(t_world *world, t_cli *cli)
{
  remove_pcli(&(world->map[cli->pos.y][cli->pos.x].pcli), cli->pcli);
  world->map[cli->pos.y][cli->pos.x].nb_joueur -= 1;
  world->map[cli->pos.y][cli->pos.x].elevation = 0;
}

void	kill_ia(t_world *world, t_cli *cli)
{
  if (cli->elevation && world->pgui != NULL)
    gui_pie(world, cli->pos.y, cli->pos.x, '0');
  if (cli->statut != ACTION && cli->statut != NOACTION && cli->statut != GHOST)
    {
      putstr("Erreur: kill_ia(): Mauvais statut client\n");
      return ;
    }
  kill_ia_bis(world, cli);
  cli->team->nb_client++;
  if (cli->lvl == LVL_MAX)
    cli->team->nb_lvl_max--;
  if (cli->statut == GHOST)
    {
      if (world->pgui != NULL)
	gui_edi(world, cli->numero);
      cli->statut = DEAD;
      reinit_buf_cli(cli);
    }
  else
    {
      if (world->pgui != NULL)
      	gui_pdi(world, cli->numero);
      cli->statut = WILL_DIE;
      save_cmd(cli, MSG_MORT, LEN_MORT, 'W');
    }
}

void	ultra_kill(t_world *world, t_cli *cli)
{
  reinit_buf_cli(cli);
  if (cli->statut == ACTION || cli->statut == NOACTION || cli->statut == GHOST)
    kill_ia(world, cli);
  else if (cli->statut == GUI)
    remove_pcli(&(world->pgui), cli->pcli);
  if (cli->sock > 0)
    if (close(cli->sock) == -1)
      perror("Erreur: close() --> ultra_kill()");
  cli->sock = DEAD;
  cli->statut = DEAD;
  putstr("\033[31mClient Numero : ");
  print_nb(cli->numero);
  putstr(" has left the server\n\033[39m");
}
