/*
** math_coor.c for math_coor in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Mar 27 23:14:34 2013 luc sinet
** Last update Fri Apr  5 11:01:31 2013 luc sinet
*/

#include <math.h>
#include "main.h"
#include "light.h"

double	point_distance(double *p1, double *p2)
{
  return (pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2)
	  + pow(p1[2] - p2[2], 2));
}

double		apply_distance(t_lco *lpt, t_lig *obj, double ratio_a)
{
  double	dist;
  double	ratio_d;

  dist = point_distance(lpt->obj_coor, obj->pos);
  if (dist < DISTM)
    dist = DISTM;
  ratio_d = 1.0 / (dist / DISTM);
  ratio_a = ((1 - ratio_a) * ratio_a + (ratio_a * ratio_d)) * obj->intensity;
  return (ratio_a);
}
