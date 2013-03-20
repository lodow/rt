/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include	"include.h"
#include	"mlx_int.h"

int	mlx_keypressed_hook(t_win_list *win, int (*funct)(), void *param)
{
  win->hooks[KeyPress].hook = funct;
  win->hooks[KeyPress].param = param;
  win->hooks[KeyPress].mask = KeyPressMask;
  return (0);
}

int	pressed_key(int key, void *param)
{
  int	*tab;

  tab = param;
  tab[key] = 1;
  return (0);
}

int	realesed_key(int key, void *param)
{
  int	*tab;

  tab = param;
  if (key != ESC)
    tab[key] = 0;
  return (0);
}
