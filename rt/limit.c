/*
** limit.c for limit in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Apr  9 18:33:23 2013 luc sinet
** Last update Thu May  9 10:32:12 2013 Adrien Della Maggiora
*/

#include "main.h"

double		test_up_limit(double *cam, double *vec,
			      double *k, double *limit)
{
  double       	mk[2];
  double	inter[3];

  mk[0] = get_min(k, 2);
  get_inter(cam, vec, mk[0], inter);
  /* printf("up = %f, max = %f\n", inter[2], limit[8]); */
  if (inter[2] > limit[8])
    {
      mk[1] = get_max(k, 2);
      get_inter(cam, vec, mk[1], inter);
      /* printf("sup = %f, min = %f\n", inter[2], limit[7]); */
      if (inter[2] < limit[7])
	return (-1);
      else
	return (mk[1]);
    }
  return (mk[0]);
}

double		test_down_limit(double *cam, double *vec,
				double *k, double *limit)
{
  double       	mk[2];
  double	inter[3];

  mk[0] = get_min(k, 2);
  get_inter(cam, vec, mk[0], inter);
  if (inter[2] < limit[7])
    {
      mk[1] = get_max(k, 2);
      get_inter(cam, vec, mk[1], inter);
      if (inter[2] < limit[7])
	return (-1);
      else
	return (mk[1]);
    }
  return (mk[0]);
}

double		test_heigh_limit(double *cam, double *vec,
				 double *limit, double *k)
{
  double	min;
  double	current;

  min = get_min(k, 2);
  current = min;
  if (min > 0 && limit[8] != IVAL)
    current = test_up_limit(cam, vec, k, limit);
  min = GMAX(min, current);
  /* if (min > 0 && limit[7] != IVAL) */
  /*   current = test_down_limit(cam, vec, k, limit); */
  /* min = GMAX(min, current); */
  return (min);
}

double		test_limit(double *cam, double *vec, double *k, double *limit)
{
  double	min;
  double	curent;

  min = get_min(k , 2);
  if (limit[6] == 3 && min > 0 &&
      ((curent = test_heigh_limit(cam, vec, limit, k)) > min || curent < 0))
    min = curent;
  /* if (limit[3] == 2 && min > 0 && */
  /*     ((curent = test_side_limit(cam, vec, limit, k)) > min || curent < 0)) */
  /*   min = curent; */
  /* if (limit[0] == 1 && min > 0 && */
  /*     ((curent = test_depth_limit(cam, vec, limit, k)) > min || curent < 0)) */
  /*   min = curent; */
  return (min);
}
