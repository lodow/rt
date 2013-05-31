/*
** main_loop.c for main_loop in /home/remi/Projet/gen_map_rt
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed May 29 09:40:01 2013 remi
** Last update Fri May 31 11:11:23 2013 remi robert
*/

#include "my_func.h"

void	main_loop(t_param *param)
{
  draw_ui(param);
  mlx_put_image_to_window(param->window.p, param->window.id,
  			  param->image.img, 0, 0);
  mlx_expose_hook(param->window.id, gere_expose, param);
  mlx_key_hook(param->window.id, gere_keyboard, param);
  mlx_mouse_hook(param->window.id, gere_mouse, param);
  mlx_loop(param->window.p);
}
