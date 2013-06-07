/*
** detect_box.c for detect_box7 in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Jun  4 12:58:21 2013 remi robert
** Last update Fri Jun  7 19:38:20 2013 remi robert
*/

#include "my_func.h"

void	rempl_tab_cord(int *tab)
{
  tab[0] = 60;
  tab[1] = 100;
  tab[2] = 140;
  tab[3] = 180;
  tab[4] = 220;
  tab[5] = 260;
  tab[6] = 300;
  tab[7] = 340;
  tab[8] = 380;
  tab[9] = 420;
  tab[10] = 460;
  tab[11] = 500;
}

void	rempl_coord(t_param *param, int x, int y)
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
	  {
	    param->saisi.y = (tab[indice] + 30) - 10;
	    return ;
	  }
      return ;
    }
  while (++indice < 12)
    if (x >= 450 && x <= 600 &&
	y >= tab[indice] && y <= tab[indice] + 30)
      {
	param->saisi.y = (tab[indice] + 30) - 10;
	return ;
      }
}

void	get_type_saisie(t_param *param, int x, int y)
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
	  {
	    param->saisi.type = indice + 1;
	    return ;
	  }
      return ;
    }
  while (++indice < 12)
    if (x >= 450 && x <= 600 &&
	y >= tab[indice] && y <= tab[indice] + 30)
      {
	param->saisi.type = indice + 1;
	return ;
      }
}

void	detect_box(t_param *param, int x, int y)
{
  get_type_saisie(param, x, y);
  if (param->saisi.type != 0)
    {
      param->saisi.check = 1;
      param->saisi.x = 460;
      rempl_coord(param, x, y);
      erease_textbox(param, 450, param->saisi.y - 20);
      mlx_put_image_to_window(param->window.p, param->window.id,
			      param->write.img, 429, param->saisi.y - 20);
    }
  else
    param->saisi.check = 0;
}
