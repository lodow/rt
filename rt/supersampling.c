/*
** supersampling.c for supersampling in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri Apr  5 11:07:42 2013 luc sinet
** Last update Sat Apr 13 23:11:44 2013 luc sinet
*/

#include <math.h>
#include "include/main.h"
#include "include/change_color.h"
#include "include/supersampling.h"

unsigned int	mix_color(unsigned int *tab, int ssp)
{
  unsigned char	final_comp[3];
  unsigned char	temp_comp[3];
  int		i;

  i = 1;
  decomp_color(tab[0], final_comp);
  while (i < ssp)
    {
      decomp_color(tab[i], temp_comp);
      final_comp[0] = (final_comp[0] + temp_comp[0]) / 2.0;
      final_comp[1] = (final_comp[1] + temp_comp[1]) / 2.0;
      final_comp[2] = (final_comp[2] + temp_comp[2]) / 2.0;
      ++i;
    }
  return (recomp_color(final_comp));
}

int	get_int(double space, int *virg)
{

  *virg = 0;
  while ((space - (int)space) > ZERO && *virg < 10)
    {
      ++(*virg);
      space *= 10;
    }
  return (space);
}

void	get_rand_pos(double *pos, double *new_pos, double spacing)
{
  int	virg;
  int	nspace;

  nspace = get_int(spacing, &virg);
  new_pos[0] = pos[0] + (double)((rand() % nspace)) / (double)pow(10, virg);
  new_pos[1] = pos[1] + (double)((rand() % nspace)) / (double)pow(10, virg);
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
	  get_rand_pos(pos, r_pos, spacing);
	  new_coor(rpt->vpt, rpt->cpt, r_pos[0], r_pos[1]);
	  spt->pixel[i] = get_pixel_color(rpt);
	  /* printf("y %f  x %f\n", r_pos[1], r_pos[0]); */
	  pos[0] += spacing;
	  ++i;
	}
      pos[1] += spacing;
    }
  return (mix_color(spt->pixel, ssp));
}
