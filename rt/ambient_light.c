/*
** ambient_light.c for ambient_light.c in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun Apr  7 19:07:11 2013 luc sinet
** Last update Fri Apr 19 16:47:19 2013 luc sinet
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
	  apply_light_color(color, light[i].lcolor, cosa);
	  *max_cos = MAX(*max_cos, cosa);
	}
      ++i;
    }
  return (color);
}

double		get_specular_coef(t_lco *lpt, double *cpos)
{
  double	nsscal;
  double	vision[3];
  double	spe_cos;

  unitaire(lpt->nvec);
  unitaire(lpt->lvec);
  /* printf("\n%f %f %f\n %f %f %f\n", lpt->lvec[0], lpt->lvec[1], lpt->lvec[2], lpt->nvec[0], lpt->nvec[1], lpt->nvec[2]); */
  nsscal = scale(lpt->nvec, lpt->lvec);
  lpt->rvec[0] =  2.0 * nsscal * lpt->nvec[0] - lpt->lvec[0];
  lpt->rvec[1] =  2.0 * nsscal * lpt->nvec[1] - lpt->lvec[1];
  lpt->rvec[2] =  2.0 * nsscal * lpt->nvec[2] - lpt->lvec[2];
  unitaire(lpt->rvec);
  /* printf("%f %f %f\n", lpt->rvec[0], lpt->rvec[1], lpt->rvec[2]); */
  /* vision[0] =  lpt->obj_coor[0] - cpos[0]; */
  /* vision[1] =  lpt->obj_coor[1] - cpos[1]; */
  /* vision[2] =  lpt->obj_coor[2] - cpos[2]; */
  unitaire(cpos);
  spe_cos = cos_vector(lpt->rvec, cpos);
  spe_cos = pow(spe_cos, SPE_SIZE);
  return (spe_cos);
}

void		get_light_color(t_lig *light, double *obj_pos,
				  t_lco *lpt, t_rt *rpt)
{
  t_lig		tmp_light;
  double	cosa;
  double	coss;

  tmp_light = move_light(light->pos, light->intensity,
  			 light->lcolor, obj_pos);
  if ((cosa = get_light_vector(rpt->vpt, lpt, tmp_light.pos)) > ZERO);
    cosa = apply_distance(lpt, &tmp_light, cosa);
  /* coss = get_specular_coef(lpt, rpt->vpt->vec); */
  /* printf("cosa = %f | cosS =  %f\n", cosa, coss); */
  apply_light_color(lpt->c_color, light->lcolor, cosa);
  lpt->mx_cos = MAX(lpt->mx_cos, cosa);
}
