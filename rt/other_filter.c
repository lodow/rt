/*
** other_filter.c for other_filter in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue May 28 13:44:12 2013 luc sinet
** Last update Wed May 29 19:34:34 2013 luc sinet
*/

#include "main.h"
#include "change_color.h"
#include "pars.h"

unsigned int	revers_filter(unsigned int color, t_opt *opt)
{
  unsigned char	comp[3];

  decomp_color(color, comp);
  comp[0] = LIMIT(2.0 * (128 - comp[0]) + comp[0], 0, 255);
  comp[1] = LIMIT(2.0 * (128 - comp[1]) + comp[1], 0, 255);
  comp[2] = LIMIT(2.0 * (128 - comp[2]) + comp[2], 0, 255);
  return (recomp_color(comp));
}
