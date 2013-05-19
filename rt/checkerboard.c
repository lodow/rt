/*
** checkerboard.c for checkerboard in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon May 20 00:00:28 2013 luc sinet
** Last update Mon May 20 01:16:51 2013 luc sinet
*/

#include "main.h"

void		checkerboard_color(t_rt *rpt, double k,
				   unsigned char *color)
{
  double       	inter[3];

  get_impact(inter, rpt->cpt->pos, k, rpt->vpt->vec);
  inter[0] = ABS(inter[0]);
  inter[1] = ABS(inter[1]);
  inter[0] += 25;
  inter[1] += 25;
  if (((int)inter[0] % 100 <= 50 && (int)inter[1] % 100 <= 50) ||
      ((int)inter[0] % 100 > 50 && (int)inter[1] % 100 > 50))
    {
      color[0] = 0;
      color[1] = 0;
      color[2] = 0;
    }
  else
    {
      color[0] = 255;
      color[1] = 255;
      color[2] = 255;
    }
}
