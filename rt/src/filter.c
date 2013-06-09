/*
** filter.c for filter in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue May 21 13:57:11 2013 luc sinet
** Last update Sun Jun  2 16:56:25 2013 luc sinet
*/

#include <math.h>
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

double	encode_srgb(double comp, double gamma)
{
  if (comp < 0.0031308)
    return (12.92 * comp);
  else
    return (255.0 * pow(comp / 255, gamma));
}

unsigned int	gamma_filter(unsigned int color, double gamma)
{
  unsigned char	comp[3];

  gamma = 1.0 / gamma;
  decomp_color(color, comp);
  comp[0] = LIMIT(encode_srgb(comp[0], gamma), 0, 255);
  comp[1] = LIMIT(encode_srgb(comp[1], gamma), 0, 255);
  comp[2] = LIMIT(encode_srgb(comp[2], gamma), 0, 255);
  return (recomp_color(comp));
}

unsigned int	filter_color(unsigned int color, t_opt *opt)
{
  if (opt->filter == 1)
    color = filter_sepia(color);
  if (opt->filter == 2)
    color = filter_grey(color);
  if (opt->gamma != -1)
    color = gamma_filter(color, opt->gamma);
  if (opt->filter == 3)
    color = revers_filter(color, opt);
  if (opt->contrast != 1.0)
    color = apply_contrast(color, opt);
  return (color);
}
