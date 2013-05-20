/*
** init_elem.c for init_elem in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Apr 10 23:01:41 2013 luc sinet
** Last update Mon May 20 11:40:02 2013 luc sinet
*/

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "pars.h"

void	init_tab_names(char **shape)
{
  shape[0] = "Sphere";
  shape[1] = "Plan";
  shape[2] = "Cone";
  shape[3] = "Cylinder";
  shape[4] = "Circle";
  shape[5] = "Square";
  shape[6] = "Triangle";
  shape[7] = "Paraboloide";
  shape[8] = "Hyperboloide";
  shape[9] = "Moebius";
  shape[10] = "Tangle";
}

void	init_limit_angle(double *pert, double *angle)
{
  int	i;

  i = 0;
  while (i < 6)
    {
      if (i % 2 == 0)
	pert[i] = -1;
      else
	pert[i] = 5;
      if (i < 4)
	angle[i] = IVAL;
      ++i;
    }
}

void	init_limits(double *limit)
{
  int	i;

  i = 0;
  while (i < 9)
    {
      limit[i] = IVAL;
      ++i;
    }
}

void	init_single_elem(t_obj *obj)
{
  int	x;

  x = 0;
  obj->type = -1;
  while (x < 3)
    {
      obj->pos[x] = IVAL;
      obj->color[x] = 0;
      obj->normal[x] = 0;
      obj->v1[x] = 0;
      obj->v2[x++] = 0;
    }
  init_limit_angle(obj->pert, obj->angle);
  init_limits(obj->limit);
  obj->size = 0;
  obj->bright = 1.0;
  obj->texture = NULL;
  obj->indice[0] = 0.0;
  obj->indice[1] = 1.0;
  obj->indice[2] = 0.0;
  obj->indice[3] = 0.5;
  obj->normal[3] = 0;
  obj->perlin = -1;
  obj->checker = 0;
}

void    init_elem(t_obj *tab, t_pars *opt)
{
  int   i;

  i = 0;
  while (i <= opt->nb_shape)
    {
      init_single_elem(&tab[i]);
      ++i;
    }
}
