/*
** exotique.c for exotique in /home/adrien/Projet/Igraph/RT_V1/Test
** 
** Made by Adrien
** Login   <adrien@adrien>
** 
** Started on  Fri Mar 15 16:19:57 2013 Adrien
** Last update Thu May  9 10:47:33 2013 Adrien Della Maggiora
*/

#include "main.h"

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

/*t_coord norparaboloide(t_coord pos, t_coord *pt, t_obj *obj)
{
  pos.x = pt->x - obj->pos.x;
  pos.y = pt->y - obj->pos.y;
  pos.z = (-obj->x) - obj->pos.z;
  rotate_x(obj->rot.x, &pos);
  rotate_y(obj->rot.y, &pos);
  rotate_z(obj->rot.z, &pos);
  return (pos);
  }*/

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

/*t_coord norhyperboloide(t_coord pos, t_coord *pt, t_obj *obj)
{
  pos.x = pt->x - obj->pos.x;
  pos.y = pt->y - obj->pos.y;
  pos.z = ((-obj->x) * pt->z) - obj->pos.z;
  rotate_x(obj->rot.x, &pos);
  rotate_y(obj->rot.y, &pos);
  rotate_z(obj->rot.z, &pos);
  return (pos);
}
*/
