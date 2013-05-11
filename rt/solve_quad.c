/*
** solve_quad.c for rt in /home/debas_e//Desktop
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Sat May 11 00:40:17 2013 etienne debas
** Last update Sat May 11 17:04:38 2013 luc sinet
*/

# include "solve_quad.h"
# include "include/main.h"

void		precalculate(double *value, double *coef, double delta)
{
  if (delta > 0)
    {
      W = cbrt(-D2 / 2.0 + sqrt(delta));
      U = W - (C2 / 3.0) / W;
    }
  else if (delta == 0)
    U = 3.0 * D2 / C2;
  else if (delta < 0)
    U = 2 * sqrt(-C2 / 3.0) *
      cos(acos(-D2 / 2.0 / pow((-C2 / 3.0), (3.0 / 2.0)))
	  / 3.0);
  T = AA / 3.0 + U;
  R = sqrt(T - AA);
  S = sqrt(pow(T / 2.0, 2.0) - CC);
  DECAL = -(coef[1]) / (4.0 * coef[0]);
}

void		calculate_sol(double *value, double *sol, int *nb_sol)
{
  double	delta;
  double	first;
  double	second;
  int		i;

  i = 1;
  while (i > -3)
    {
      delta = powf(R, 2) - 2.0 * T - (i * 4.0) * S;
      first = -(i * R) / 2.0;
      if (BB > 0)
	first = -first;
      second = sqrt(fabs(delta)) / 2.0;
      if (delta >= 0)
	{
	  sol[*nb_sol] = first + second + DECAL;
	  sol[*nb_sol + 1] = first - second + DECAL;
	  *nb_sol += 2;
	}
      if (i == -1)
	return ;
      i -= 2;
    }
}

double		solve_quad(double *coef, double *res)
{
  double	delta;
  double	value[11];
  int		nb_sol;

  nb_sol = 0;
  Z = coef[1] / (2.0 * coef[0]);
  AA = coef[2] / coef[0] - 3.0 * powf(Z, 2) / 2.0;
  BB = coef[3] / coef[0] + powf(Z, 3.0) - coef[2] * Z / coef[0];
  CC = coef[4] / coef[0] - 3 * powf(Z, 4.0) / 16.0 + coef[2] * pow(Z, 2.0)
    / (4.0 * coef[0]) - coef[3] * Z / (2.0 * coef[0]);
  D2 = -2.0 * pow(AA, 3.0) / 27.0 - powf(BB, 2.0) + 8.0 * AA * CC / 3.0;
  C2 = -(powf(AA, 2.0) + 12.0 * CC) / 3.0;
  delta = powf(C2 / 3.0, 3.0) + powf(D2 / 2.0, 2.0);
  precalculate(value, coef, delta);
  calculate_sol(value, res, &nb_sol);
  return (get_min(coef, 4));
}
