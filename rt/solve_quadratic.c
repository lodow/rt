/*
** solve_quadratic.c for rt in /home/debas_e//Desktop/projet/rt/rt
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Mon Jun  3 20:46:13 2013 etienne debas
** Last update Sat Jun  8 18:09:24 2013 etienne debas
*/

#include "solve.h"
#include "include/main.h"

int		solve_quadratic(double *coef, double *res)
{
  double	delta;
  double	k;
  int		nb_sol;

  nb_sol = 0;
  delta = coef[1] * coef[1] - 4 * coef[0] * coef[2];
  if (delta < 0.0)
    return (0);
  if (delta >= 0.0)
    {
      k = (-coef[1] + sqrt(delta)) / (2 * coef[0]);
      res[nb_sol++] = k;
    }
  if (delta > 0.0)
    {
      k = (-coef[1] - sqrt(delta)) / (2 * coef[0]);
      res[nb_sol++] = k;
    }
  return (nb_sol);
}
