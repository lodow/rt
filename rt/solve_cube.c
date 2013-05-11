/*
** solve_cube.c for solve_third in /home/debas_e//Desktop
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Fri May 10 21:28:51 2013 etienne debas
** Last update Sat May 11 16:42:36 2013 etienne debas
*/

# include "solve_cube.h"
# include "include/main.h"

void		get_pq_and_disc(double *coef, double *res,
				double *pq, double *discriminant)
{
  pq[0] = (3 * coef[2] / coef[0] - pow(coef[1], 2) / pow(coef[0], 2)) / 3;
  pq[1] = (2 * pow(coef[1], 3) / pow(coef[0], 3) - 9 * coef[1]
	   * coef[2] / pow(coef[0], 2) + 27 * coef[3] / coef[0]) / 27;
  *discriminant = pow(pq[1], 2) / 4 + pow(pq[0], 3) / 27;
  res[0] = -1;
  res[1] = -1;
  res[2] = -1;
}

void		three_solution(double *res, double *pq,
			       double *coef, double discriminant)
{
  double	i;
  double	j;
  double	k;
  double	m;
  double	n;
  double	p;

  i = pow(pow(pq[1], 2) / 4 - discriminant, 0.5);
  j = cbrt(i);
  k = acos(-(pq[1] / (2 * i)));
  m = cos(k / 3);
  n = ROOTTHREE * sin(k / 3);
  p = -(coef[1] / (3 * coef[0]));
  res[0] = 2 * j * m + p;
  res[1] = -j * (m + n) + p;
  res[2] = -j * (m - n) + p;
}

void		one_solution(double *res, double *pq,
			     double *coef, double discriminant)
{
  double	r;
  double	s;
  double	t;
  double	u;
  double	v;

  r = -(pq[1] / 2) + pow(discriminant, 0.5);
  s = cbrt(r);
  t = -(pq[1] / 2) - pow(discriminant, 0.5);
  u = cbrt(t);
  v = -(coef[1] / (3 * coef[0]));
  res[0] = (s + u) + v;
}

double		solve_third(double *coef, double *res)
{
    double	discriminant;
    double	pq[2];

    get_pq_and_disc(coef, res, pq, &discriminant);
    if (pq[0] == 0 && pq[1] == 0 && discriminant == 0)
      res[0] = -cbrt(coef[3] / coef[0]);
    else if (discriminant <= 0)
      three_solution(res, pq, coef, discriminant);
    else if (discriminant > 0)
      one_solution(res, pq, coef, discriminant);
    return (get_min(res, 4));
}
