/*
** movement.c for movement in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Mar 12 20:29:28 2013 luc sinet
** Last update Sun Mar 17 16:51:35 2013 luc sinet
*/

#include <math.h>
#include "main.h"

void		rotate_x(t_vec *vpt, t_cam *cpt, t_elem *elem)
{
  double	xcos;
  double	ysin;

  xcos = cos(RAD(-elem->angle[0]));
  ysin = sin(RAD(-elem->angle[0]));
  cpt->ty = cpt->ty * xcos - cpt->tz * ysin;
  cpt->tz = cpt->ty * ysin + cpt->tz * xcos;
  vpt->vy = vpt->vy * xcos - vpt->vz * ysin;
  vpt->vz = vpt->vy * ysin + vpt->vz * xcos;
}

void		rotate_y(t_vec *vpt, t_cam *cpt, t_elem *elem)
{
  double	xcos;
  double	ysin;

  xcos = cos(RAD(-elem->angle[1]));
  ysin = sin(RAD(-elem->angle[1]));
  cpt->tx = cpt->tx * xcos - cpt->tz * ysin;
  cpt->tz = cpt->tx * -ysin + cpt->tz * xcos;
  vpt->vx = vpt->vx * xcos - vpt->vz * ysin;
  vpt->vz = vpt->vx * -ysin + vpt->vz * xcos;
}

void		rotate_z(t_vec *vpt, t_cam *cpt, t_elem *elem)
{
  double	xcos;
  double	ysin;

  xcos = cos(RAD(-elem->angle[2]));
  ysin = sin(RAD(-elem->angle[2]));
  cpt->tx = cpt->tx * xcos + cpt->ty * -ysin;
  cpt->ty = cpt->tx * ysin + cpt->ty * xcos;
  vpt->vx = vpt->vx * xcos + vpt->vy * -ysin;
  vpt->vy = vpt->vx * ysin + vpt->vy * xcos;
}

double		move_cam(t_rt *rpt, t_elem *elem, int type)
{
  double	sv[3];
  double	k;

  sv[0] = rpt->vpt->vx;
  sv[1] = rpt->vpt->vy;
  sv[2] = rpt->vpt->vz;
  rpt->cpt->tx = rpt->cpt->cx - elem->pos[0];
  rpt->cpt->ty = rpt->cpt->cy - elem->pos[1];
  rpt->cpt->tz = rpt->cpt->cz - elem->pos[2];
  rotate_y(rpt->vpt, rpt->cpt, elem);
  rotate_x(rpt->vpt, rpt->cpt, elem);
  rotate_z(rpt->vpt, rpt->cpt, elem);
  k = rpt->eptr[type](rpt->cpt, rpt->vpt, elem);
  rpt->vpt->vx = sv[0];
  rpt->vpt->vy = sv[1];
  rpt->vpt->vz = sv[2];
  return (k);
}
