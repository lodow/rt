/*
** ambient_light.c for ambient_light.c in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun Apr  7 19:07:11 2013 luc sinet
** Last update Mon Apr 22 15:32:38 2013 luc sinet
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

/* double		get_specular_coef(t_lco *lpt, double *cpos) */
/* { */
/*   double	vis[3]; */
/*   double	nvec[3]; */

/*   copy_tab(lpt->nvec, nvec, 3); */
/*   vis[0] = lpt->obj_coor[0] - cpos[0]; */
/*   vis[1] = lpt->obj_coor[1] - cpos[1]; */
/*   vis[2] = lpt->obj_coor[2] - cpos[2]; */
/*   cpos[0] = lpt->obj_coor[0]; */
/*   cpos[1] = lpt->obj_coor[1]; */
/*   cpos[2] = lpt->obj_coor[2]; */
/*   unitaire() */
/* } */

void		get_light_color(t_lig *light, t_lco *lpt, t_rt *rpt)
{
  t_lig		tmp_light;
  double	cpos[3];
  double	cosa;
  double	coss;

  copy_tab(rpt->cpt->pos, cpos, 3);
  tmp_light = move_light(light->pos, light->intensity,
  			 light->lcolor);
  if ((cosa = get_light_vector(lpt, tmp_light.pos)) > ZERO);
    cosa = apply_distance(lpt, &tmp_light, cosa);
  /* coss = get_specular_coef(lpt, cpos); */
  /* printf("cosa = %f | cosS =  %f\n", cosa, coss); */
  apply_light_color(lpt->c_color, light->lcolor, cosa);
  lpt->mx_cos = MAX(lpt->mx_cos, cosa);
}
