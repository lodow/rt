/*
** init_elem.c for init_elem in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Apr 10 23:01:41 2013 luc sinet
** Last update Sun Apr 14 12:21:57 2013 luc sinet
*/

#include "../include/main.h"
#include "../include/pars.h"

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
      if (i % 3 == 0)
	limit[i] = -1;
      else
	limit[i] = IVAL;
      ++i;
    }
}

void    init_elem(t_obj *tab, t_pars *opt)
{
  int   i;
  int   x;

  i = 0;
  while (i < opt->nb_shape)
    {
      x = 0;
      tab[i].type = -1;
      while (x < 3)
	{
	  tab[i].pos[x] = IVAL;
	  tab[i].color[x++] = 0;
	}
      init_limit_angle(tab[i].pert, tab[i].angle);
      init_limits(tab[i].limit);
      tab[i].rayon = 0;
      tab[i].bright = 1.0;
      tab[i].alpha = 0;
      tab[i].n = 1;
      i++;
    }
}
