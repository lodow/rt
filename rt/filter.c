/*
** filter.c for filter in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue May 21 13:57:11 2013 luc sinet
** Last update Tue May 21 15:10:30 2013 luc sinet
*/

#include "main.h"
#include "change_color.h"
#include "pars.h"

unsigned int	filter_sepia(unsigned int color)
{
  unsigned char	comp[3];
  unsigned char	o_color[3];

  decomp_color(color, comp);
  o_color[0]= LIMIT(comp[0] * 0.393 + comp[1] * 0.769
  		    + comp[2] * 0.189, 0, 255);
  o_color[1]= LIMIT(comp[0] * 0.349 + comp[1] * 0.686
  		    + comp[2] * 0.168, 0, 255);
  o_color[2]= LIMIT(comp[0] * 0.272 + comp[1] * 0.534
  		    + comp[2] * 0.131, 0, 255);
  return (recomp_color(o_color));
}

unsigned int	filter_grey(unsigned int color)
{
  unsigned char	comp[3];
  unsigned char	o_color[3];

  decomp_color(color, comp);
  o_color[0]= LIMIT(comp[0] * 0.33 + comp[1] * 0.33
  		    + comp[2] * 0.33, 0, 255);
  o_color[1]= LIMIT(comp[0] * 0.33 + comp[1] * 0.33
  		    + comp[2] * 0.33, 0, 255);
  o_color[2]= LIMIT(comp[0] * 0.33 + comp[1] * 0.33
  		    + comp[2] * 0.33, 0, 255);
  return (recomp_color(o_color));
}

unsigned int	filter_color(unsigned int color, int type)
{
  unsigned int	fin_color;

  fin_color = color;
  if (type == 1)
    fin_color = filter_sepia(color);
  else if (type == 2)
    fin_color = filter_grey(color);
  return (fin_color);
}
