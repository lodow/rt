/*
** inter.c for inter in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Feb 26 04:22:07 2013 luc sinet
** Last update Thu Jun  6 00:37:14 2013 luc sinet
*/

#include <math.h>
#include "main.h"

double		sphere(double *cam, double *vec, t_obj *ept)
{
  double	k[2];
  double	a[3];

  a[0] = vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2];
  a[1] = 2.0 * (cam[0] * vec[0] + cam[1] * vec[1] + cam[2] * vec[2]);
  a[2] = cam[0] * cam[0] + cam[1] * cam[1] + cam[2]
    * cam[2] - ept->size[0] * ept->size[0];
  if (solve_second(a, k) == -1)
    return (-1);
  return (test_limit(cam, vec, k, ept->limit));
}

double		cone(double *cam, double *vec, t_obj *ept)
{
  double	k[2];
  double	a[3];
  double	tan_pow;

  tan_pow = pow(ept->apt->osin[3] / ept->apt->ocos[3], 2);
  a[0] = vec[0] * vec[0] * tan_pow + vec[1] * vec[1] * tan_pow -
    vec[2] * vec[2];
  a[1] = 2.0 * (cam[0] * vec[0] * tan_pow + cam[1] * vec[1] * tan_pow
       - cam[2] * vec[2]);
  a[2] = cam[0] * cam[0] * tan_pow + cam[1] * cam[1] * tan_pow -
    cam[2] * cam[2];
  if (solve_second(a, k) == -1)
    return (-1);
  return (test_limit(cam, vec, k, ept->limit));
}

double		plan(double *cam, double *vec, UNUSED t_obj *ept)
{
  double	a[3];

  a[1] = ept->normal[0] * vec[0] + ept->normal[1] * vec[1]
    + ept->normal[2] * vec[2];
  a[2] = -(ept->normal[0] * cam[0] + ept->normal[1] * cam[1]
	+ ept->normal[2] * cam[2]
	+ (-(ept->pos[0] * ept->normal[0] + ept->pos[1] * ept->normal[1]
	     + ept->pos[2] * ept->normal[2])));
  a[0] = 0;
  if (a[1] > ZERO || a[1] < ZERO)
    return (a[2] / a[1]);
  return (-1.0);
}

double		cylinder(double *cam, double *vec, t_obj *ept)
{
  double	k[2];
  double	a[3];

  a[0] = vec[0] * vec[0] + vec[1] * vec[1];
  a[1] = 2.0 * (cam[0] * vec[0] + cam[1] * vec[1]);
  a[2] = cam[0] * cam[0] + cam[1] * cam[1] - ept->size[0] * ept->size[0];
  if (solve_second(a, k) == -1)
    return (-1);
  return (test_limit(cam, vec, k, ept->limit));
}
