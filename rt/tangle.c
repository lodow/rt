/*
** tangle.c for tangle in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri Mar 29 10:18:26 2013 luc sinet
** Last update Tue May 14 17:55:44 2013 etienne debas
*/

#include <math.h>
#include "main.h"
#include "inter.h"
#include "light.h"

double		tangle(double *cam, double *vec, t_obj *ept)
{
  double	c[5];
  double	k[4];

  c[0] = pow(vec[0], 4) + pow(vec[1], 4) + pow(vec[2], 4);
  c[1] = 4.0 * (pow(vec[0], 3) * cam[0] + pow(vec[1], 3) * cam[1]
		+ pow(vec[2], 3) * cam[2]);
  c[2] = 6.0 * (pow(vec[0], 2) * cam[0] + pow(vec[1], 2) * cam[1]
		+ pow(vec[2], 2) * cam[2])
    - 5.0 * (pow(vec[0], 2) + pow(vec[1], 2) + pow(vec[2], 2));
  c[3] = 4.0 * (pow(cam[0], 3) * vec[0] + pow(cam[1], 3) * vec[1]
		+ pow(cam[1], 3) * vec[1])
    - 10.0 * (vec[0] * cam[0] + cam[1] * vec[1] + cam[1] * vec[1]);
  c[4] = pow(cam[0], 4) + pow(cam[1], 4) + pow(cam[2], 4)
    - 5.0 * (pow(cam[0], 2) + pow(cam[1], 2) + pow(cam[2], 2));
  return (solve_quad(c, k));
}
