/*
** movement.c for movement in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Mar 12 20:29:28 2013 luc sinet
** Last update Wed Mar 20 23:01:18 2013 luc sinet
*/

#include <math.h>
#include "main.h"
#include "inter.h"

void		rotate_x(double *z, double *y, int angle)
{
  double	cosin;
  double	sinus;
  double	nvy;
  double	nvz;

  cosin = cos(RAD(angle));
  sinus = sin(RAD(angle));
  nvz = (*y * sinus) + (*z * cosin);
  nvy = (*y * cosin) - (*z * sinus);
  *z = nvz;
  *y = nvy;
}

void		rotate_y(double *z, double *x, int angle)
{
  double	cosin;
  double	sinus;
  double	nvx;
  double	nvz;

  cosin = cos(RAD(angle));
  sinus = sin(RAD(angle));
  nvx = (*z * sinus) + (*x * cosin);
  nvz = (*x * (-sinus)) + (*z * cosin);
  *z = nvz;
  *x = nvx;
}

void		rotate_z(double *x, double *y, int angle)
{
  double	cosin;
  double	sinus;
  double	nvy;
  double	nvx;

  cosin = cos(RAD(angle));
  sinus = sin(RAD(angle));
  nvx = (*x * cosin) + (*y * sinus);
  nvy = (*x * -sinus) + (*y * cosin);
  *y = nvy;
  *x = nvx;
}

double		move_cam(t_rt *rpt, t_vec *vpt, int nb)
{
  double	sv[3];
  double	k;

  sv[0] = vpt->vx;
  sv[1] = vpt->vy;
  sv[2] = vpt->vz;
  rpt->cpt->tx = rpt->cpt->cx - rpt->obj[nb].pos[0];
  rpt->cpt->ty = rpt->cpt->cy - rpt->obj[nb].pos[1];
  rpt->cpt->tz = rpt->cpt->cz - rpt->obj[nb].pos[2];
  rotate_x(&vpt->vz, &vpt->vy, -rpt->obj[nb].angle[0]);
  rotate_y(&vpt->vz, &vpt->vx, -rpt->obj[nb].angle[1]);
  rotate_z(&vpt->vx, &vpt->vy, -rpt->obj[nb].angle[2]);
  rotate_x(&rpt->cpt->tz, &rpt->cpt->ty, -rpt->obj[nb].angle[0]);
  rotate_y(&rpt->cpt->tz, &rpt->cpt->tx, -rpt->obj[nb].angle[1]);
  rotate_z(&rpt->cpt->tx, &rpt->cpt->ty, -rpt->obj[nb].angle[2]);
  k = rpt->eptr[rpt->obj[nb].type](rpt->cpt, vpt, &rpt->obj[nb]);
  vpt->vx = sv[0];
  vpt->vy = sv[1];
  vpt->vz = sv[2];
  return (k);
}
