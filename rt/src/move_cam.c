/*
** movement.c for movement in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Mar 12 20:29:28 2013 luc sinet
** Last update Thu Jun  6 00:58:35 2013 luc sinet
*/

#include <math.h>
#include "main.h"
#include "inter.h"

void		rotate_x(double *p, double cosin, double sinus)
{
  double	nvy;
  double	nvz;

  nvz = (p[1] * sinus) + (p[2] * cosin);
  nvy = (p[1] * cosin) - (p[2] * sinus);
  p[2] = nvz;
  p[1] = nvy;
}

void		rotate_y(double *p, double cosin, double sinus)
{
  double	nvx;
  double	nvz;

  nvx = (p[2] * sinus) + (p[0] * cosin);
  nvz = (p[0] * (-sinus)) + (p[2] * cosin);
  p[2] = nvz;
  p[0] = nvx;
}

void		rotate_z(double *p, double cosin, double sinus)
{
  double	nvy;
  double	nvx;

  nvx = (p[0] * cosin) + (p[1] * sinus);
  nvy = (p[0] * -sinus) + (p[1] * cosin);
  p[1] = nvy;
  p[0] = nvx;
}

double		move_cam(t_rt *rpt, double *rvec, double *cpos, t_obj *obj)
{
  double	vec[3];
  double	cam[3];
  double	*ocos;
  double	*osin;
  double	k;

  ocos = obj->apt->ocos;
  osin = obj->apt->osin;
  copy_tab(rvec, vec, 3);
  cam[0] = cpos[0] - obj->pos[0];
  cam[1] = cpos[1] - obj->pos[1];
  cam[2] = cpos[2] - obj->pos[2];
  rotate(vec, ocos, osin, 0);
  rotate(cam, ocos, osin, 0);
  k = rpt->eptr[obj->type](cam, vec, obj);
  return (k);
}
