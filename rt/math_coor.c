/*
** math_coor.c for math_coor in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Mar 27 23:14:34 2013 luc sinet
** Last update Mon Apr 15 22:12:40 2013 luc sinet
*/

#include <math.h>
#include "include/main.h"
#include "include/light.h"

double	point_distance(double *p1, double *p2)
{
  return (pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2)
	  + pow(p1[2] - p2[2], 2));
}

double	vec_norme(double *vector)
{
  return (sqrt(pow(vector[0], 2) + pow(vector[1], 2) + pow(vector[2], 2)));
}

double		apply_distance(t_lco *lpt, t_lig *obj, double ratio_a)
{
  double	dist;
  double	ratio_d;

  dist = point_distance(lpt->obj_coor, obj->pos);
  if (dist < DISTM)
    dist = DISTM;
  ratio_d = 1.0 / (dist / DISTM);
  ratio_a = ((1.0 - ratio_a) * ratio_a + (ratio_a * ratio_d)) * obj->intensity;
  return (ratio_a);
}

void		get_obj_distance(t_obj *obj, t_cam *cpt, double *hit)
{
  double	cam[3];

  cam[0] = cpt->pos[0];
  cam[1] = cpt->pos[1];
  cam[2] = cpt->pos[2];
  obj->dist = point_distance(cam, hit);
}
