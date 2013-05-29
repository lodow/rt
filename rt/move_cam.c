/*
** movement.c for movement in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Mar 12 20:29:28 2013 luc sinet
** Last update Wed May 29 18:31:35 2013 luc sinet
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

double		move_cam(t_rt *rpt, t_vec *vpt, t_cam *cpt, t_obj *obj)
{
  double	cam[3];
  double	vec[3];
  double	k;

  copy_tab(vpt->vec, vec, 3);
  cam[0] = cpt->pos[0] - obj->pos[0];
  cam[1] = cpt->pos[1] - obj->pos[1];
  cam[2] = cpt->pos[2] - obj->pos[2];
  rotate(vec, obj->ocos, obj->osin, 0);
  rotate(cam, obj->ocos, obj->osin, 0);
  k = rpt->eptr[obj->type](cam, vec, obj);
  return (k);
}
