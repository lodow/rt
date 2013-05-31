/*
** my_pixel_put_to_image.c for my_pixel_put_to_image in /home/robert_r//TP_minilibx/TP2
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Nov 12 10:10:24 2012 remi robert
** Last update Wed May 29 10:09:23 2013 remi
*/

#include "my_func.h"

int	my_pixel_put_to_image(int x, int y, t_param *param, int color)
{
  int	indice;
  int	nb_octet;

  if (y < 0 || x < 0)
    return (0);
  if (y > param->window.y || x > param->window.x)
    return (0);
  nb_octet =  mlx_get_color_value(param->window.p, 0xFFFFFF);
  indice = y * param->image.size_line + 4 * x;
  param->image.tab[indice] = (color >> 16) & 0xFF;
  if (nb_octet >> 8 != 0)
    param->image.tab[indice + 1] = (color >> 8) & 0xFF;
  if (nb_octet >> 16 != 0)
    param->image.tab[indice + 2] = color & 0xFF;
  return (1);
}
