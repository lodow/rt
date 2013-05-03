/*
** shadows.c for rt in /home/dellam_a/Projet/rt/rt
**
** Made by Adrien Della Maggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Tue Apr  9 10:14:18 2013 Adrien Della Maggiora
** Last update Fri May  3 15:53:46 2013 luc sinet
*/

#include <math.h>
#include "include/main.h"
#include "include/light.h"
#include "include/change_color.h"

unsigned int		darken_color(unsigned char *color, double sdw_coef)
{
  color[0] = ((1.0 - sdw_coef) * color[0]);
  color[1] = ((1.0 - sdw_coef) * color[1]);
  color[2] = ((1.0 - sdw_coef) * color[2]);
  return (recomp_color(color));
}

double		shadows(t_rt *rpt, double *cpos, double *lpos, double *opos)
{
  double	cam[3];
  double	vec[3];
  double	*vpos;
  double	k;
  int		obj;
  int		retv;

  retv = 0;
  vpos = rpt->vpt->vec;
  obj = rpt->obj_num;
  copy_tab(cpos, cam, 3);
  copy_tab(vpos, vec, 3);
  copy_tab(opos, cpos, 3);
  cpos[0] = opos[0];
  cpos[1] = opos[1];
  cpos[2] = opos[2];
  vpos[0] = lpos[0] - cpos[0];
  vpos[1] = lpos[1] - cpos[1];
  vpos[2] = lpos[2] - cpos[2];
  calc_inter(rpt, &k);
  copy_tab(cam, cpos, 3);
  copy_tab(vec, vpos, 3);
  if (obj != rpt->obj_num && k > ZERO && k < 1)
    retv = 1;
  rpt->obj_num = obj;
  return (retv);
}
