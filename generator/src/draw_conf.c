/*
** draw_conf.c for draw_conf in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jun  3 12:44:40 2013 remi robert
** Last update Wed Jun  5 13:15:26 2013 remi robert
*/

#include "my_func.h"

void	draw_conf_box(t_param *param, int x, int y, char *str)
{
  mlx_string_put(param->window.p, param->window.id, x - 150, y + 20,
		 0xFFFFFFFF, str);
  mlx_put_image_to_window(param->window.p, param->window.id,
			  param->textbox.img, x, y);
}

void	draw_conf(t_param *param)
{
  if (param->on_click != 11)
    {
      draw_conf_box(param, 450, 60, "conf z :");
      draw_conf_box(param, 450, 100, "color :");
      draw_conf_box(param, 450, 140, "angle :");
      draw_conf_box(param, 450, 180, "size :");
      return ;
    }
  draw_conf_box(param, 450, 60, "conf z :");
  draw_conf_box(param, 450, 100, "color :");
  draw_conf_box(param, 450, 140, "intensite :");
}
