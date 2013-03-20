/*
** init.c for init in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Feb 25 17:22:40 2013 luc sinet
** Last update Sun Mar 17 16:38:30 2013 luc sinet
*/

#include "pars.h"
#include "main.h"

void	init_light(t_lig *ltab, t_obj *opt)
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
      i++;
    }
}

void    init_elem(t_elem *tab, t_obj *opt)
{
  int   i;
  int   x;

  i = 0;
  while (i < opt->nb_shape)
    {
      x = 0;
      tab[i].type = -1;
      while (x < 3)
	tab[i].pos[x++] = IVAL;
      x = 0;
      while (x < 4)
	tab[i].angle[x++] = IVAL;
      tab[i].color = 0x000000;
      tab[i].rayon = 0;
      tab[i].bright = 1.0;
      i++;
    }
}
