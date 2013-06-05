/*
** detect_box.c for detect_box7 in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Jun  4 12:58:21 2013 remi robert
** Last update Wed Jun  5 13:14:10 2013 remi robert
*/

#include "my_func.h"

void	rempl_coord(t_param *param, int x, int y)
{
  param->saisi.check = 1;
  param->saisi.x = 460;
  if (x >= 450 && x <= 600 && y >= 60 && y <= 90)
    param->saisi.y = 80;
  if (x >= 450 && x <= 600 && y >= 100 && y <= 130)
    param->saisi.y = 120;
  if (x >= 450 && x <= 600 && y >= 140 && y <= 170)
    param->saisi.y = 160;
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 180 && y <= 210)
    param->saisi.y = 200;
}

void	detect_box(t_param *param, int x, int y)
{
  if (x >= 450 && x <= 600 && y >= 60 && y <= 90)
    param->saisi.type = 1;
  if (x >= 450 && x <= 600 && y >= 100 && y <= 130)
    param->saisi.type = 2;
  if (x >= 450 && x <= 600 && y >= 140 && y <= 170)
    param->saisi.type = 3;
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 180 && y <= 210)
    param->saisi.type = 4;
  if (param->saisi.type != 0)
    {
      rempl_coord(param, x, y);
      mlx_put_image_to_window(param->window.p, param->window.id,
			      param->write.img, 429, param->saisi.y - 20);
    }
  else
    param->saisi.check = 0;
}
