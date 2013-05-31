/*
** init_window.c for init_window in /home/remi/Projet/gen_map_rt
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed May 29 08:51:46 2013 remi
** Last update Fri May 31 16:45:59 2013 remi robert
*/

#include "my_func.h"

void    init_img(t_param *param)
{
  param->image.size_line = param->window.x * 4;
  param->image.bbp = 4;
  param->image.endian = 1;
  param->image.img = mlx_new_image(param->window.p,
				   param->window.x, param->window.y);
  param->image.tab = mlx_get_data_addr(param->image.img,
				       &(param->image.bbp),
				       &(param->image.size_line),
				       &(param->image.endian));
}

int	init_window(t_param *param)
{
  if ((param->window.p = mlx_init()) == NULL ||
      (param->window.id = mlx_new_window(param->window.p, X,
					 Y, "generator rt")) == NULL)
    return (0);
  param->window.x = X;
  param->window.y = Y;
  param->phead = NULL;
  param->on_click = NOTHING;
  param->click_menu = 0;
  init_img(param);
  if (init_texture(param) == 0)
    return (0);
  return (1);
}
