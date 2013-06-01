/*
** init_elem_indice.c for init_elem_indices in /home/sinet_l//rt/rt/parseur
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu May 30 21:18:05 2013 luc sinet
** Last update Sat Jun  1 15:06:02 2013 luc sinet
*/

#include "main.h"
#include "pars.h"

void	init_elem_indices(t_obj *obj)
{
  obj->indice[0] = 0.0;
  obj->indice[1] = 1.0;
  obj->indice[2] = 0.0;
  obj->indice[3] = 0.5;
  obj->perlin[0] = -1;
  obj->perlin[1] = 0.02;
  obj->checker = 0;
  obj->bump = 0;
  obj->rate = 1;
}
