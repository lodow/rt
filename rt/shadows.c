/*
** shadows.c for rt in /home/dellam_a/Projet/rt/rt
**
** Made by Adrien Della Maggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Tue Apr  9 10:14:18 2013 Adrien Della Maggiora
** Last update Sun May  5 11:24:32 2013 luc sinet
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

double		shadows(t_rt *rpt, double *cpos, double *lpos, double *opos)
{
  double	cam[3];
  double	vec[3];
  double	inter[3];
  double	*vpos;
  double	k;
  double	sdw_coef;
  int		obj[2];
  char		hit;

  hit = 0;
  sdw_coef = 0;
  vpos = rpt->vpt->vec;
  copy_tab(vpos, vec, 3);
  copy_tab(cpos, cam, 3);
  copy_tab(opos, inter, 3);
  printf("New shadow\n");
  obj[0] = rpt->obj_num;
  while (sdw_coef < 1.0 && hit == 0)
    {
      printf("sdw_coef = %f\n", sdw_coef);
      obj[1] = rpt->obj_num;
      copy_tab(inter, cpos, 3);
      vpos[0] = lpos[0] - cpos[0];
      vpos[1] = lpos[1] - cpos[1];
      vpos[2] = lpos[2] - cpos[2];
      calc_inter(rpt, &k);
      if (obj[1] != rpt->obj_num && k > ZERO && k < 1)
	{
	  sdw_coef += 1 - rpt->obj[rpt->obj_num].indice[0];
	  if (sdw_coef < 1.0)
	    get_impact(inter, cpos, k, vpos);
	}
      else
	hit = 1;
    }
  printf("final: sdw_coef = %f\n\n", sdw_coef);
  copy_tab(cam, cpos, 3);
  copy_tab(vec, vpos, 3);
  rpt->obj_num = obj[0];
  return (sdw_coef > 1.0 ? 1.0 : sdw_coef);
}
