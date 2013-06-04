/*
** detect_box.c for detect_box7 in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Jun  4 12:58:21 2013 remi robert
** Last update Tue Jun  4 13:04:02 2013 remi robert
*/

#include "my_func.h"

void	detect_box(t_param *param, int x, int y)
{
  if (x >= 450 && x <= 600 && y >= 60 && y <= 90)
    {
      param->saisi.check = 1;
      printf("First !! \n");
      param->saisi.type = 1;
      param->saisi.x = 460;
      param->saisi.y = 80;
    }
}
