/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "vector.h"

void	init_vect(float x, float y, float z, t_vector3d *res)
{
  if (res != NULL)
    {
      res->x = x;
      res->y = y;
      res->z = z;
    }
}

void	add_vect(t_vector3d *vec1, t_vector3d *vec2, t_vector3d *res)
{
  if ((res != NULL) && (vec1 != NULL) && (vec2 != NULL))
    {
      res->x = vec1->x + vec2->x;
      res->y = vec1->y + vec2->y;
      res->z = vec1->z + vec2->z;
    }
}

void	mul_vect(t_vector3d *vec1, t_vector3d *vec2, t_vector3d *res)
{
  if ((res != NULL) && (vec1 != NULL) && (vec2 != NULL))
    {
      res->x = vec1->x * vec2->x;
      res->y = vec1->y * vec2->y;
      res->z = vec1->z * vec2->z;
    }
}

void	sub_vect(t_vector3d *vec1, t_vector3d *vec2, t_vector3d *res)
{
  if ((res != NULL) && (vec1 != NULL) && (vec2 != NULL))
    {
      res->x = vec1->x - vec2->x;
      res->y = vec1->y - vec2->y;
      res->z = vec1->z - vec2->z;
    }
}

float		dist_vect(t_vector3d *vec1)
{
  float		res;
  t_vector3d	vectmp;

  res = 0.0;
  init_vect(0.0, 0.0, 0.0, &vectmp);
  if (vec1 != NULL)
    {
      mul_vect(vec1, vec1, &vectmp);
      res = (vectmp.x + vectmp.y + vectmp.z);
      res = sqrt(res);
    }
  return (res);
}
