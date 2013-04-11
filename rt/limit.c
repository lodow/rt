/*
** limit.c for limit in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Apr  9 18:33:23 2013 luc sinet
** Last update Thu Apr 11 17:29:26 2013 luc sinet
*/

#include "main.h"

double		test_up_limit(double *cam, double *vec,
			      double k, double *limit)
{
  double	inter[3];

  get_inter(cam, vec, k, inter);
  if (inter[2] > limit[1])
    return (-1);
  if (limit[0] != IVAL && inter[2] < limit[0])
    return (-1);
  return (k);
}

double		test_down_limit(double *cam, double *vec,
				double k, double *limit)
{
  double	inter[3];

  get_inter(cam, vec, k, inter);
  if (inter[2] < limit[0])
    return (-1);
  if (limit[1] != IVAL && inter[2] > limit[1])
    return (-1);
  return (k);
}

double		test_heigh_limit(double *cam, double *vec,
				 double *limit, double *k)
{
  double	min;
  double	inter[3];

  min = get_min(k, 2);
  get_inter(cam, vec, min, inter);
  if (limit[0] != IVAL && inter[2] < limit[0])
    return (test_down_limit(cam, vec, get_max(k, 2), limit));
  else if (limit[1] != IVAL && inter[2] > limit[1])
    return (test_up_limit(cam, vec, get_max(k, 2), limit));
  return (min);
}

double		test_limit(double *cam, double *vec, double *k, double *limit)
{
  double	max;
  double	curent;

  max = get_min(k , 2);
  if ((curent = test_heigh_limit(cam, vec, limit, k)) > max || curent == -1)
    max = curent;
  if (max != -1 && ((curent = test_side_limit(cam, vec, limit, k)) > max ||
  		    curent == -1))
    max = curent;
  if (max != -1 && ((curent = test_depth_limit(cam, vec, limit, k)) > max ||
  		    curent == -1))
    max = curent;
  return (max);
}
