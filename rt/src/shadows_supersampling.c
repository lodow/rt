/*
** shadows_supersampling.c for shadows_supersampling in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu May 23 21:40:41 2013 luc sinet
** Last update Tue Jun  4 11:42:04 2013 luc sinet
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

int		throw_rays(t_rt *rpt, t_shadow *spt,
			   double *cpos, double *sinter)
{
  double	k;

  copy_tab(sinter, &sinter[3], 3);
  apply_rand_pos(&sinter[3], sinter[6]);
  copy_tab(&sinter[3], cpos, 3);
  rpt->vpt->vec[0] = spt->light->pos[0] - cpos[0];
  rpt->vpt->vec[1] = spt->light->pos[1] - cpos[1];
  rpt->vpt->vec[2] = spt->light->pos[2] - cpos[2];
  calc_inter(rpt, &k);
  if (spt->obj[1] != rpt->obj_num && k > ZERO && k < 1)
    spt->s_coef -= ((1.0 - rpt->obj[rpt->obj_num].ipt->indice[0])
		    / (double)SDW_SS);
  sinter[0] += sinter[6];
  return (1);
}

double		shadow_supersampling(t_rt *rpt, double *cpos, t_shadow *spt)
{
  double	sinter[7];
  double	svec[3];
  double	copy_cam[3];
  int		i;

  spt->s_coef = spt->sdw_coef;
  sinter[6] = (double)RAY_DIST / sqrt(SDW_SS);
  copy_tab(spt->inter, sinter, 3);
  copy_tab(rpt->vpt->vec, svec, 3);
  copy_tab(cpos, copy_cam, 3);
  i = 0;
  sinter[1] -= (double)RAY_DIST / 2.0;
  while (i < SDW_SS && sinter[1] < spt->inter[1] + (double)RAY_DIST / 2.0
	 && spt->s_coef > ZERO)
    {
      sinter[0] = spt->inter[0] - (double)RAY_DIST / 2.0;
      while (i < SDW_SS && sinter[0] < spt->inter[0] + (double)RAY_DIST / 2.0
	     && spt->s_coef > ZERO)
	i += throw_rays(rpt, spt, cpos, sinter);
      sinter[1] += sinter[6];
    }
  copy_tab(copy_cam, cpos, 3);
  copy_tab(svec, rpt->vpt->vec, 3);
  return (spt->s_coef);
}
