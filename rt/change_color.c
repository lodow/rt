/*
** change_color.c for change_color in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Mar 21 16:50:09 2013 luc sinet
** Last update Wed Mar 27 20:34:58 2013 luc sinet
*/

#include "main.h"
#include "light.h"

unsigned char	min(double x)
{
  if (x > 255.0)
    return (255);
  return (x);
}

unsigned int	apply_light(unsigned int color, double lamb, t_lig *lpt)
{
  unsigned int	ncolor;
  double	r;
  double	g;
  double	b;

  b = lamb * ((double)lpt->lcolor[2] / 255.0) * ((double)(color & 0xFF) / 255.0);
  g = lamb * ((double)lpt->lcolor[1] / 255.0) * ((double)((color >> 8) & 0xFF) / 255.0);
  r = lamb * ((double)lpt->lcolor[0] / 255.0) * ((double)((color >> 16) & 0xFF) / 255.0);
  ncolor = min(r * 255.0) << 8;
  ncolor = (ncolor | min(g * 255.0)) << 8;
  ncolor = (ncolor | min(b * 255.0));
  return (ncolor);
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
