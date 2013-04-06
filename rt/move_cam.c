/*
** movement.c for movement in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Mar 12 20:29:28 2013 luc sinet
** Last update Sat Apr  6 11:41:32 2013 luc sinet
*/

#include <math.h>
#include "main.h"
#include "inter.h"

void		rotate_x(double *z, double *y, double cosin, double sinus)
{
  double	nvy;
  double	nvz;

  nvz = (*y * sinus) + (*z * cosin);
  nvy = (*y * cosin) - (*z * sinus);
  *z = nvz;
  *y = nvy;
}

void		rotate_y(double *z, double *x, double cosin, double sinus)
{
  double	nvx;
  double	nvz;

  nvx = (*z * sinus) + (*x * cosin);
  nvz = (*x * (-sinus)) + (*z * cosin);
  *z = nvz;
  *x = nvx;
}

void		rotate_z(double *x, double *y, double cosin, double sinus)
{
  double	nvy;
  double	nvx;

  nvx = (*x * cosin) + (*y * sinus);
  nvy = (*x * -sinus) + (*y * cosin);
  *y = nvy;
  *x = nvx;
}

double		move_cam(t_rt *rpt, t_vec *vpt, t_cam *cpt, t_obj obj)
{
  double	cam[3];
  double	vec[3];
  double	k;

  deref_vec(vpt, vec);
  cam[0] = cpt->cx - obj.pos[0];
  cam[1] = cpt->cy - obj.pos[1];
  cam[2] = cpt->cz - obj.pos[2];
  rotate_x(&vec[2], &vec[1], obj.ocos[0], obj.osin[0]);
  rotate_y(&vec[2], &vec[0], obj.ocos[1], obj.osin[1]);
  rotate_z(&vec[0], &vec[1], obj.ocos[2], obj.osin[2]);
  rotate_x(&cam[2], &cam[1], obj.ocos[0], obj.osin[0]);
  rotate_y(&cam[2], &cam[0], obj.ocos[1], obj.osin[1]);
  rotate_z(&cam[0], &cam[1], obj.ocos[2], obj.osin[2]);
  k = rpt->eptr[obj.type](cam, vec, &obj);
  return (k);
}
