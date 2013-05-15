/*
** tore.c for rt in /tmp/rt/rt
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Tue May 14 17:26:07 2013 etienne debas
** Last update Wed May 15 16:49:22 2013 etienne debas
*/

#include <math.h>
#include "main.h"
#include "inter.h"
#include "light.h"
# define SIZE 1

double		tore(double *cam, double *vec, t_obj *obj)
{
  double	c[5];
  double	k[4];

  tab_set((int *)k, 4);
  c[0] = powf(powf(vec[0], 2) + powf(vec[1], 2) + powf(vec[2], 2), 2);

  c[1] = (4.0
	  * (powf(vec[0], 2) + powf(vec[1], 2) + powf(vec[2], 2))
	  * (vec[0] * cam[0] + vec[1] * cam[1] + vec[2] * cam[2]));

  c[2] = (2.0
	  * (powf(vec[0], 2) + powf(vec[1], 2) + powf(vec[2], 2))
	  * (powf(cam[0], 2) + powf(cam[1], 2) + powf(cam[2], 2)
	     + powf((double)obj->size, 2) - powf((double)SIZE, 2))
	  + (powf((vec[0] * cam[0] + vec[1] * cam[1] + vec[2] * cam[2]), 2))
	  - (4.0 * powf((double)obj->size, 2) * (powf(vec[0], 2) + powf(vec[2], 2))));

  c[3] = (4.0
	  * (vec[0] * cam[0] + vec[1] * cam[1] + vec[2] * cam[2])
	  * (powf(cam[0], 2) + powf(cam[1], 2) + powf(cam[2], 2)
	     + (powf((double)obj->size, 2) - powf((double)SIZE, 2)))
	  - (8.0 * powf((double)obj->size, 2) * (vec[0] * cam[0] + vec[2] * cam[2])));

  c[4] = (powf((powf(cam[0], 2) + powf(cam[1], 2) + powf(cam[2], 2)
		+ powf((double)obj->size, 2) - powf((double)SIZE, 2)), 2)
	  - (4.0 * powf((double)obj->size, 2) * (powf(cam[0], 2) + powf(cam[2], 2))));
  return (solve_quad(c, k));
}
