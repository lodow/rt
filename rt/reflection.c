/*
** reflection.c for reflection in /tmp/rt/rt
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Tue Apr  2 18:25:49 2013 etienne debas
** Last update Tue Apr  2 20:47:12 2013 etienne debas
*/

#include <math.h>
#include "main.h"
#include "change_color.h"
#include "light.h"

t_vec		get_vec_reflection(double lvec[3], double nvec[3], double scalar)
{
  t_vec		vec_reflection;

  vec_reflection.vx = lvec[0] - 2 * scalar * nvec[0];
  vec_reflection.vx = lvec[1] - 2 * scalar * nvec[1];
  vec_reflection.vx = lvec[2] - 2 * scalar * nvec[2];
  return (vec_reflection);
}

/* float		vec_to_tab(t_vec *vec) */
/* { */
/*   float		tab[3]; */

/*   tab[0] = vec->vx; */
/*   tab[1] = vec->vy; */
/*   tab[2] = vec->vz; */
/*   return (tab); */
/* } */

double		get_scalar(double tab1[3], double tab2[3])
{
  double		scalar;

  scalar = tab1[0] * tab2[0] + tab1[1] * tab2[1] + tab1[2] * tab2[2];
  return (scalar);
}

double		get_angle_specular(double lvec[3], double nvec[3], t_lco *lpt)
{
  double	bnorme;
  double	angle;
  t_vec		reflection;
  double	scalar;

  scalar = get_scalar(lvec, nvec);
  reflection = get_vec_reflection(lvec, nvec, scalar);
  bnorme = (sqrt(pow(reflection.vx, 2) + pow(reflection.vy, 2)
		 + pow(reflection.vz, 2))
	    * sqrt(pow(lvec[0], 2) + pow(lvec[1], 2)
		   + pow(lvec[2], 2)));
  angle = (reflection.vx * lvec[0]
	   + reflection.vy * lvec[1]
	   + reflection.vz * lvec[2]) / bnorme;
  angle = acos(angle);
  return (angle);
}
