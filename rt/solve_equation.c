/*
** solve_equation.c for solve_eq in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri Mar 29 10:47:30 2013 luc sinet
** Last update Fri Mar 29 12:50:33 2013 luc sinet
*/



void	fourth(double *c, double *p)
{
  p[0] = ((-3.0 * pow(c[1], 2)) / (8.0 * pow(c[0], 2))) + (c[2] / c[0]);
  p[1] = (pow(c[1], 3) / (8.0 * pow(c[0], 3)))
    - ((c[1] * c[2]) / (2.0 * pow(c[0], 2))) + (c[3] / c[0]);
  p[2] = -3.0 * pow((c[1] / (4.0 * c[0])), 4)
    + ((pow(c[1], 2) * c[2]) / (16.0 * pow(c[0], 3)))
    + ((c[1] * c[3]) / (4.0 * pow(c[0], 2)))
    + (c[4] / c[0]);
}

void	x_res(double *p, double *x)
{
  x[0] = sqrt((p[0] / 2.0) + sqrt((pos(p[0], 2) / 4.0) - p[2]));
  x[1] = sqrt((p[0] / 2.0) - sqrt((pos(p[0], 2) / 4.0) - p[2]));
  x[2] = -sqrt((p[0] / 2.0) + sqrt((pos(p[0], 2) / 4.0) - p[2]));
  x[3] = -sqrt((p[0] / 2.0) - sqrt((pos(p[0], 2) / 4.0) - p[2]));
}

void	new_res(double *p, double *x)
{

}
