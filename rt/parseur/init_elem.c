/*
** init_elem.c for init_elem in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Apr 10 23:01:41 2013 luc sinet
** Last update Thu May  9 11:04:21 2013 Adrien Della Maggiora
*/

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

void    init_elem(t_obj *tab, t_pars *opt)
{
  int   i;
  int   x;

  i = 0;
  while (i < opt->nb_shape + 1)
    {
      x = 0;
      tab[i].type = -1;
      while (x < 3)
	{
	  tab[i].pos[x] = IVAL;
	  tab[i].color[x] = 0;
	  tab[i].v1[x] = 0;
	  tab[i].v2[x++] = 0;
	}
      init_limit_angle(tab[i].pert, tab[i].angle);
      init_limits(tab[i].limit);
      tab[i].rayon = 0;
      tab[i].bright = 1.0;
      tab[i].indice[0] = 0;
      tab[i].indice[1] = 1;
      tab[i].indice[2] = 0;
      tab[i].indice[3] = 0;
      i++;
    }
}
