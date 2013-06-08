/*
** erease_textbox.c for erease_textbox in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri Jun  7 13:09:57 2013 remi robert
** Last update Sat Jun  8 19:32:58 2013 remi robert
*/

#include "my_func.h"

void	ecrase_wrong(t_param *param, int y)
{
  mlx_put_image_to_window(param->window.p, param->window.id,
			  param->cache.img, 375, y);
  mlx_put_image_to_window(param->window.p, param->window.id,
			  param->cache.img, 400, y);
}

void	erease_textbox(t_param *param, int x, int y)
{
  int	indice_y;
  int	indice_x;

  indice_y = y;
  ecrase_wrong(param, y);
  while (indice_y <= 30 + y)
    {
      indice_x = x;
      while (indice_x <= x + 150)
	{
	  mlx_pixel_put(param->window.p, param->window.id,
			indice_x, indice_y, 0xFFFFFF);
	  indice_x += 1;
	}
      indice_y += 1;
    }
}
