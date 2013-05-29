/*
** shadows_supersampling.c for shadows_supersampling in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu May 23 21:40:41 2013 luc sinet
** Last update Mon May 27 15:18:15 2013 luc sinet
*/

#include <math.h>
#include "main.h"
#include "light.h"
#include "change_color.h"

double		shadow_supersampling(t_rt *rpt, double *cpos,
			     t_shadow  *spt, t_lco *lpt)
{
  double	k;
  double	sinter[3];
  double	s_coef;
  double	spacing;
  double	svec[3];
  double	sdw_ss;
  double	s_coef2;
  int		s_obj;
  int		i;

  sdw_ss = 20;
  s_coef = s_coef2 = spt->sdw_coef;
  s_obj = rpt->obj_num;
  spacing = 2.0 / sqrt(sdw_ss);
  copy_tab(spt->inter, sinter, 3);
  copy_tab(rpt->vpt->vec, svec, 3);
  i = 0;
  /* printf("\nstart\n"); */
  sinter[1] -= 1.0;
  while (i < sdw_ss && sinter[1] < spt->inter[1] + 1.0)
    {
      sinter[0] = spt->inter[0] - 1.0;
      while (i < sdw_ss && sinter[0] < spt->inter[0] + 1.0)
	{
	  s_coef2 = spt->sdw_coef;
	  copy_tab(sinter, cpos, 3);
	  rpt->vpt->vec[0] = spt->light->pos[0] - cpos[0];
	  rpt->vpt->vec[1] = spt->light->pos[1] - cpos[1];
	  rpt->vpt->vec[2] = spt->light->pos[2] - cpos[2];
	  calc_inter(rpt, &k);
	  /* printf("%f\n", rpt->obj[rpt->obj_num].indice[0]); */
	  s_coef2 -= (1.0 - rpt->obj[rpt->obj_num].indice[0]);
	  s_coef -= ((1.0 - rpt->obj[rpt->obj_num].indice[0]) / 20.0);
	  sinter[0] += spacing;
	  ++i;
	}
      sinter[1] += spacing;
    }
  /* printf("\nstop\n"); */
  copy_tab(svec, rpt->vpt->vec, 3);
  rpt->obj_num = s_obj;
  return (s_coef);
}
