/*
** limit.c for limit in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Apr  9 18:33:23 2013 luc sinet
** Last update Wed Apr 10 03:00:04 2013 luc sinet
*/

#include "main.h"

double		test_up_limit(double *cam, double *vec,
			      double k, double *limit)
{
  double	inter[3];

  get_inter(cam, vec, k, inter);
  if (inter[2] > limit[1] || inter[2] < limit[0])
    return (-1);
  return (k);
}

double		test_down_limit(double *cam, double *vec,
				double k, double *limit)
{
  double	inter[3];

  get_inter(cam, vec, k, inter);
  if (inter[2] < limit[0] || inter[2] > limit[1])
    return (-1);
  return (k);
}

double		test_limit(double *cam, double *vec, double *k, double *limit)
{
  double	min;
  double	inter[3];

  min = get_min(k, 2);
  get_inter(cam, vec, min, inter);
  if (limit[0] != -1 && inter[2] < limit[0])
    return (test_down_limit(cam, vec, get_max(k, 2), limit));
  else if (limit[1] != -1 && inter[2] > limit[1])
    return (test_up_limit(cam, vec, get_max(k, 2), limit));
  return (min);
}
