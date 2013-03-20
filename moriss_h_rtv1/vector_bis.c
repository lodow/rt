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

void	mul_vec_float(t_vector3d *vec, float a, t_vector3d *res)
{
  if ((res != NULL) && (vec != NULL))
    {
      res->x = vec->x * a;
      res->y = vec->y * a;
      res->z = vec->z * a;
    }
}
