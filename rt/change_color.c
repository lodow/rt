/*
** change_color.c for change_color in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Mar 21 16:50:09 2013 luc sinet
** Last update Wed Mar 27 19:02:09 2013 luc sinet
*/

#include "main.h"
#include "light.h"

unsigned int	apply_light(unsigned int color, double cosa, t_lig *lpt)
{
  unsigned int	ncolor;
  unsigned char	r;
  unsigned char	g;
  unsigned char	b;

  b = (color & 0xff) * cosa * lpt->intensity;
  g = ((color >> 8) & 0xff) * cosa * lpt->intensity;
  r = ((color >> 16) & 0xff) * cosa * lpt->intensity;
  ncolor = r << 8;
  ncolor = (ncolor | g) << 8;
  ncolor = (ncolor | b);
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
