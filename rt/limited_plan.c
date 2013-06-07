/*
** limited_plan.c for limited_plan in /home/adrien/Projet/rt/rt
**
** Made by Adrien
** Login   <adrien@Adrien>
**
** Started on  Sat May  4 14:46:20 2013 Adrien
** Last update Fri Jun  7 11:56:28 2013 adrien dellamaggiora
*/

#include "main.h"
#include "inter.h"
#include "light.h"

double		circle(double *cam, double *vec, t_obj *ept)
{
  double	ret;
  double	test;
  double	pt[2];

  if ((ret = plan(cam, vec, ept)) == -1)
    return (-1);
  pt[0] = vec[0] * ret + cam[0];
  pt[1] = vec[1] * ret + cam[1];
  test = pt[0] * pt[0] + pt[1] * pt[1];
  if (test < (ept->size[0] * ept->size[0]))
    return (ret);
  return (-1);
}

double		square(double *cam, double *vec, t_obj *ept)
{
  double	k1;
  double	k2;
  double	ret;
  double	pt[2];

  if ((ret = plan(cam, vec, ept)) == -1)
    return (-1);
  pt[0] = vec[0] * ret + cam[0];
  pt[1] = vec[1] * ret + cam[1];
  k2 = (ept->v1[0] * pt[1] - pt[0] * ept->v1[1])
    / (ept->v2[1] * ept->v1[0] - ept->v1[1] * ept->v2[0]);
  k1 = (pt[0] - k2 * ept->v2[0]) / (ept->v1[0]);
  if (k1 > ZERO && k1 < 1 && k2 > ZERO && k2 < 1)
    return (ret);
  return (-1);
}

double		triangle(double *cam, double *vec, t_obj *ept)
{
  double	pt[3];
  double	u[3];
  double	v[3];
  double	w[3];
  double	d;
  double	ret;
  double	s;
  double	t;

  if ((ret = plan(cam, vec, ept)) < -ZERO)
    return (-1);
  pt[0] = vec[0] * ret + cam[0];
  pt[1] = vec[1] * ret + cam[1];
  pt[2] = vec[2] * ret + cam[2];
  v[0] = ept->pt2[0] - ept->pos[0];
  v[1] = ept->pt2[1] - ept->pos[1];
  v[2] = ept->pt2[2] - ept->pos[2];
  u[0] = ept->pt1[0] - ept->pos[0];
  u[1] = ept->pt1[1] - ept->pos[1];
  u[2] = ept->pt1[2] - ept->pos[2];
  w[0] = pt[0] - ept->pos[0];
  w[1] = pt[1] - ept->pos[1];
  w[2] = pt[2] - ept->pos[2];
  d = ((scale(u, v) * scale(u, v)) - (scale(u, u) * scale(v, v)));
  s = ((scale(u, v) * scale(w, v)) - (scale(v, v) * scale(w, u))) / d;
  t = ((scale(u, v) * scale(w, u)) - (scale(u, u) * scale(w, v))) / d;
  if (s > ZERO && t > ZERO && s < 1 && t < 1 && s + t <= 1)
    return (ret);
  return (-1);
}
