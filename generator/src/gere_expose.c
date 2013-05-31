/*
** gere_expose.c for gere_expose in /home/remi/Projet/gen_map_rt
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed May 29 15:50:56 2013 remi
** Last update Fri May 31 11:12:55 2013 remi robert
*/

#include "my_func.h"

int	gere_expose(t_param *param)
{
  mlx_put_image_to_window(param->window.p, param->window.id,
			  param->image.img, 0, 0);
  draw_ui(param);
  return (0);
}
