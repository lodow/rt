/*
** draw_conf.c for draw_conf in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jun  3 12:44:40 2013 remi robert
** Last update Thu Jun  6 13:26:08 2013 remi
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
      draw_conf_box(param, 450, 60, "Coord z :");
      draw_conf_box(param, 450, 100, "Color :");
      draw_conf_box(param, 450, 140, "Angle :");
      draw_conf_box(param, 450, 180, "Size :");
      draw_conf_box(param, 450, 220, "Alpha :");
      draw_conf_box(param, 450, 260, "Brightness :");
      draw_conf_box(param, 450, 300, "Bump mapping :");
      draw_conf_box(param, 450, 340, "Perlin :");
      draw_conf_box(param, 450, 380, "Reflexion :");
      draw_conf_box(param, 450, 420, "Normal :");
      draw_conf_box(param, 450, 460, "Checker :");
      draw_conf_box(param, 450, 500, "N :");
      return ;
    }
  draw_conf_box(param, 450, 60, "Coord z :");
  draw_conf_box(param, 450, 100, "Color :");
  draw_conf_box(param, 450, 140, "Intensite :");
}
