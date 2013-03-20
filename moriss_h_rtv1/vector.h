/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sun Mar 10 18:34:38 2013 Hugues
*/

#ifndef VECTOR_H_
# define VECTOR_H_

# include <stdlib.h>
# include <math.h>

typedef struct	s_vecteur3d
{
  float		x;
  float		y;
  float		z;
}		t_vector3d;

float	dist_vect(t_vector3d *vec1);
void	init_vect(float x, float y, float z, t_vector3d *res);
void	add_vect(t_vector3d *vec1, t_vector3d *vec2, t_vector3d *res);
void	mul_vect(t_vector3d *vec1, t_vector3d *vec2, t_vector3d *res);
void	mul_vec_float(t_vector3d *vec, float a, t_vector3d *res);
void	sub_vect(t_vector3d *vec1, t_vector3d *vec2, t_vector3d *res);

#endif
