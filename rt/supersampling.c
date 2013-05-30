/*
** supersampling.c for supersampling in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri Apr  5 11:07:42 2013 luc sinet
** Last update Thu May 30 16:48:25 2013 luc sinet
*/

#include <math.h>
#include "main.h"
#include "change_color.h"
#include "supersampling.h"

unsigned int	mix_color(unsigned int *tab, int ssp)
{
  double	final_comp[3];
  unsigned char	temp_comp[3];
  unsigned char	final[3];
  int		i;

  i = 0;
  final_comp[0] = 0;
  final_comp[1] = 0;
  final_comp[2] = 0;
  while (i < ssp)
    {
      decomp_color(tab[i], temp_comp);
      final_comp[0] += ((double)temp_comp[0] / ssp);
      final_comp[1] += ((double)temp_comp[1] / ssp);
      final_comp[2] += ((double)temp_comp[2] / ssp);
      ++i;
    }
  final[0] = final_comp[0];
  final[1] = final_comp[1];
  final[2] = final_comp[2];
  return (recomp_color(final));
}

unsigned int   	supersampling(t_rt *rpt, t_samp *spt, int x, int y)
{
  double	spacing;
  double	pos[2];
  double	r_pos[2];
  int		i;
  int		ssp;

  spacing = 1.0 / sqrt(rpt->opt->aa);
  ssp = rpt->opt->aa;
  pos[1] = y;
  i = 0;
  while (i < ssp && pos[1] < y + 1)
    {
      pos[0] = x;
      while (i < ssp && pos[0] < x + 1)
	{
	  new_coor(rpt->vpt, rpt->cpt, pos[0], pos[1]);
	  spt->pixel[i] = get_pixel_color(rpt);
	  pos[0] += spacing;
	  ++i;
	}
      pos[1] += spacing;
    }
  return (mix_color(spt->pixel, ssp));
}
