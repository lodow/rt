/*
** deref.c for deref.c in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Mar 25 19:33:13 2013 luc sinet
** Last update Fri Apr 12 14:42:13 2013 Adrien Della Maggiora
*/

#include "include/main.h"

double		*deref_cam(t_cam *cpt, double *cam)
{
  cam[0] = cpt->tx;
  cam[1] = cpt->ty;
  cam[2] = cpt->tz;
  return (cam);
}

double		*deref_vec(t_vec *vpt, double *vec)
{
  vec[0] = vpt->vx;
  vec[1] = vpt->vy;
  vec[2] = vpt->vz;
  return (vec);
}
