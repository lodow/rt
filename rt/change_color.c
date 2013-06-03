/*
** change_color.c for change_color in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Mar 21 16:50:09 2013 luc sinet
** Last update Mon Jun  3 20:48:08 2013 luc sinet
*/

#include <math.h>
#include "main.h"
#include "light.h"
#include "change_color.h"

void		apply_light_color(unsigned char *col_o, unsigned char *col_l,
				  double lg_i, double bright)
{
  double	a;
  double	b;

  a = 0.6 * lg_i;
  b = 1.0 - a;
  bright /= 10;
  col_o[0] = col_o[0] * (1.0 - bright) + col_l[0] * bright;
  col_o[1] = col_o[1] * (1.0 - bright) + col_l[1] * bright;
  col_o[2] = col_o[2] * (1.0 - bright) + col_l[2] * bright;
  col_o[0] = b * (double)col_o[0] + a * (double)col_l[0];
  col_o[1] = b * (double)col_o[1] + a * (double)col_l[1];
  col_o[2] = b * (double)col_o[2] + a * (double)col_l[2];
}

unsigned int	apply_light(unsigned char *c, double cosa,
			    double sdw_coef)
{
  c[0] = (double)c[0] * cosa;
  c[1] = (double)c[1] * cosa;
  c[2] = (double)c[2] * cosa;
  return (darken_color(c, sdw_coef));
}

void   	decomp_color(unsigned int color, unsigned char *ncolor)
{
  ncolor[2] = color & 0xFF;
  ncolor[1] = (color >> 8) & 0xFF;
  ncolor[0] = (color >> 16) & 0xFF;
}

unsigned int	apply_fog(unsigned int color, double *fog, double distance)
{
  unsigned char	c[3];
  unsigned char	fog_color[3];
  double	ratio;

  if (fog[1] > ZERO)
    {
      decomp_color(color, c);
      decomp_color((unsigned int)(fog[0]), fog_color);
      ratio = exp(-(distance / fog[1]));
      c[0] = fog_color[0] * (1.0 - ratio)
	+ c[0] * ratio;
      c[1] = fog_color[1] * (1.0 - ratio)
	+ c[1] * ratio;
      c[2] = fog_color[2] * (1.0 - ratio)
	+ c[2] * ratio;
      return (recomp_color(c));
    }
  return (color);
}

unsigned int	recomp_color(unsigned char *color)
{
  unsigned int	ncolor;

  ncolor = color[0] << 8;
  ncolor = (ncolor | color[1]) << 8;
  ncolor = ncolor | color[2];
  return (ncolor);
}
