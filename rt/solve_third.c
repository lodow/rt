/*
** solve_third.c for rt in /tmp/rt/rt
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Mon Apr 22 21:01:11 2013 etienne debas
** Last update Mon Apr 22 23:32:48 2013 etienne debas
*/

#include <math.h>
#include "include/main.h"

double		solve_third(double *coef)
{
  double	pq[2];
  double	delta;
  double	k[3];

  get_pq(coef, &pq);
  k[0] = -1;
  k[1] = -1;
  k[2] = -1;
  delta = pow(pq[1], 2) + ((4 * pow(pq[0], 3)) / 27);
  if (delta < 0)
    delta_neg_third(k, delta, pq);
  else if (delta == 0.0 && pq[0] == 0.0 && pq[1] == 0.0)
    k[0] = 0;
  else if (delta == 0.0)
    delta_nul_third(k, pq);
  else if (delta > 0.0)
    delta_pos_third(k, delta, pq);
  return (get_min(k, 3));
}

void		delta_neg_third(double *k, double delta, double *pq)
{
  double	u;
  double	v;

  u = pow(-(pq[1] + sqrt(delta)) / 2, 1 / 3);
  v = pow(-(pq[1] - sqrt(delta)) / 2, 1 / 3);
  k[0] = u + v;
}

void		delta_nul_third(double *k, double *pq)
{
  k[0] = (3 * pq[1]) / pq[0];
  k[1] = (-3 * pq[1]) / (2 * pq[0]);
}

void		delta_pos_third(double *k, double delta, double *pq)
{
  int		i;

  i = 0;
  while (i < 3)
    {
      k[i] = 2 * sqrt(-pq[0] / 3)
	* cos((1 / 3) * acos((-pq[1] / 2) * sqrt(27 / pow(-pq[0], 3))) + (2 * i * M_PI) / 3);
      i++;
    }
}
