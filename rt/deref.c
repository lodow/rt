/*
** deref.c for deref.c in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Mar 25 19:33:13 2013 luc sinet
** Last update Mon Apr 15 23:05:14 2013 luc sinet
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
  vec[0] = vpt->vec[0];
  vec[1] = vpt->vec[1];
  vec[2] = vpt->vec[2];
  return (vec);
}
