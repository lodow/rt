/*
** gere_expose.c for gere_expose in /home/remi/Projet/gen_map_rt
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed May 29 15:50:56 2013 remi
** Last update Sun Jun  9 12:10:31 2013 remi robert
*/

#include "my_func.h"

int	gere_expose(t_param *param)
{
  mlx_put_image_to_window(param->window.p, param->window.id,
			  param->image.img, 0, 0);
  draw_ui(param);
  if (param->click_menu == 1)
    {
      mlx_put_image_to_window(param->window.p, param->window.id,
			      param->panel_control.img, 165, 10);
      draw_conf(param);
    }
  return (0);
}
