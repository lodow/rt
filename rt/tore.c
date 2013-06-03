/*
** tore.c for rt in /tmp/rt/rt
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Tue May 14 17:26:07 2013 etienne debas
** Last update Mon May 20 20:18:32 2013 etienne debas
*/

#include <math.h>
#include "main.h"
#include "inter.h"
#include "light.h"
#define SIZE 10

double		tore(double *cam, double *vec, t_obj *obj)
{
  double	c[5];
  double	k[4];

  tab_set((int *)k, 4);
  c[0] = pow(pow(vec[0], 2) + pow(vec[1], 2) + pow(vec[2], 2), 2);

  c[1] = 4.0
    * (vec[0] * cam[0] + vec[1] * cam[1] + vec[2] * cam[2])
    * (pow(vec[0], 2) + pow(vec[1], 2) + pow(vec[2], 2));

  c[2] = 4.0
    * pow(vec[0] * cam[0] + vec[1] * cam[1] + vec[2] * cam[2], 2)
    + 2.0
    * (pow(cam[0], 2) + pow(cam[1], 2) + pow(cam[2], 2)
	+ pow((double)obj->size[0], 2) - pow((double)SIZE, 2))
       * (pow(vec[0], 2) + pow(vec[1], 2) + pow(vec[2], 2))
    - (4.0 * pow((double)obj->size[0], 2))
    * (pow(vec[0], 2) + pow(vec[1], 2));

  c[3] = 2.0
    * (pow(cam[0], 2) + pow(cam[1], 2) + pow(cam[2], 2)
       + pow((double)obj->size[0], 2) - pow((double)SIZE, 2))
    * (2.0 * (vec[0] * cam[0] + vec[1] * cam[1] + vec[2] * cam[2]))
    - (4.0 * pow((double)obj->size[0], 2))
    * (2.0 * vec[0] * cam[0] + 2.0 * vec[1] * cam[1]);

  c[4] = pow(pow(cam[0], 2) + pow(cam[1], 2) + pow(cam[2], 2)
	      + pow((double)obj->size[0], 2) - pow((double)SIZE, 2), 2)
    - (4.0 * pow((double)obj->size[0], 2))
    * (pow(cam[0], 2) + pow(cam[1], 2));
  return (solve_quad(c, k));
}
