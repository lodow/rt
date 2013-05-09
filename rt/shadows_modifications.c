/*
** shadows_modifications.c for shadows_modifications in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue May  7 14:26:08 2013 luc sinet
** Last update Thu May  9 10:31:03 2013 Adrien Della Maggiora
*/

#include "main.h"
#include "light.h"
#include "change_color.h"

void		change_shadow_color(unsigned char *obj_color, t_obj *d_elem,
				    t_lig *lpt)
{
  double	alpha;

  alpha = d_elem->indice[0];
  obj_color[0] = alpha * obj_color[0] + (1.0 - alpha) * d_elem->color[0];
  obj_color[1] = alpha * obj_color[1] + (1.0 - alpha) * d_elem->color[1];
  obj_color[2] = alpha * obj_color[2] + (1.0 - alpha) * d_elem->color[2];
}
