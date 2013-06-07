/*
** get_new_type.c for get_new_type in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri Jun  7 11:15:52 2013 remi robert
** Last update Fri Jun  7 19:33:38 2013 remi robert
*/

#include "my_func.h"

int	get_new_type(t_param *param, int x, int y)
{
  int	tab[12];
  int	indice;

  rempl_tab_cord(tab);
  indice = -1;
  if (param->on_click == 11)
    {
      while (++indice < 3)
	if (x >= 450 && x <= 600 &&
	    y >= tab[indice] && y <= tab[indice] + 30)
	  return (indice + 1);
      return (param->saisi.type);
    }
  while (++indice < 12)
    if (x >= 450 && x <= 600 &&
	y >= tab[indice] && y <= tab[indice] + 30)
      return (indice + 1);
  return (param->saisi.type);
}
