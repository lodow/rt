/*
** inter_third.c for rt in /tmp/rt/rt
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Mon Apr 22 23:06:51 2013 etienne debas
** Last update Thu May  9 10:32:20 2013 Adrien Della Maggiora
*/

#include <math.h>
#include "main.h"

double		moebius(double *cam, double *vec, t_obj *ept)
{
  double	a[4];

  (void)ept;
  a[0] = (pow(vec[0], 2) * vec[1] + pow(vec[2], 2) * vec[1] + pow(vec[1], 3)
	  - 2 * pow(vec[0], 2) * vec[2] - 2 * pow(vec[1], 2) * vec[2]);
  a[1] = (pow(vec[0], 2) * cam[1] + 2 * cam[0] * vec[0] * vec[1] + pow(vec[2], 2)
	  * cam[1] + 2 * cam[2] * vec[1] * vec[2] + pow(vec[2], 2) * cam[1]
	  + 2 * cam[1] * pow(vec[1], 2) - 2 * vec[0] * vec[2] - 2 * pow(vec[2], 2)
	  * cam[2] - 4 * cam[0] * vec[0] * vec[2] - 2 * pow(vec[1], 2) * cam[2]
	  - 4 * cam[1] * vec[1] * vec[2]);
  a[2] = (2 * cam[0] * vec[0] * cam[1] + cam[0] * vec[1] + 2 * cam[2] * vec[2] * cam[1]
	  + pow(cam[2], 2) * vec[1] + 2 * pow(cam[1], 2) * vec[1] + vec[1] * pow(cam[1], 2)
	  + vec[1] - 2 * cam[0] * vec[2] - 2 * vec[0] * cam[2] - 4
	  * cam[0] * vec[0] * cam[2] - 2 * pow(cam[0], 2) * vec[2] - 4
	  * cam[1] * vec[1] * cam[2] - 2 * pow(cam[1], 2) * vec[2]);
  a[3] = (pow(cam[0], 2) * cam[1] + pow(cam[2], 2) * cam[1]
	  + pow(cam[1], 3) - cam[1] - 2 * cam[0] * cam[2]
	  - 2 * pow(cam[0], 2) * cam[2] - 2 * pow(cam[1], 2) * cam[2]);
  return (solve_third(a));
}
