/*
** ambient_light.c for ambient_light.c in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun Apr  7 19:07:11 2013 luc sinet
** Last update Thu May  9 12:16:40 2013 luc sinet
*/

#include <math.h>
#include "include/main.h"
#include "include/change_color.h"
#include "include/light.h"

void		*apply_ambient(t_lig *light, unsigned char *color,
			      double *max_cos)
{
  int		i;
  double	cosa;

  i = 0;
  cosa = 0.0;
  *max_cos = 0.0;
  while (light[i].on == 1)
    {
      if (light[i].ambient == 1)
	{
	  cosa = light[i].intensity / 1.7;
	  apply_light_color(color, light[i].lcolor, cosa, 0.0);
	  *max_cos = MAX(*max_cos, cosa);
	}
      ++i;
    }
  return (color);
}

double		get_specular_coef(t_lco *lpt, double *cam_pos)
{
  double	lvec[3];
  double	cvec[3];
  double	rvec[3];
  double	scal;

  copy_tab(lpt->lvec, lvec, 3);
  cvec[0] = cam_pos[0] - lpt->obj_coor[0];
  cvec[1] = cam_pos[1] - lpt->obj_coor[1];
  cvec[2] = cam_pos[2] - lpt->obj_coor[2];
  scal = scale(lvec, lpt->nvec);
  unitaire(lvec);
  unitaire(lpt->nvec);
  rvec[0] = lvec[0] - 2.0 * scal * lpt->nvec[0];
  rvec[1] = lvec[1] - 2.0 * scal * lpt->nvec[1];
  rvec[2] = lvec[2] - 2.0 * scal * lpt->nvec[2];
  return (pow(cos_vector(rvec, cvec), 50));
}

void		get_light_color(t_lig *light, t_lco *lpt,
				t_rt *rpt, double lpower)
{
  double	cosa;
  double	coss;

  light->intensity *= lpower;
  if ((cosa = get_light_vector(lpt, light->pos)) > ZERO)
  cosa = apply_distance(lpt, light, cosa);
  coss = get_specular_coef(lpt, rpt->cpt->pos);
  if (coss < ZERO)
    coss = 0.0;
  /* printf("cosa = %f | cosS =  %f\n", cosa, coss); */
  /* cosa = 0.25 * coss + 0.75 * cosa; */
  apply_light_color(lpt->c_color, light->lcolor, cosa, 0);
  lpt->mx_cos = MAX(lpt->mx_cos, cosa);
}
