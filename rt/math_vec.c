/*
** math_vec.c for math_vec in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun Apr 14 17:32:06 2013 luc sinet
** Last update Mon Apr 22 01:00:07 2013 luc sinet
*/

#include <math.h>
#include "include/main.h"
#include "include/light.h"

void		unitaire(double *vec)
{
  double	norme;

  norme = sqrt(pow(vec[0], 2) + pow(vec[1], 2) + pow(vec[2], 2));
  if (norme)
    {
      vec[0] /= norme;
      vec[1] /= norme;
      vec[2] /= norme;
    }
}

void	vec_mult(double *vec1, double *vec2, double *vecr)
{
  vecr[0] = vec1[0] * vec2[0];
  vecr[1] = vec1[1] * vec2[1];
  vecr[2] = vec1[2] * vec2[2];
}

double	norme_vec(double *vec)
{
  return (sqrt(pow(vec[0], 2) + pow(vec[1], 2) + pow(vec[2], 2)));
}

double	scale(double *vec1, double *vec2)
{
  return (vec1[0] * vec2[0] + vec1[1] * vec2[1] + vec1[2] * vec2[2]);
}

double		cos_vector(double *vec1, double *vec2)
{
  double	bnorme;

  bnorme = norme_vec(vec1) * norme_vec(vec2);
  if (bnorme)
    return (scale(vec1, vec2) / bnorme);
  return (0);
}
