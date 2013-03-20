/*
** eq_droit.c for eq_droit in /home/dellam_a/Projet/Igraph/RT_V1
**
** Made by Adrien dellamaggiora
** Login   <dellam_a@epitech.eu>
**
** Started on  Mon Feb  4 18:32:23 2013 Adrien dellamaggiora
** Last update Sat Mar 16 22:47:45 2013 Adrien
*/

#include "include.h"

float	min(float a, float b)
{
  if (a < b && a > 0)
    return (a);
  else if (b < a && b > 0)
    return (b);
  else if (a < 0 && b > 0)
    return (b);
  else if (b < 0 && a > 0)
    return (a);
  else
    return (a);
}

void	eq_droite(t_rt *rt, t_coord *pixel)
{
  rt->droite.x = pixel->x - rt->eye.x;
  rt->droite.y = pixel->y - rt->eye.y;
  rt->droite.z = pixel->z - rt->eye.z;
}

t_coord		pos_reality(t_rt *rt, t_obj *obj, t_coord *vec)
{
  t_coord	res;

  res.x = (rt->eye.x - obj->pos.x);
  res.y = (rt->eye.y - obj->pos.y);
  res.z = (rt->eye.z - obj->pos.z);
  vec->x = rt->droite.x;
  vec->y = rt->droite.y;
  vec->z = rt->droite.z;
  rotate_x((360 - obj->rot.x), vec);
  rotate_y((360 - obj->rot.z), vec);
  rotate_z((360 - obj->rot.y), vec);
  return (res);
}
