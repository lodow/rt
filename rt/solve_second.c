/*
** solve_second.c for solve_second in /home/sinet_l//rt/rtv1_sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Apr  9 14:49:14 2013 luc sinet
** Last update Tue Apr  9 15:06:52 2013 luc sinet
*/

#include <math.h>
#include "main.h"

double	get_min(double k1, double k2)
{
  if (k1 < ZERO && k2 < ZERO)
    return (-1.0);
  if (k1 < k2)
    return (k1 < ZERO ? k2 : k1);
  else if (k2 < k1)
    return (k2 < ZERO ? k1 : k2);
  return (-1.0);
}

double		solve_second(double *a)
{
  double	delta;

  delta = a[1] * a[1] - (4.0 * a[0] * a[2]);
  if (delta < ZERO || a[0] == ZERO)
    return (-1);
  if (delta == ZERO)
    return (get_min((-a[1] / (2.0 * a[0])), -1.0));
  return (get_min(((-a[1] + sqrt(delta)) / (2 * a[0])),
		  ((-a[1] - sqrt(delta)) / (2 * a[0]))));
}
