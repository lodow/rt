/*
** form.c for form in /home/dellam_a/Projet/Igraph/RT_V1
**
** Made by Adrien dellamaggiora
** Login   <dellam_a@epitech.eu>
**
** Started on  Fri Feb  8 10:17:41 2013 Adrien dellamaggiora
** Last update Tue Feb 12 17:03:33 2013 Adrien dellamaggiora
*/

#include "include.h"

float		sphere(t_rt *rt, t_obj *obj)
{
  float		eq[3];
  float		delta;
  t_coord	pos;
  t_coord	vec;

  pos = pos_reality(rt, obj, &vec);
  eq[0] = (vec.x * vec.x) + (vec.y * vec.y)
          + (vec.z * vec.z);
  eq[1] = 2 * ((pos.x * vec.x) + (pos.y * vec.y)
               + (pos.z * vec.z));
  eq[2] = (pos.x * pos.x) + (pos.y * pos.y)
          + (pos.z * pos.z) - (obj->r * obj->r);
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

float		plan(t_rt *rt, t_obj *obj)
{
  float		k;
  t_coord	pos;
  t_coord	vec;

  pos = pos_reality(rt, obj, &vec);
  if (vec.z != 0)
    {
      k = (- pos.z) / vec.z;
      if (k > 0)
        return (k);
    }
  return (-1);
}

float	cylindre(t_rt *rt, t_obj *obj)
{
  t_coord	pos;
  t_coord	vec;
  float		eq[3];
  float		delta;

  pos = pos_reality(rt, obj, &vec);
  eq[0] = (vec.x * vec.x) + (vec.y * vec.y);
  eq[1] = 2 * ((vec.x * pos.x ) + (vec.y * pos.y));
  eq[2] = (pos.x * pos.x) + (pos.y * pos.y) - (obj->r * obj->r);
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
  return (-1);
}

float	cone(t_rt *rt, t_obj *obj)
{
  t_coord	pos;
  t_coord	vec;
  float		eq[3];
  float		delta;

  pos = pos_reality(rt, obj, &vec);
  eq[0] = vec.x * vec.x * obj->x + vec.y * vec.y * obj->x
          - (vec.z * vec.z);
  eq[1] = 2 * (vec.x * pos.x * obj->x + vec.y * pos.y * obj->x
               - (vec.z * pos.z));
  eq[2] = pos.x * pos.x * obj->x + pos.y * pos.y * obj->x
          - (pos.z * pos.z);
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
  return (-1);
}
