/*
** solve_third.c for rt in /tmp/rt/rt
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Mon Apr 22 21:01:11 2013 etienne debas
** Last update Mon Apr 22 21:15:35 2013 luc sinet
*/

void	get_pq(double *coef, double *pq)
{
  pq[0] = (-pow(coef[1], 2)) / (3.0 * pow(coef[0], 2))
    + coef[2] / coef[0];
  pq[1] = (coef[1] / (27.0 * coef[0]))
    * (((2.0 * pow(coef[1], 2)) / pow(coef[0], 2))
       - ((9.0 * coef[2]) / coef[0])) + (coef[3] / coef[0]);
}
