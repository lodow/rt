/*
** ojbect.c for rtv1 in /home/debas_e//Desktop/projet/rt-v1
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Tue Feb 26 20:45:14 2013 etienne debas
** Last update Sun Mar 17 16:20:06 2013 etienne debas
*/

#include "../rtv1.h"

void		fill_k_obj(t_vector *vector, t_cam *cam, t_object *obj)
{
  int		i;
  t_cam		cam_tmp;
  t_vector	vector_tmp;

  i = 0;
  while (obj[i].type != -1)
    {
      cam_tmp = modif_cam(cam, obj[i]);
      cam_tmp = rotate_cam(&cam_tmp, obj[i]);
      vector_tmp = rotate_vector(vector, obj[i]);
      if (obj[i].type == SPHERE)
      	obj[i].k = make_k_sphere(&vector_tmp, &cam_tmp, obj[i]);
      else if (obj[i].type == PLAN)
      	obj[i].k = make_k_plan(&vector_tmp, &cam_tmp, obj[i]);
      else if (obj[i].type == CONE)
      	obj[i].k = make_k_cone(&vector_tmp, &cam_tmp, obj[i]);
      else if (obj[i].type == CYLINDRE)
	obj[i].k = make_k_cylindre(&vector_tmp, &cam_tmp, obj[i]);
      i++;
    }
}

t_object	get_nearest_obj(t_object *obj)
{
  double	k;
  int		i;
  int		nearest;

  i = 0;
  nearest = 0;
  k = 100000000;
  while (obj[i].type != -1)
    {
      if ((obj[i].k > 0.0) && (obj[i].k < k))
	{
	  k = obj[i].k;
	  nearest = i;
	}
      i++;
    }
  return (obj[nearest]);
}
