/*
** change_color.c for change_color in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Mar 21 16:50:09 2013 luc sinet
** Last update Mon Apr  8 12:11:39 2013 luc sinet
*/

#include "main.h"
#include "light.h"
#include "change_color.h"

void		apply_light_color(unsigned char *col_o, unsigned char *col_l,
				 double lg_i)
{
  double	a;
  double	b;

  a = 0.5 * lg_i;
  b = 1.0 - a;
  col_o[0] = b * (double)col_o[0] + a * (double)col_l[0];
  col_o[1] = b * (double)col_o[1] + a * (double)col_l[1];
  col_o[2] = b * (double)col_o[2] + a * (double)col_l[2];
}


unsigned int	apply_light(unsigned char *c, double cosa, t_obj *ept)
{
  c[0] = (double)c[0] * cosa * ept->bright;
  c[1] = (double)c[1] * cosa * ept->bright;
  c[2] = (double)c[2] * cosa * ept->bright;
  return (recomp_color(c));
}

void   	decomp_color(unsigned int color, unsigned char *ncolor)
{
  ncolor[2] = color & 0xFF;
  ncolor[1] = (color >> 8) & 0xFF;
  ncolor[0] = (color >> 16) & 0xFF;
}

unsigned int	recomp_color(unsigned char *color)
{
  unsigned int	ncolor;

  ncolor = color[0] << 8;
  ncolor = (ncolor | color[1]) << 8;
  ncolor = ncolor | color[2];
  return (ncolor);
}
