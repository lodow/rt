/*
** shadows.c for rt in /home/dellam_a/Projet/rt/rt
**
** Made by Adrien Della Maggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Tue Apr  9 10:14:18 2013 Adrien Della Maggiora
** Last update Wed May  8 19:41:34 2013 luc sinet
*/

#include <math.h>
#include "include/main.h"
#include "include/light.h"
#include "include/change_color.h"

unsigned int		darken_color(unsigned char *color, double sdw_coef)
{
  double		intensity;

  intensity = 0.75;
  color[0] = ((1.0 - (sdw_coef * intensity)) * color[0]);
  color[1] = ((1.0 - (sdw_coef * intensity)) * color[1]);
  color[2] = ((1.0 - (sdw_coef * intensity)) * color[2]);
  return (recomp_color(color));
}

void   	init_shadows(t_shadow *spt, t_rt *rpt, double *cpos, t_lco *lpt)
{
  spt->slpt = lpt;
  spt->sdw_coef = 1.0;
  spt->vpos = rpt->vpt->vec;
  copy_tab(spt->vpos, spt->vec, 3);
  copy_tab(cpos, spt->cam, 3);
  copy_tab(lpt->obj_coor, spt->inter, 3);
  spt->obj[0] = rpt->obj_num;
  spt->hit = 0;
}

void	cam_to_inter(t_shadow *spt, int obj_num, double *cpos, double *lpos)
{
  spt->obj[1] = obj_num;
  copy_tab(spt->inter, cpos, 3);
  spt->vpos[0] = lpos[0] - cpos[0];
  spt->vpos[1] = lpos[1] - cpos[1];
  spt->vpos[2] = lpos[2] - cpos[2];
}

void	get_inter_shadow(t_shadow *spt, t_rt *rpt, double k, double *cpos)
{
  if (spt->obj[1] != rpt->obj_num && k > ZERO && k < 1)
    {
      if (add_to_tab(spt->pass, rpt->obj_num) == 1)
	{
	  spt->sdw_coef *= rpt->obj[rpt->obj_num].indice[0];
	  if (rpt->obj[rpt->obj_num].indice[0] < 1.0)
	    filter_light_color(spt->light->lcolor, &rpt->obj[rpt->obj_num]);
	  /*   change_shadow_color */
	  /*     (spt->slpt->c_color, &rpt->obj[rpt->obj_num], spt->slpt->light); */
	}
      if (spt->sdw_coef > 0)
	get_impact(spt->inter, cpos, k, spt->vpos);
    }
  else if (spt->obj[1] == rpt->obj_num && k > ZERO && k < 1)
    {
      add_to_tab(spt->pass, rpt->obj_num);
      get_impact(spt->inter, cpos, k, spt->vpos);
    }
  else
    spt->hit = 1;
}

double		shadows(t_rt *rpt, double *cpos, t_lig *light, t_lco *lpt)
{
  t_shadow	spt;
  double	k;

  init_shadows(&spt, rpt, cpos, lpt);
  spt.light = light;
  tab_set(spt.pass, 256);
  while (spt.sdw_coef > 0 && spt.hit == 0)
    {
      cam_to_inter(&spt, rpt->obj_num, cpos, light->pos);
      calc_inter(rpt, &k);
      get_inter_shadow(&spt, rpt, k, cpos);
   }
  copy_tab(spt.cam, cpos, 3);
  copy_tab(spt.vec, spt.vpos, 3);
  rpt->obj_num = spt.obj[0];
  return (1.0 - spt.sdw_coef);
}
