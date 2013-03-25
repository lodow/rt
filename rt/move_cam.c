/*
** movement.c for movement in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Mar 12 20:29:28 2013 luc sinet
** Last update Mon Mar 25 19:50:33 2013 luc sinet
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

double		move_cam(t_rt *rpt, t_vec *vpt, t_cam *cpt, int nb)
{
  double	sv[3];
  double	cam[3];
  double	vec[3];
  double	k;

  sv[0] = vpt->vx;
  sv[1] = vpt->vy;
  sv[2] = vpt->vz;
  cpt->tx = cpt->cx - rpt->obj[nb].pos[0];
  cpt->ty = cpt->cy - rpt->obj[nb].pos[1];
  cpt->tz = cpt->cz - rpt->obj[nb].pos[2];
  rotate_x(&vpt->vz, &vpt->vy, rpt->obj[nb].ocos[0], rpt->obj[nb].osin[0]);
  rotate_y(&vpt->vz, &vpt->vx, rpt->obj[nb].ocos[1], rpt->obj[nb].osin[1]);
  rotate_z(&vpt->vx, &vpt->vy, rpt->obj[nb].ocos[2], rpt->obj[nb].osin[2]);
  rotate_x(&cpt->tz, &cpt->ty, rpt->obj[nb].ocos[0], rpt->obj[nb].osin[0]);
  rotate_y(&cpt->tz, &cpt->tx, rpt->obj[nb].ocos[1], rpt->obj[nb].osin[1]);
  rotate_z(&cpt->tx, &cpt->ty, rpt->obj[nb].ocos[2], rpt->obj[nb].osin[2]);
  k = rpt->eptr[rpt->obj[nb].type](deref_cam(cpt, cam),
				   deref_vec(vpt, vec), &rpt->obj[nb]);
  vpt->vx = sv[0];
  vpt->vy = sv[1];
  vpt->vz = sv[2];
  return (k);
}
