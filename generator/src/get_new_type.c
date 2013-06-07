/*
** get_new_type.c for get_new_type in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri Jun  7 11:15:52 2013 remi robert
** Last update Fri Jun  7 11:16:50 2013 remi robert
*/

#include "my_func.h"

int	get_new_type(t_param *param, int x, int y)
{
  if (x >= 450 && x <= 600 && y >= 60 && y <= 90)
    return (1);
  if (x >= 450 && x <= 600 && y >= 100 && y <= 130)
    return (2);
  if (x >= 450 && x <= 600 && y >= 140 && y <= 170)
    return (3);
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 180 && y <= 210)
    return (4);
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 220 && y <= 250)
    return (5);
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 260 && y <= 290)
    return (6);
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 300 && y <= 330)
    return (7);
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 340 && y <= 370)
    return (8);
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 380 && y <= 420)
    return (9);
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 420 && y <= 450)
    return (10);
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 460 && y <= 480)
    return (11);
  if (param->on_click != 11 && x >= 450 && x <= 600 && y >= 500 && y <= 520)
    return (12);
  return (param->saisi.type);
}
