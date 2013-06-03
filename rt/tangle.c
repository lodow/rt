/*
** hole_cube.c for rt in /home/debas_e//Desktop/projet/rt/rt
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Fri May 31 22:30:23 2013 etienne debas
** Last update Sat Jun  1 00:39:29 2013 etienne debas
*/

#include <math.h>
#include "main.h"
#include "inter.h"
#include "light.h"
#define SIZE 10

double		tangle(double *cam, double *vec, UNUSED t_obj *obj)
{
  double	c[5];
  double	k[4];

  c[0] = pow(vec[0], 4) + pow(vec[1], 4) + pow(vec[2], 4);

  c[1] = 4 * ((pow(vec[0], 3) * cam[0])
	      + (pow(vec[1], 3) * cam[1])
	      + (pow(vec[2], 3) * cam[2]));

  c[2] = 6 * ((pow(vec[0], 2) * pow(cam[0], 2))
	      + (pow(vec[1], 2) * pow(cam[1], 2))
	      + (pow(vec[2], 2) * pow(cam[2], 2)))
    - 10 * pow(obj->size[0], 2) * (pow(vec[0] , 2)
				   + pow(vec[1] , 2) + pow(vec[2], 2));

  c[3] = 4 * (pow(cam[0], 3) * vec[0]
	      + pow(cam[1], 3) * vec[1]
	      + pow(cam[2], 3) * vec[2])
    - 20 * pow(obj->size[0], 2) * (vec[0] * cam[0]
				   + vec[1] * cam[1]
				   + vec[2] * cam[2]);

  c[4] = pow(cam[0], 4) + pow(cam[1], 4) + pow(cam[2], 4)
    - 10 * pow(obj->size[0], 2) * (pow(cam[0], 2)
				   + pow(cam[1], 2)
				   + pow(cam[2], 2)) + 40 * pow(obj->size[0], 4);

  return (solve_quad(c, k));
}

