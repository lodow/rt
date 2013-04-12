/*
** init.c for init in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Feb 25 17:22:40 2013 luc sinet
** Last update Fri Apr 12 15:40:47 2013 Adrien Della Maggiora
*/

#include <math.h>
#include "../include/main.h"
#include "../include/pars.h"

void	init_light(t_lig *ltab, t_pars *opt)
{
  int	i;
  int	x;

  i = 0;
  while (i < opt->nb_light)
    {
      x = 0;
      ltab[i].on = 0;
      while (x < 3)
	ltab[i].pos[x++] = IVAL;
      ltab[i].intensity = 1.0;
      ltab[i].ambient = 0;
      i++;
    }
}

void	init_cos(t_obj *obj)
{
  int	i;
  int	x;

  i = 0;
  while (obj[i].type != -1)
    {
      x = 0;
      while (x < 3)
	{
	  obj[i].ocos[x] = cos(-RAD(obj[i].angle[x]));
	  obj[i].osin[x] = sin(-RAD(obj[i].angle[x]));
	  obj[i].acos[x] = cos(RAD(obj[i].angle[x]));
	  obj[i].asin[x] = sin(RAD(obj[i].angle[x]));
	  ++x;
	}
      if (obj[i].type == 2)
	{
	  obj[i].ocos[x] = cos(RAD(obj[i].angle[x]));
	  obj[i].osin[x] = sin(RAD(obj[i].angle[x]));
	}
      ++i;
    }
}

void	init_nb_obj(t_pars *opt)
{
  opt->accol = 0;
  opt->nb_line = 0;
  opt->nb_shape = 0;
  opt->nb_light = 0;
  opt->nb_cam = 0;
  opt->nb_opt = 0;
}

void	init_shapes(char **shape)
{
  shape[0] = "Sphere";
  shape[1] = "Cone";
  shape[2] = "Cylinder";
  shape[3] = "Plan";
  shape[4] = "Light";
  shape[5] = "Cam";
  shape[6] = "Option";
  shape[7] = "{";
  shape[8] = "}";
}
