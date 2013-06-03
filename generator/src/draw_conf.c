/*
** draw_conf.c for draw_conf in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jun  3 12:44:40 2013 remi robert
** Last update Mon Jun  3 12:45:24 2013 remi robert
*/

#include "my_func.h"

void	draw_conf(t_param *param)
{
  mlx_string_put(param->window.p, param->window.id, 450, 50,
		 0xFFFFFFFF, "conf z : ");
  mlx_put_image_to_window(param->window.p, param->window.id,
			  param->textbox.img, 450, 60);
}
