/*
** limit_sides.c for limit_sides in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Apr 10 22:20:26 2013 luc sinet
** Last update Wed Apr 10 23:52:26 2013 luc sinet
*/

#include "main.h"

double		test_r_limit(double *cam, double *vec,
			      double k, double *limit)
{
  double	inter[3];

  get_inter(cam, vec, k, inter);
  if (inter[1] > limit[3] || inter[1] < limit[2])
    return (-1);
  return (k);
}

double		test_l_limit(double *cam, double *vec,
				double k, double *limit)
{
  double	inter[3];

  get_inter(cam, vec, k, inter);
  if (inter[1] < limit[2] || inter[1] > limit[1])
    return (-1);
  return (k);
}

double		test_side_limit(double *cam, double *vec,
				 double *limit, double k)
{
  double	inter[3];

  get_inter(cam, vec, min, inter);
  if (limit[2] != -1 && inter[1] < limit[2])
    return (test_l_limit(cam, vec, k, limit));
  else if (limit[3] != -1 && inter[1] > limit[3])
    return (test_r_limit(cam, vec, k, limit));
  return (min);
}
