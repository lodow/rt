/*
** calc_vec.c for calc_vec in /home/adrien/Projet/rt/rt/parseur
**
** Made by Adrien Della Maggiora
** Login   <adrien@mint>
**
** Started on  Wed May  8 18:10:25 2013 Adrien Della Maggiora
** Last update Sat May 11 13:21:44 2013 Adrien Della Maggiora
*/

#include "main.h"

void	calc_vec(double *point, t_obj *obj)
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
}
