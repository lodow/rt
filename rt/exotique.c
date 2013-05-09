/*
** exotique.c for exotique in /home/adrien/Projet/Igraph/RT_V1/Test
** 
** Made by Adrien
** Login   <adrien@adrien>
** 
** Started on  Fri Mar 15 16:19:57 2013 Adrien
** Last update Thu May  9 13:35:08 2013 Adrien Della Maggiora
*/

#include "main.h"
#include "light.h"

double		paraboloide(double *cam, double *vec, t_obj *ept)
{
  double	a[3];
  double	k[2];

  a[0] = (vec[0] * vec[0]) + (vec[1] * vec[1]);
  a[1] = 2 * ((cam[0] * vec[0]) + (cam[1] * vec[1]))
    - (ept->indice[3] * vec[2]);
  a[2] = (cam[0] * cam[0]) + (cam[1] * cam[1])
    - (cam[2] * ept->indice[3]);
  if (solve_second(a, k) == -1)
    return (-1);
  return (test_limit(cam, vec, k, ept->limit));
}

void	paraboloide_normal(double *nvec, double *obj_coor, double *pert,
			   t_obj *obj)
{
  nvec[0] = obj_coor[0];
  nvec[1] = obj_coor[1];
  nvec[2] = (-obj->indice[3]);
  perturb_normal(nvec, obj_coor, pert);
}

double		hyperboloide(double *cam, double *vec, t_obj *ept)
{
  double	a[3];
  double	k[2];

  a[0] = (vec[0] * vec[0]) + (vec[1] * vec[1]) - (ept->indice[3]
						  * (vec[2] * vec[2]));
  a[1] = 2 * ((cam[0] * vec[0]) + (cam[1] * vec[1]) - (ept->indice[3]
						       * (vec[2] * cam[2])));
  a[2] = (cam[0] * cam[0]) + (cam[1] * cam[1]) - (cam[2] *  cam[2]
						  * ept->indice[3]) - 1;
  if (solve_second(a, k) == -1)
    return (-1);
  return (test_limit(cam, vec, k, ept->limit));
}

void	hyperboloide_normal(double *nvec, double *obj_coor, double *pert,
			    t_obj *obj)
{
  nvec[0] = obj_coor[0];
  nvec[1] = obj_coor[1];
  nvec[2] = ((-obj->indice[3]) * obj_coor[2]);
  perturb_normal(nvec, obj_coor, pert);
}
