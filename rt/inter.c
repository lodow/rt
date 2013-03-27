/*
** inter.c for inter in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Feb 26 04:22:07 2013 luc sinet
** Last update Mon Mar 25 22:22:00 2013 luc sinet
*/

#include <math.h>
#include "main.h"

double	get_min(double k1, double k2)
{
  if (k1 < ZERO && k2 < ZERO)
    return (-1.0);
  if (k1 < k2)
    return (k1 < ZERO ? k2 : k1);
  else if (k2 < k1)
    return (k2 < ZERO ? k1 : k2);
  return (-1.0);
}

double		sphere(double *cam, double *vec, t_obj *ept)
{
  double	a;
  double	b;
  double	c;
  double	delta;

  a = vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2];
  b = 2.0 * (cam[0] * vec[0] + cam[1] * vec[1] + cam[2] * vec[2]);
  c = cam[0] * cam[0] + cam[1] * cam[1] + cam[2]
    * cam[2] - ept->rayon * ept->rayon;
  delta = b * b - (4.0 * a * c);
  if (delta < ZERO || a == ZERO)
    return (-1);
  if (delta == ZERO)
    return (get_min((-b / (2.0 * a)), -1.0));
  return (get_min(((-b + sqrt(delta)) / (2 * a)),
		  ((-b - sqrt(delta)) / (2 * a))));
}

double		cone(double *cam, double *vec, t_obj *ept)
{
  double	a;
  double	b;
  double	c;
  double	delta;
  double	tan_pow;

  tan_pow = pow(ept->osin[3] / ept->ocos[3], 2);
  a = vec[0] * vec[0] * tan_pow + vec[1] * vec[1] * tan_pow -
    vec[2] * vec[2];
  b = 2.0 * (cam[0] * vec[0] * tan_pow + cam[1] * vec[1] * tan_pow
       - cam[2] * vec[2]);
  c = cam[0] * cam[0] * tan_pow + cam[1] * cam[1] * tan_pow -
    cam[2] * cam[2];
  delta = b * b - (4.0 * a * c);
  if (delta < ZERO || a == ZERO)
    return (-1);
  if (delta == ZERO)
    return (get_min((-b / (2.0 * a)), -1.0));
  return (get_min(((-b + sqrt(delta)) / (2 * a)),
		  ((-b - sqrt(delta)) / (2 * a))));
}

double		plan(double *cam, double *vec, t_obj *ept)
{
  return ((vec[2] == ZERO) ? -1.0 : -(cam[2] / vec[2]));
}

double		cylinder(double *cam, double *vec, t_obj *ept)
{
  double	a;
  double	b;
  double	c;
  double	delta;

  a = vec[0] * vec[0] + vec[1] * vec[1];
  b = 2.0 * (cam[0] * vec[0] + cam[1] * vec[1]);
  c = cam[0] * cam[0] + cam[1] * cam[1] - ept->rayon * ept->rayon;
  delta = b * b - (4.0 * a * c);
  if (delta < ZERO || a == ZERO)
    return (-1);
  if (delta == ZERO)
    return (get_min((-b / (2.0 * a)), -1.0));
  return (get_min(((-b + sqrt(delta)) / (2 * a)),
		  ((-b - sqrt(delta)) / (2 * a))));
}
