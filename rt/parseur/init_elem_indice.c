/*
** init_elem_indice.c for init_elem_indices in /home/sinet_l//rt/rt/parseur
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu May 30 21:18:05 2013 luc sinet
** Last update Tue Jun  4 11:27:59 2013 luc sinet
*/

#include "main.h"
#include "pars.h"

void	init_elem_indices(t_indice *ipt)
{
  ipt->indice[0] = 0.0;
  ipt->indice[1] = 1.0;
  ipt->indice[2] = 0.0;
  ipt->indice[3] = 0.5;
  ipt->perlin[0] = -1;
  ipt->perlin[1] = 0.02;
  ipt->checker = 0;
  ipt->bump = 0;
  ipt->rate = 1;
}
