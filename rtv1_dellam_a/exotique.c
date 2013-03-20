/*
** exotique.c for exotique in /home/adrien/Projet/Igraph/RT_V1/Test
** 
** Made by Adrien
** Login   <adrien@adrien>
** 
** Started on  Fri Mar 15 16:19:57 2013 Adrien
** Last update Sat Mar 16 22:52:29 2013 Adrien
*/

#include "include.h"

float		paraboloide(t_rt *rt, t_obj *obj)
{
  float		eq[3];
  float		delta;
  t_coord	pos;
  t_coord	vec;

  pos = pos_reality(rt, obj, &vec);
  eq[0] = (vec.x * vec.x) + (vec.y * vec.y);
  eq[1] = 2 * ((pos.x * vec.x) + (pos.y * vec.y)) - (obj->x * vec.z);
  eq[2] = (pos.x * pos.x) + (pos.y * pos.y)
    - (pos.z * obj->x);
  delta = (eq[1] * eq[1]) - (4 * eq[0] * eq[2]);
  if (delta > 0 && eq[0] != 0)
    return (min(((-eq[1] + sqrt(delta)) / (2 * eq[0])),
                ((-eq[1] - sqrt(delta)) / (2 * eq[0]))));
  else if (delta == 0 && eq[0] != 0)
    {
      if ((-eq[1]) / (2 * eq[0]) > 0)
        return ((-eq[1]) / (2 * eq[0]));
    }
  else if (eq[0] == 0)
    return (-eq[2] / eq[1]);
  return (-1.0);
}

t_coord norparaboloide(t_coord pos, t_coord *pt, t_obj *obj)
{
  pos.x = pt->x - obj->pos.x;
  pos.y = pt->y - obj->pos.y;
  pos.z = (-obj->x) - obj->pos.z;
  rotate_x(obj->rot.x, &pos);
  rotate_y(obj->rot.y, &pos);
  rotate_z(obj->rot.z, &pos);
  return (pos);
}

float		hyperboloide(t_rt *rt, t_obj *obj)
{
  float		eq[3];
  float		delta;
  t_coord	pos;
  t_coord	vec;

  pos = pos_reality(rt, obj, &vec);
  eq[0] = (vec.x * vec.x) + (vec.y * vec.y) - (obj->x * (vec.z * vec.z));
  eq[1] = 2 * ((pos.x * vec.x) + (pos.y * vec.y) - (obj->x * (vec.z * pos.z)));
  eq[2] = (pos.x * pos.x) + (pos.y * pos.y) - (pos.z *  pos.z * obj->x) - 1;
  delta = (eq[1] * eq[1]) - (4 * eq[0] * eq[2]);
  if (delta > 0 && eq[0] != 0)
    return (min(((-eq[1] + sqrt(delta)) / (2 * eq[0])),
                ((-eq[1] - sqrt(delta)) / (2 * eq[0]))));
  else if (delta == 0 && eq[0] != 0)
    {
      if ((-eq[1]) / (2 * eq[0]) > 0)
        return ((-eq[1]) / (2 * eq[0]));
    }
  else if (eq[0] == 0)
    return (-eq[2] / eq[1]);
  return (-1.0);
}

t_coord norhyperboloide(t_coord pos, t_coord *pt, t_obj *obj)
{
  pos.x = pt->x - obj->pos.x;
  pos.y = pt->y - obj->pos.y;
  pos.z = ((-obj->x) * pt->z) - obj->pos.z;
  rotate_x(obj->rot.x, &pos);
  rotate_y(obj->rot.y, &pos);
  rotate_z(obj->rot.z, &pos);
  return (pos);
}
