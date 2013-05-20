/*
** normals.c for normals in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun Mar 31 13:20:23 2013 luc sinet
** Last update Mon May 20 20:37:37 2013 etienne debas
*/

#include <math.h>
#include "main.h"
#include "light.h"
# define SIZE 10

void	perturb_normal(double *nvec, double *obj_coor, double *pert)
{
  if ((int)pert[0] == 1)
    nvec[0] = nvec[0] + cos(obj_coor[0] / pert[1])
      * (norme_vec(nvec) / pert[1]);
  if ((int)pert[2] == 1)
    nvec[1] = nvec[1] + cos(obj_coor[1] / pert[3])
      * (norme_vec(nvec) / pert[3]);
  if ((int)pert[4] == 1)
    nvec[2] = nvec[2] + cos(obj_coor[2] / pert[5])
      * (norme_vec(nvec) / pert[5]);
}

void	sphere_normal(double *nvec, double *obj_coor, double *pert, t_obj *obj)
{
  (void)(obj);
  nvec[0] = obj_coor[0];
  nvec[1] = obj_coor[1];
  nvec[2] = obj_coor[2];
  perturb_normal(nvec, obj_coor, pert);
}

void	plan_normal(double *nvec, double *obj_coor, double *pert, t_obj *obj)
{
  (void)(obj);
  nvec[0] = obj->normal[0];
  nvec[1] = obj->normal[1];
  nvec[2] = obj->normal[2];
  perturb_normal(nvec, obj_coor, pert);
}

void	cone_normal(double *nvec, double *obj_coor, double *pert, t_obj *obj)
{
  (void)(obj);
  nvec[0] = obj_coor[0];
  nvec[1] = obj_coor[1];
  nvec[2] = -0.6 * obj_coor[2];
  perturb_normal(nvec, obj_coor, pert);
}

void	cylinder_normal(double *nvec, double *obj_coor, double *pert,
			t_obj *obj)
{
  (void)(obj);
  nvec[0] = obj_coor[0];
  nvec[1] = obj_coor[1];
  nvec[2] = 0;
  perturb_normal(nvec, obj_coor, pert);
}

void	moebius_normal(double *nvec, double *obj_coor, double *pert, t_obj *obj)
{
  (void)(obj);
  nvec[0] = obj_coor[0];
  nvec[1] = obj_coor[1];
  nvec[2] = obj_coor[2];
  perturb_normal(nvec, obj_coor, pert);
}

void	tangle_normal(double *nvec, double *obj_coor, double *pert, t_obj *obj)
{
  nvec[0] = (4.0 * obj_coor[0] * (powf(obj_coor[0], 2)
				  + powf(obj_coor[1], 2)
				  + powf(obj_coor[2], 2)
				  - powf((double)obj->size, 2)
				  - powf((double)SIZE, 2)));
  nvec[1] = (4.0 * obj_coor[1] * (powf(obj_coor[0], 2)
				  + powf(obj_coor[1], 2)
				  + powf(obj_coor[2], 2)
				  - powf((double)obj->size, 2)
				  - powf((double)SIZE, 2)));
  nvec[2] = (4.0 * obj_coor[2] * (powf(obj_coor[0], 2)
				  + powf(obj_coor[1], 2)
				  + powf(obj_coor[2], 2)
				  - powf((double)obj->size, 2)
				  - powf((double)SIZE, 2))
	     + (8.0 * powf((double)obj->size, 2) * powf(obj_coor[2], 2)));
  perturb_normal(nvec, obj_coor, pert);
}

void	tore_normal(double *nvec, double *obj_coor, double *pert, t_obj *obj)
{
  int	a;

  a = 1;
  if (obj_coor[2] < obj->pos[2])
    a = -1;
  nvec[0] = (4.0 * obj_coor[0] * (powf(obj_coor[0], 2)
				  + powf(obj_coor[1], 2)
				  + powf(obj_coor[2], 2)
				  - powf((double)obj->size, 2)
				  - powf((double)SIZE, 2)));
  nvec[1] = (4.0 * obj_coor[1] * (powf(obj_coor[0], 2)
				  + powf(obj_coor[1], 2)
				  + powf(obj_coor[2], 2)
				  - powf((double)obj->size, 2)
				  - powf((double)SIZE, 2)));
  nvec[2] = a * (4.0 * obj_coor[2] * (powf(obj_coor[0], 2)
				      + powf(obj_coor[1], 2)
				      + powf(obj_coor[2], 2)
				      - powf((double)obj->size, 2)
				      - powf((double)SIZE, 2))
		 + (8.0 * powf((double)obj->size, 2) * powf(obj_coor[2], 2)));
  perturb_normal(nvec, obj_coor, pert);
}
