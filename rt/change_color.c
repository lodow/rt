/*
** change_color.c for change_color in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Mar 21 16:50:09 2013 luc sinet
** Last update Thu Mar 21 17:21:38 2013 luc sinet
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
