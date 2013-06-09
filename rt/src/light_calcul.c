/*
** light_calcul.c for light_calcul in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed May  8 18:39:21 2013 luc sinet
** Last update Sun Jun  9 01:08:05 2013 Hugues
*/

#include <math.h>
#include "main.h"
#include "light.h"
#include "change_color.h"

void		filter_light_color(unsigned char *lcolor, t_obj *obj,
				   double distance)
{
  double	ratio;
  double	ratio_distance;

  ratio_distance = LIMIT(distance / MAX_DIST, 0, 1);
  ratio = LIMIT(obj->ipt->indice[3] * (1.0 - obj->ipt->indice[0])
		* ratio_distance, 0 , 1);
  lcolor[0] = (1.0 - ratio) * lcolor[0]
    + ratio * obj->color[0];
  lcolor[1] = (1.0 - ratio) * lcolor[1]
    + ratio * obj->color[1];
  lcolor[2] = (1.0 - ratio) * lcolor[2]
    + ratio * obj->color[2];
}
