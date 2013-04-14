/*
** limit_sides.c for limit_sides in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Apr 10 22:20:26 2013 luc sinet
** Last update Sun Apr 14 12:37:58 2013 luc sinet
*/

#include "include/main.h"

double		test_left_limit(double *cam, double *vec,
			      double k, double *limit)
{
  double	inter[3];

  get_inter(cam, vec, k, inter);
  if (inter[1] < limit[4])
    return (-1);
  if (limit[5] != IVAL && inter[1] > limit[5])
    return (-1);
  return (k);
}

double		test_right_limit(double *cam, double *vec,
				double k, double *limit)
{
  double	inter[3];

  get_inter(cam, vec, k, inter);
  if (inter[1] > limit[5])
    return (-1);
  if (limit[4] != IVAL && inter[1] < limit[4])
    return (-1);
  return (k);
}

double		test_side_limit(double *cam, double *vec,
				 double *limit, double *k)
{
  double	min;
  double	inter[3];

  min = get_min(k, 2);
  get_inter(cam, vec, min, inter);
  if (limit[4] != IVAL && inter[1] < limit[4])
    return (test_left_limit(cam, vec, get_max(k, 2), limit));
  else if (limit[5] != IVAL && inter[1] > limit[5])
    return (test_right_limit(cam, vec, get_max(k, 2), limit));
  return (min);
}
