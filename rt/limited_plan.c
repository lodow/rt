/*
** limited_plan.c for limited_plan in /home/adrien/Projet/rt/rt
** 
** Made by Adrien
** Login   <adrien@Adrien>
** 
** Started on  Sat May  4 14:46:20 2013 Adrien
** Last update Sun May  5 19:04:46 2013 Adrien
*/

#include "include/main.h"

double		circle(double *cam, double *vec, t_obj *ept)
{
  double	ret;
  double	test;
  double	pt[2];

  if (vec[2] == ZERO || -(cam[2] / vec[2]) < ZERO)
    return (-1);
  ret = -(cam[2] / vec[2]);
  pt[0] = vec[0] * ret + cam[0];
  pt[1] = vec[1] * ret + cam[1];
  test = pt[0] * pt[0] + pt[1] * pt[1];
  if (test < (ept->rayon * ept->rayon))
    {
      return (ret);
    }
  return (-1);
}

double		square(double *cam, double *vec, t_obj *ept)
{
  double	k1;
  double	k2;

  k2 = (ept->v1[0] * ept->pos[1] - ept->pos[0] * ept->v1[1])
    / (ept->v2[1] * ept->v1[0] - ept->v1[1] * ept->v2[0]);
  k1 = (ept->pos[0] - k2 * ept->v2[0]) / (ept->v1[0]); 
  if (k1 > ZERO && k1 < 1 && k2 > ZERO && k2 < 1)
    return ((vec[2] == ZERO) ? -1.0 : -(cam[2] / vec[2]));
  return (-1);
}

double		triangle(double *cam, double *vec, t_obj *ept)
{
  double	k1;
  double	k2;

  k2 = (ept->v1[0] * ept->pos[1] - ept->pos[0] * ept->v1[1])
    / (ept->v2[1] * ept->v1[0] - ept->v1[1] * ept->v2[0]);
  k1 = ((ept->pos[0] - k2 * ept->v2[0]) / (ept->v1[0])) + k2; 
  if (k1 > ZERO && k1 < 1)
    return ((vec[2] == ZERO) ? -1.0 : -(cam[2] / vec[2]));
  return (-1);
}
