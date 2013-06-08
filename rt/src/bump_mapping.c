/*
** bump_mapping.c for bump_mapping in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed May 22 12:12:01 2013 luc sinet
** Last update Wed May 22 14:52:49 2013 luc sinet
*/

#include <math.h>
#include "main.h"
#include "light.h"
#include "perlin.h"

void		apply_bump(double *nvec, double *obj_coor, double ratio)
{
  double	bump_vec[3];
  double	temp;

  unitaire(nvec);
  bump_vec[0] = (get_perlin(0.1 * obj_coor[0], 0.1
			    * obj_coor[1], 0.1 * obj_coor[2]));
  bump_vec[1] = (get_perlin(0.1 * obj_coor[1], 0.1
			    * obj_coor[2], 0.1 * obj_coor[0]));
  bump_vec[2] = (get_perlin(0.1 * obj_coor[2], 0.1
			    * obj_coor[0], 0.1 * obj_coor[1]));
  nvec[0] = (1.0f - ratio) * nvec[0] + ratio * bump_vec[0];
  nvec[1] = (1.0f - ratio) * nvec[1] + ratio * bump_vec[1];
  nvec[2] = (1.0f - ratio) * nvec[2] + ratio * bump_vec[2];
  if ((temp = scale(nvec, nvec)) <= ZERO)
    return ;
  temp = 1.0 / sqrt(temp);
  nvec[0] *= temp;
  nvec[1] *= temp;
  nvec[2] *= temp;
}
