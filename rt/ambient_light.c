/*
** ambient_light.c for ambient_light.c in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun Apr  7 19:07:11 2013 luc sinet
** Last update Tue May 21 20:44:19 2013 luc sinet
*/

#include <math.h>
#include "main.h"
#include "change_color.h"
#include "light.h"

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
	  apply_light_color(color, light[i].lcolor, cosa);
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
  double	scal[2];

  copy_tab(lpt->lvec, lvec, 3);
  cvec[0] = cam_pos[0] - lpt->obj_coor[0];
  cvec[1] = cam_pos[1] - lpt->obj_coor[1];
  cvec[2] = cam_pos[2] - lpt->obj_coor[2];
  unitaire(lvec);
  unitaire(lpt->nvec);
  scal[0] = scale(lvec, lpt->nvec);
  rvec[0] = lvec[0] - 2.0 * scal[0] * lpt->nvec[0];
  rvec[1] = lvec[1] - 2.0 * scal[0] * lpt->nvec[1];
  rvec[2] = lvec[2] - 2.0 * scal[0] * lpt->nvec[2];
  scal[1] = scale(rvec, cvec);
  if (scal[1] < 0)
    scal[1] += 360;
  if (scal[1] < 90)
    return (pow(cos_vector(rvec, cvec), 20));
  return (0);
}

void		get_light_color(t_lig *light, t_lco *lpt,
				t_rt *rpt, double lpower)
{
  double	cosa;
  double	coss;

  light->intensity *= lpower;
  cosa = get_light_vector(lpt, light->pos);
  if (cosa > 0)
    {
      if (rpt->obj[rpt->obj_num].indice[2])
	coss = get_specular_coef(lpt, rpt->cpt->pos);
      else
	coss = 0;
      cosa *= light->intensity;
      cosa *= 0.8;
      if (coss > cosa)
	{
	  cosa = coss;
	}
      cosa = apply_distance(lpt, light, cosa);
    }
  apply_light_color(lpt->c_color, light->lcolor, cosa);
  lpt->mx_cos = MAX(lpt->mx_cos, cosa);
}
