/*
** light_calcul.c for light_calcul in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed May  8 18:39:21 2013 luc sinet
** Last update Thu May 16 00:14:55 2013 luc sinet
*/

#include <math.h>
#include "include/main.h"
#include "include/light.h"
#include "include/change_color.h"

void		filter_light_color(unsigned char *lcolor, t_obj *obj, double distance)
{
  double	lcolor1[3];
  double	lcolor2[3];
  double	ratio1;
  double	ratio2;

  ratio1 = obj->indice[0];
  ratio2 = exp(-(distance / 200));
  lcolor1[0] = ratio1 * lcolor[0]
    + (1.0 - ratio1) * obj->color[0];
  lcolor1[1] = ratio1 * lcolor[1]
    + (1.0 - ratio1) * obj->color[1];
  lcolor1[2] = ratio1 * lcolor[2]
    + (1.0 - ratio1) * obj->color[2];
  lcolor2[0] = obj->color[0] * (1.0 - ratio2)
    + lcolor[0] * ratio2;
  lcolor2[1] = obj->color[1] * (1.0 - ratio2)
    + lcolor[1] * ratio2;
  lcolor2[2] = obj->color[2] * (1.0 - ratio2)
    + lcolor[2] * ratio2;
  lcolor[0] = 0.90 * lcolor1[0] + 0.10 * lcolor2[0];
  lcolor[1] = 0.90 * lcolor1[1] + 0.10 * lcolor2[1];
  lcolor[2] = 0.90 * lcolor1[2] + 0.10 * lcolor2[2];
}
