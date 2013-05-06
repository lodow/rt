/*
** ambient_light.c for ambient_light.c in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun Apr  7 19:07:11 2013 luc sinet
** Last update Mon May  6 13:52:24 2013 luc sinet
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

double		get_specular_coef(double *obj_coor, double *cam_pos, double *nvec, double *lpos)
{
  double	vis[3];
  double	cpos[3];
  double	refl[3];
  double	unvec[3];
  double	lvec[3];
  /* double	scal; */
  double	ncos;

  copy_tab(nvec, unvec, 3);
  copy_tab(cam_pos, cpos, 3);
  lvec[0] = -lpos[0] + obj_coor[0];
  lvec[1] = -lpos[1] + obj_coor[1];
  lvec[2] = -lpos[2] + obj_coor[2];
  vis[0] = obj_coor[0] - cpos[0];
  vis[1] = obj_coor[1] - cpos[1];
  vis[2] = obj_coor[2] - cpos[2];
  unitaire(vis);
  unitaire(unvec);
  unitaire(lvec);
  ncos = cos_vector(unvec, lvec);
  refl[0] = lvec[0] - 2.0 * ncos * unvec[0];
  refl[1] = lvec[1] - 2.0 * ncos * unvec[1];
  refl[2] = lvec[2] - 2.0 * ncos * unvec[2];
  /* scal = scale(vis, unvec); */
  /* refl[0] = (-2.0 * unvec[0] * scal) + vis[0]; */
  /* refl[1] = (-2.0 * unvec[1] * scal) + vis[1]; */
  /* refl[2] = (-2.0 * unvec[2] * scal) + vis[2]; */
  return (pow(cos_vector(vis, refl), 20));
}

void		get_light_color(t_lig *light, t_lco *lpt,
				t_rt *rpt, double lpower)
{
  t_lig		tmp_light;
  double	cosa;
  double	coss;

  tmp_light = move_light(light->pos, light->intensity,
  			 light->lcolor);
  tmp_light.intensity *= lpower;
  if ((cosa = get_light_vector(lpt, tmp_light.pos)) > ZERO)
    cosa = apply_distance(lpt, &tmp_light, cosa);
  coss = get_specular_coef(lpt->obj_coor, rpt->cpt->pos, lpt->nvec, light->pos);
  if (coss < ZERO)
    coss = 0.0;
  /* printf("cosa = %f | cosS =  %f\n", cosa, coss); */
  apply_light_color(lpt->c_color, light->lcolor, cosa, 0);
  lpt->mx_cos = MAX(lpt->mx_cos, cosa);
}
