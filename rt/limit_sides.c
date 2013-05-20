/*
** limit_sides.c for limit_sides in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Apr 10 22:20:26 2013 luc sinet
** Last update Mon May 20 20:17:52 2013 luc sinet
*/

#include "main.h"

double		test_left_limit(double *cam, double *vec,
			      double *k, double *limit)
{
  double       	mk[2];
  double	inter[3];

  mk[0] = get_min(k, 2);
  get_inter(cam, vec, mk[0], inter);
  if (inter[1] > limit[5])
    {
      mk[1] = get_max(k, 2);
      get_inter(cam, vec, mk[1], inter);
      if (inter[1] > limit[5] || inter[1] < limit[4])
	return (-1);
      else
	return (mk[1]);
    }
  return (mk[0]);
}

double		test_right_limit(double *cam, double *vec,
				double *k, double *limit)
{
  double       	mk[2];
  double	inter[3];

  mk[0] = get_min(k, 2);
  get_inter(cam, vec, mk[0], inter);
  if (inter[1] < limit[4])
    {
      mk[1] = get_max(k, 2);
      get_inter(cam, vec, mk[1], inter);
      if (inter[1] < limit[4] || inter[1] > limit[5])
	return (-1);
      else
	return (mk[1]);
    }
  return (mk[0]);
}

double		test_side_limit(double *cam, double *vec,
				 double *limit, double *k)
{
  double	min;
  double	current;

  min = get_min(k, 2);
  current = min;
  if (min > 0 && limit[4] != IVAL)
    current = test_right_limit(cam, vec, k, limit);
  min = GMAX(min, current);
  if (min > 0 && limit[5] != IVAL)
    current = test_left_limit(cam, vec, k, limit);
  min = GMAX(min, current);
  return (min);
}
