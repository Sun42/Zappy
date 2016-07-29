/*
** event.c for event in /u/all/yurdus_y/cu/rendu/c/Zappy2009/gui/src
** 
** Made by yavuz yurdusev
** Login   <yurdus_y@epitech.net>
** 
** Started on  Thu Apr 23 20:39:50 2009 yavuz yurdusev
** Last update Thu Apr 23 21:42:29 2009 yavuz yurdusev
*/

#include "map.h"
#include "event.h"
#include "socket.h"
#include "move_map.h"
#include "command.h"
#include "minimap.h"
#include "inventaire.h"

static const t_key_manage	gl_key_func[] =
  {
    {SDLK_UP, move_map},
    {SDLK_DOWN, move_map},
    {SDLK_RIGHT, move_map},
    {SDLK_LEFT, move_map},
    {SDLK_m, display_mini},
    {0, NULL}
  };

static int	key_manager(t_on_screen *screen)
{
  int		i;

  i = 0;
  while (gl_key_func[i].key != 0 && i != -1)
    {
      if (gl_key_func[i].key == screen->cmd)
        {
          screen->quit = gl_key_func[i].f(screen, i);
          i = -2;
        }
      i++;
    }
  if (i != -1)
    screen->quit = 1;
  return (0);
}

static int	check_pos(t_on_screen *screen,
			  SDL_Event *event,
			  t_cli *client)
{
  if (screen->world->client != NULL)
    if (screen->info_bag->bag == NULL)
      {
	if (click_perso(screen, client, event) == 1)
	  return (1);
      }
  return (0);
}

static void	on_mouse_click(t_on_screen *screen, SDL_Event *event)
{
  t_cli		*list_cli;

  if (event->button.button == SDL_BUTTON_LEFT &&
      !screen->info_bag->have_invent)
    {
      list_cli = screen->world->client;
      while (list_cli != NULL)
	{
	  if (check_pos(screen, event, list_cli))
	    break;
	  list_cli = list_cli->next;
	}
      screen->world->loading = 0;
    }
  else if (event->button.button == SDL_BUTTON_RIGHT)
    {
      if (screen->info_bag->have_invent)
	{
	  screen->info_bag->have_invent = 0;
	  screen->world->loading = 0;
	}
    }
}

int		manage_events(void *data)
{
  SDL_Event	event;
  t_on_screen	*screen;

  screen = (t_on_screen *)data;
  SDL_EnableKeyRepeat(10, 100);
  while (screen->quit)
    {
      if (SDL_PollEvent(&event) == 1)
	{
	  if (event.type == SDL_QUIT)
	    screen->quit = 0;
	  else if (event.type == SDL_MOUSEBUTTONUP)
	    on_mouse_click(screen, &event);
	  else
	    if (event.type == SDL_KEYDOWN)
	      {
		screen->cmd = event.key.keysym.sym;
		key_manager(screen);
		screen->world->loading = 0;
	      }
	}
      SDL_Delay(1);
    }
  return (1);
}

/*
** boucle principale evenement + select
*/
void		events(t_on_screen *screen, SDLNet_SocketSet *set)
{
  SDL_Thread	*thread;

  thread = NULL;
  screen->quit = 1;
  while (screen->quit)
    {
      do_select(screen, set);
      if (access_cmdlen(&(screen->my_msg), 'R') > 0)
	read_command(screen);
      if (thread == NULL && screen->world->loading != 2)
	thread = SDL_CreateThread(manage_events, (void *)screen);
      if (screen->world->loading == 0)
	refresh(screen);
    }
  SDL_KillThread(thread);
}
