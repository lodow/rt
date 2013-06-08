/*
** normals_exotique.c for rt in /home/debas_e//Desktop/projet/rt/rt
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Fri Jun  7 19:54:06 2013 etienne debas
** Last update Sat Jun  8 16:02:23 2013 maxime lavandier
*/

#include <math.h>
#include "main.h"
#include "light.h"

void	tangle_normal(double *nvec, double *obj_coor,
		      double *pert, t_obj *obj)
{
  nvec[0] = 4 * pow(obj_coor[0], 3) - 20 * pow(obj->size[0], 2) * obj_coor[0];
  nvec[1] = 4 * pow(obj_coor[1], 3) - 20 * pow(obj->size[0], 2) * obj_coor[1];
  nvec[2] = 4 * pow(obj_coor[2], 3) - 20 * pow(obj->size[0], 2) * obj_coor[2];
  perturb_normal(nvec, obj_coor, pert);
}

void		tore_normal(double *nvec, double *obj_coor,
			    double *pert, t_obj *obj)
{
  double	k;

  k = 4 * (pow(obj_coor[0], 2)
           + pow(obj_coor[1], 2)
           + pow(obj_coor[2], 2)
           + pow(obj->size[0], 2)
           - pow(obj->size[1], 2));
  nvec[0] = obj_coor[0] * k - 8.0 * pow(obj->size[0], 2) * obj_coor[0];
  nvec[1] = obj_coor[1] * k - 8.0 * pow(obj->size[0], 2) * obj_coor[1];
  nvec[2] = obj_coor[2] * k;
  perturb_normal(nvec, obj_coor, pert);
}
