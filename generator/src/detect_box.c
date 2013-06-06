/*
** detect_box.c for detect_box7 in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Jun  4 12:58:21 2013 remi robert
** Last update Thu Jun  6 08:00:34 2013 remi robert
*/

#include "my_func.h"

void	rempl_coord(t_param *param, int x, int y)
{
  if (x >= 450 && x <= 600 && y >= 60 && y <= 90)
    param->saisi.y = 80;
  if (x >= 450 && x <= 600 && y >= 100 && y <= 130)
    param->saisi.y = 120;
  if (x >= 450 && x <= 600 && y >= 140 && y <= 170)
    param->saisi.y = 160;
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 180 && y <= 210)
    param->saisi.y = 200;
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 220 && y <= 250)
    param->saisi.y = 240;
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 260 && y <= 290)
    param->saisi.y = 280;
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 300 && y <= 330)
    param->saisi.y = 320;
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 340 && y <= 370)
    param->saisi.y = 360;
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 380 && y <= 420)
    param->saisi.y = 400;
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 420 && y <= 450)
    param->saisi.y = 440;
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 460 && y <= 480)
    param->saisi.y = 480;
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 500 && y <= 520)
    param->saisi.y = 520;
}

void	get_type_saisie(t_param *param, int x, int y)
{
  if (x >= 450 && x <= 600 && y >= 60 && y <= 90)
    param->saisi.type = 1;
  if (x >= 450 && x <= 600 && y >= 100 && y <= 130)
    param->saisi.type = 2;
  if (x >= 450 && x <= 600 && y >= 140 && y <= 170)
    param->saisi.type = 3;
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 180 && y <= 210)
    param->saisi.type = 4;
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 220 && y <= 250)
    param->saisi.type = 5;
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 260 && y <= 290)
    param->saisi.type = 6;
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 300 && y <= 330)
    param->saisi.type = 7;
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 340 && y <= 370)
    param->saisi.type = 8;
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 380 && y <= 420)
    param->saisi.type = 9;
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 420 && y <= 450)
    param->saisi.type = 10;
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 460 && y <= 480)
    param->saisi.type = 11;
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 500 && y <= 520)
    param->saisi.type = 12;
}

void	detect_box(t_param *param, int x, int y)
{
  get_type_saisie(param, x, y);
  if (param->saisi.type != 0)
    {
      param->saisi.check = 1;
      param->saisi.x = 460;
      rempl_coord(param, x, y);
      mlx_put_image_to_window(param->window.p, param->window.id,
			      param->write.img, 429, param->saisi.y - 20);
    }
  else
    param->saisi.check = 0;
}
