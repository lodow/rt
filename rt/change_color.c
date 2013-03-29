/*
** change_color.c for change_color in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Mar 21 16:50:09 2013 luc sinet
** Last update Fri Mar 29 15:30:34 2013 luc sinet
*/

#include "main.h"
#include "light.h"
#include "change_color.h"

void	apply_brightness(unsigned char *col_i, unsigned char *col_l,
			 double intensity, double brighto)
{
  col_i[0] = ((double)col_i[0] * brighto
	      * (double)col_l[0] * intensity) / 255.0;
  col_i[1] = ((double)col_i[1] * brighto
	      * (double)col_l[1] * intensity) / 255.0;
  col_i[2] = ((double)col_i[2] * brighto
	      * (double)col_l[2] * intensity) / 255.0;
}


unsigned int	apply_light(unsigned int color, double cosa,
			    t_lig *lpt, t_obj *ept)
{
  unsigned char	c[3];

  decomp_color(color, c);
  apply_brightness(c, lpt->lcolor, lpt->intensity, ept->bright);
  /* Have to apply light intensity here*/
  c[0] = (double)c[0] * cosa;
  c[1] = (double)c[1] * cosa;
  c[2] = (double)c[2] * cosa;
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
