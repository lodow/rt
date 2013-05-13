/*
** inter.c for inter in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Feb 26 04:22:07 2013 luc sinet
** Last update Mon May 13 15:27:26 2013 luc sinet
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
    * cam[2] - ept->size * ept->size;
  return (solve_second(a, k));
  /* if (solve_second(a, k) == -1) */
  /*   return (-1); */
  /* return (test_limit(cam, vec, k, ept->limit)); */
}

double		cone(double *cam, double *vec, t_obj *ept)
{
  double	k[2];
  double	a[3];
  double	tan_pow;

  tan_pow = pow(ept->osin[3] / ept->ocos[3], 2);
  a[0] = vec[0] * vec[0] * tan_pow + vec[1] * vec[1] * tan_pow -
    vec[2] * vec[2];
  a[1] = 2.0 * (cam[0] * vec[0] * tan_pow + cam[1] * vec[1] * tan_pow
       - cam[2] * vec[2]);
  a[2] = cam[0] * cam[0] * tan_pow + cam[1] * cam[1] * tan_pow -
    cam[2] * cam[2];
  return (solve_second(a, k));
  /* if (solve_second(a, k) == -1) */
  /*   return (-1); */
  /* return (test_limit(cam, vec, k, ept->limit)); */
}

double		plan(double *cam, double *vec, t_obj *ept)
{
  double	a;
  double	b;

  (void)(*ept);
  a = ept->normal[0] * vec[0] + ept->normal[1] * vec[1]
    + ept->normal[2] * vec[2];
  b = -(ept->normal[0] * cam[0] + ept->normal[1] * cam[1]
	+ ept->normal[2] * cam[2]
	+ (-(ept->pos[0] * ept->normal[0] + ept->pos[1] * ept->normal[1]
	     + ept->pos[2] * ept->normal[2])));
  if (a > ZERO || a < ZERO)
    return (b / a);
  return (-1.0);
}

double		cylinder(double *cam, double *vec, t_obj *ept)
{
  double	k[2];
  double	a[3];

  a[0] = vec[0] * vec[0] + vec[1] * vec[1];
  a[1] = 2.0 * (cam[0] * vec[0] + cam[1] * vec[1]);
  a[2] = cam[0] * cam[0] + cam[1] * cam[1] - ept->size * ept->size;
  return (solve_second(a, k));
  /* if (solve_second(a, k) == -1) */
  /*   return (-1); */
  /* return (test_limit(cam, vec, k, ept->limit)); */
}
