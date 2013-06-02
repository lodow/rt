/*
** shadows_supersampling.c for shadows_supersampling in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu May 23 21:40:41 2013 luc sinet
** Last update Sun Jun  2 11:28:50 2013 luc sinet
*/

#include <math.h>
#include "main.h"
#include "light.h"
#include "change_color.h"

void		apply_rand_pos(double *inter, double spacing)
{
  double	res;

  spacing *= 100000;
  res = rand() % (int)spacing;
  res /= 100000;
  inter[0] += res;
  inter[1] += res;
}

double		shadow_supersampling(t_rt *rpt, double *cpos, t_shadow *spt)
{
  double	k;
  double	sinter[3];
  double	rand_inter[3];
  double	s_coef;
  double	spacing;
  double	svec[3];
  double	copy_cam[3];
  double	sdw_ss;
  double	dist;
  int		s_obj;
  int		i;

  sdw_ss = 1;
  dist = 15;
  s_coef = spt->sdw_coef;
  s_obj = rpt->obj_num;
  spacing = dist / sqrt(sdw_ss);
  copy_tab(spt->inter, sinter, 3);
  copy_tab(rpt->vpt->vec, svec, 3);
  copy_tab(cpos, copy_cam, 3);
  i = 0;
  sinter[1] -= dist / 2.0;
  while (i < sdw_ss && sinter[1] < spt->inter[1] + 3.0 && s_coef > ZERO)
    {
      sinter[0] = spt->inter[0] - dist / 2.0;
      while (i < sdw_ss && sinter[0] < spt->inter[0] + 3.0 && s_coef > ZERO)
	{
	  copy_tab(sinter, rand_inter, 3);
	  apply_rand_pos(rand_inter, spacing);
	  copy_tab(rand_inter, cpos, 3);
	  rpt->vpt->vec[0] = spt->light->pos[0] - cpos[0];
	  rpt->vpt->vec[1] = spt->light->pos[1] - cpos[1];
	  rpt->vpt->vec[2] = spt->light->pos[2] - cpos[2];
	  calc_inter(rpt, &k);
	  if (spt->obj[1] != rpt->obj_num && k > ZERO && k < 1)
	    s_coef -= ((1.0 - rpt->obj[rpt->obj_num].indice[0]) / sdw_ss);
	  sinter[0] += spacing;
	  ++i;
	}
      sinter[1] += spacing;
    }
  copy_tab(copy_cam, cpos, 3);
  copy_tab(svec, rpt->vpt->vec, 3);
  rpt->obj_num = s_obj;
  return (s_coef);
}
