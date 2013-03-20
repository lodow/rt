/*
** my_mlx.c for mlx in /home/sinet_l//wolf
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri Jan  4 13:07:19 2013 luc sinet
** Last update Sat Jan 12 17:59:47 2013 luc sinet
*/

#include        "mlx_int.h"

int             mlx_key_hook2(t_win_list *win, int (*funct)(), void *param)
{
  win->hooks[KeyPress].hook = funct;
  win->hooks[KeyPress].param = param;
  win->hooks[KeyPress].mask = KeyPressMask;
}
