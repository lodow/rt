/*
** light_calcul.c for light_calcul in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed May  8 18:39:21 2013 luc sinet
** Last update Fri May 10 11:49:53 2013 luc sinet
*/

#include "include/main.h"
#include "include/light.h"
#include "include/change_color.h"

void		filter_light_color(unsigned char *lcolor, t_obj *obj)
{
  double	ratio;

  ratio = obj->indice[0];
  lcolor[0] = ratio * lcolor[0]
    + (1.0 - ratio) * obj->color[0];
  lcolor[1] = ratio * lcolor[1]
    + (1.0 - ratio) * obj->color[1];
  lcolor[2] = ratio * lcolor[2]
    + (1.0 - ratio) * obj->color[2];
}
