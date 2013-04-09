/*
** solve_second.c for solve_second in /home/sinet_l//rt/rtv1_sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Apr  9 14:49:14 2013 luc sinet
** Last update Tue Apr  9 19:09:57 2013 luc sinet
*/

#include <math.h>
#include "main.h"

void	get_inter(double *cam, double *vec, double k, double *inter)
{
  inter[0] = cam[0] + k * vec[0];
  inter[1] = cam[1] + k * vec[1];
  inter[2] = cam[2] + k * vec[2];
}

double		get_max(double *k, int size)
{
  int		i;
  double	max;

  i = 1;
  max = k[0];
  while (i < size)
    {
      if (k[i] > size)
	max = k[i];
      ++i;
    }
  return (max);
}

double		get_min(double *k, int size)
{
  int		i;
  double	smallest;

  i = 1;
  smallest = k[0];
  while (i < size)
    {
      if (k[i] >= ZERO && k[i] < smallest)
	smallest = k[i];
      ++i;
    }
  return (smallest);
}

double		get_smallest(double a, double b)
{
  if (a >= ZERO && a > b)
    return (a);
  return (b);
}

int		solve_second(double *a, double *k)
{
  double	delta;

  delta = a[1] * a[1] - (4.0 * a[0] * a[2]);
  if (delta < ZERO || a[0] == ZERO)
    return (-1);
  if (delta == ZERO)
    return (get_smallest((-a[1] / (2.0 * a[0])), -1.0));
  k[0] = ((-a[1] + sqrt(delta)) / (2 * a[0]));
  k[1] = ((-a[1] - sqrt(delta)) / (2 * a[0]));
  return (1);
}
