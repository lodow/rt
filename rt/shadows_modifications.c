/*
** shadows_modifications.c for shadows_modifications in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue May  7 14:26:08 2013 luc sinet
** Last update Tue May  7 15:03:34 2013 luc sinet
*/

#include "include/main.h"
#include "include/light.h"
#include "include/change_color.h"

void		change_shadow_color(unsigned char *obj_color, t_obj *d_elem)
{
  double	color_ratio;

  color_ratio = 1.0 - d_elem->indice[0];
  obj_color[0] = (1.0 - color_ratio) * obj_color[0]
    + color_ratio * d_elem->color[0];
  obj_color[1] = (1.0 - color_ratio) * obj_color[1]
    + color_ratio * d_elem->color[1];
  obj_color[2] = (1.0 - color_ratio) * obj_color[2]
    + color_ratio * d_elem->color[2];
}
