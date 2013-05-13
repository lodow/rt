/*
** calc_vec.c for calc_vec in /home/adrien/Projet/rt/rt/parseur
**
** Made by Adrien Della Maggiora
** Login   <adrien@mint>
**
** Started on  Wed May  8 18:10:25 2013 Adrien Della Maggiora
** Last update Mon May 13 15:12:19 2013 luc sinet
*/

#include "main.h"

void	calc_vec(double *point, double *normal, t_obj *obj)
{
  obj->v1[0] = (point[0] - point[3]);
  obj->v1[1] = (point[1] - point[4]);
  obj->v1[2] = (point[2] - point[5]);
  obj->v2[0] = (point[6] - point[3]);
  obj->v2[1] = (point[7] - point[4]);
  obj->v2[2] = (point[8] - point[5]);
  obj->pos[0] = point[0];
  obj->pos[1] = point[1];
  obj->pos[2] = point[2];
  obj->normal[0] = normal[0];
  obj->normal[1] = normal[1];
  obj->normal[2] = normal[2];
}
