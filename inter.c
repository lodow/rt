/*
** inter.c for inter in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Feb 26 04:22:07 2013 luc sinet
** Last update Wed Mar 20 22:48:27 2013 luc sinet
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

double		sphere(t_cam *cpt, t_vec *vpt, t_obj *ept)
{
  double	a;
  double	b;
  double	c;
  double	delta;

  a = vpt->vx * vpt->vx + vpt->vy * vpt->vy + vpt->vz * vpt->vz;
  b = 2.0 * (cpt->tx * vpt->vx + cpt->ty * vpt->vy + cpt->tz * vpt->vz);
  c = cpt->tx * cpt->tx + cpt->ty * cpt->ty + cpt->tz
    * cpt->tz - ept->rayon * ept->rayon;
  delta = b * b - (4.0 * a * c);
  if (delta < ZERO || a == ZERO)
    return (-1);
  if (delta == ZERO)
    return (get_min((-b / (2.0 * a)), -1.0));
  return (get_min(((-b + sqrt(delta)) / (2 * a)),
		  ((-b - sqrt(delta)) / (2 * a))));
}

double		cone(t_cam *cpt, t_vec *vpt, t_obj *ept)
{
  double	a;
  double	b;
  double	c;
  double	delta;
  double	tan_pow;

  tan_pow = tan(RAD(ept->angle[3])) * tan(RAD(ept->angle[3]));
  a = vpt->vx * vpt->vx * tan_pow + vpt->vy * vpt->vy * tan_pow -
    vpt->vz * vpt->vz;
  b = 2.0 * (cpt->tx * vpt->vx * tan_pow + cpt->ty * vpt->vy * tan_pow
       - cpt->tz * vpt->vz);
  c = cpt->tx * cpt->tx * tan_pow + cpt->ty * cpt->ty * tan_pow -
    cpt->tz * cpt->tz;
  delta = b * b - (4.0 * a * c);
  if (delta < ZERO || a == ZERO)
    return (-1);
  if (delta == ZERO)
    return (get_min((-b / (2.0 * a)), -1.0));
  return (get_min(((-b + sqrt(delta)) / (2 * a)),
		  ((-b - sqrt(delta)) / (2 * a))));
}

double		plan(t_cam *cpt, t_vec *vpt, t_obj *ept)
{
  return ((vpt->vz == ZERO) ? -1.0 : -(cpt->tz / vpt->vz));
}

double		cylinder(t_cam *cpt, t_vec *vpt, t_obj *ept)
{
  double	a;
  double	b;
  double	c;
  double	delta;

  a = vpt->vx * vpt->vx + vpt->vy * vpt->vy;
  b = 2.0 * (cpt->tx * vpt->vx + cpt->ty * vpt->vy);
  c = cpt->tx * cpt->tx + cpt->ty * cpt->ty - ept->rayon * ept->rayon;
  delta = b * b - (4.0 * a * c);
  if (delta < ZERO || a == ZERO)
    return (-1);
  if (delta == ZERO)
    return (get_min((-b / (2.0 * a)), -1.0));
  return (get_min(((-b + sqrt(delta)) / (2 * a)),
		  ((-b - sqrt(delta)) / (2 * a))));
}
