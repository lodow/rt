/*
** limited_plan.c for limited_plan in /home/adrien/Projet/rt/rt
**
** Made by Adrien
** Login   <adrien@Adrien>
**
** Started on  Sat May  4 14:46:20 2013 Adrien
** Last update Mon May 13 15:27:42 2013 luc sinet
*/

#include "main.h"
#include "inter.h"

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
  if (k1 > ZERO && k1 < 1 && k2 > ZERO && k2 < 1 && (k1 + k2) < 1)
    return (ret);
  return (-1);
}
