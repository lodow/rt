/*
** math_coor.c for math_coor in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Mar 27 23:14:34 2013 luc sinet
** Last update Wed May 29 21:22:02 2013 luc sinet
*/

#include <math.h>
#include "main.h"
#include "light.h"

double	point_distance(double *p1, double *p2)
{
  return (sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2)
	       + pow(p1[2] - p2[2], 2)));
}

double		apply_distance(t_lco *lpt, t_lig *obj, double ratio_a)
{
  double	dist;
  double	ratio_d;

  dist = point_distance(lpt->obj_coor, obj->pos);
  ratio_d = -dist / DISTP + 1.0;
  ratio_d = (ratio_d > 1.0) ? 1.0 : (ratio_d < 0.0) ? 0.0 : ratio_d;
  ratio_a = ratio_a * ratio_d;
  return (ratio_a);
}

void		get_obj_distance(t_obj *obj, double *cpos, double *hit)
{
  double	cam[3];

  cam[0] = cpos[0];
  cam[1] = cpos[1];
  cam[2] = cpos[2];
  obj->dist = point_distance(cam, hit);
}
