/*
** solve_quad.h for rt in /home/debas_e//Desktop/projet/rt/rt
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Mon Jun  3 20:55:00 2013 etienne debas
** Last update Sat Jun  8 17:52:08 2013 adrien dellamaggiora
*/

#ifndef SOLVE_H_
# define SOLVE_H_

# include <math.h>

int	solve_cubic(double *coef, double *res);
int	solve_quadratic(double *coef, double *res);
int	solve_quartic(double *coef, double *res);

#endif /* !SOLVE_H_ */
