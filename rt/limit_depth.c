/*
** limit_sides.c for limit_sides in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Apr 10 22:20:26 2013 luc sinet
** Last update Sat Jun  8 16:04:08 2013 maxime lavandier
*/

#include "main.h"

double		test_forw_limit(double *cam, double *vec,
				double *k, double *limit)
{
  double       	mk[2];
  double	inter[3];

  mk[0] = get_min(k, 2);
  get_inter(cam, vec, mk[0], inter);
  if (inter[0] < limit[1])
    {
      mk[1] = get_max(k, 2);
      get_inter(cam, vec, mk[1], inter);
      if (inter[0] < limit[1] || inter[0] > limit[2])
	return (-1);
      else
	return (mk[1]);
    }
  return (mk[0]);
}

double		test_back_limit(double *cam, double *vec,
				double *k, double *limit)
{
  double       	mk[2];
  double	inter[3];

  mk[0] = get_min(k, 2);
  get_inter(cam, vec, mk[0], inter);
  if (inter[0] > limit[2])
    {
      mk[1] = get_max(k, 2);
      get_inter(cam, vec, mk[1], inter);
      if (inter[0] > limit[2] || inter[0] < limit[1])
	return (-1);
      else
	return (mk[1]);
    }
  return (mk[0]);
}

double		test_depth_limit(double *cam, double *vec,
				 double *limit, double *k)
{
  double	min;
  double	current;

  min = get_min(k, 2);
  current = min;
  if (min > 0 && limit[1] != IVAL)
    current = test_forw_limit(cam, vec, k, limit);
  min = GMAX(min, current);
  if (min > 0 && limit[2] != IVAL)
    current = test_back_limit(cam, vec, k, limit);
  min = GMAX(min, current);
  return (min);
}
