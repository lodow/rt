/*
** detect_shadows.c for detect_shadows in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Apr 10 10:30:07 2013 luc sinet
** Last update Wed Apr 10 10:34:13 2013 luc sinet
*/

#include "main.h"
#include "change_color.h"

int		get_color_diff(unsigned int pixel1, unsigned int pixel2)
{
  unsigned char	cola[3];
  unsigned char	colb[3];
  int		diff;

  decomp_color(pixel1, cola);
  decomp_color(pixel2, colb);
  diff = ABS(cola[0] - colb[0]);
  diff += ABS(cola[1] - colb[1]);
  diff += ABS(cola[2] - colb[2]);
  return (diff);
}
