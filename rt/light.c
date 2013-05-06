/*
** light.c for light in /home/sinet_l//rt/rt/rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Mar 21 15:37:38 2013 luc sinet
** Last update Mon May  6 13:50:43 2013 luc sinet
*/

#include <math.h>
#include "include/main.h"
#include "include/change_color.h"
#include "include/light.h"

void	copy_color(unsigned char *color1, unsigned char *color2)
{
  color1[0] = color2[0];
  color1[1] = color2[1];
  color1[2] = color2[2];
}

void		get_inter_normal(t_rt *rpt, t_vec *vpt, double k, t_lco *lpt)
{
  void		(*nptr[8])(double *nvec, double *obj_coor, double *pert);
  double	vcam[6];
  t_obj		*obj;

  copy_tab(rpt->cpt->pos, &vcam[3], 3);
  copy_tab(vpt->vec, vcam, 3);
  nptr[0] = &sphere_normal;
  nptr[1] = &plan_normal;
  nptr[2] = &cone_normal;
  nptr[3] = &cylinder_normal;
  nptr[4] = &plan_normal;
  nptr[5] = &plan_normal;
  nptr[6] = &plan_normal;
  nptr[7] = &moebius_normal;
  obj = &rpt->obj[rpt->obj_num];
  modif_cam(&vcam[3], obj->pos);
  rotate(&vcam[3], obj->ocos, obj->osin, 0);
  rotate(vcam, obj->ocos, obj->osin, 0);
  get_impact(lpt->obj_coor, &vcam[3], k, vcam);
  nptr[obj->type](lpt->nvec, lpt->obj_coor, obj->pert);
  rotate(lpt->nvec, obj->acos, obj->asin, 1);
  rotate(lpt->obj_coor, obj->acos, obj->asin, 1);
  lpt->obj_coor[0] += obj->pos[0];
  lpt->obj_coor[1] += obj->pos[1];
  lpt->obj_coor[2] += obj->pos[2];
  get_obj_distance(obj, &vcam[3], lpt->obj_coor);
}

double		get_light_vector(t_lco *lpt, double *spot_pos)
{
  double	cosa;
  double	lvec[3];

  lvec[0] = spot_pos[0] - lpt->obj_coor[0];
  lvec[1] = spot_pos[1] - lpt->obj_coor[1];
  lvec[2] = spot_pos[2] - lpt->obj_coor[2];
  cosa = cos_vector(lpt->nvec, lvec);
  return (cosa < ZERO ? 0.0 : cosa);
}

t_lig		move_light(double *pos, double intensity,
			   unsigned char *lcolor)
{
  t_lig		new_ligth;

  new_ligth.pos[0] = pos[0];
  new_ligth.pos[1] = pos[1];
  new_ligth.pos[2] = pos[2];
  new_ligth.intensity = intensity;
  new_ligth.lcolor[0] = lcolor[0];
  new_ligth.lcolor[1] = lcolor[1];
  new_ligth.lcolor[2] = lcolor[2];
  return (new_ligth);
}

unsigned int	get_light(t_rt *rpt, double k, t_obj *obj, t_lco *lpt)
{
  double	nb_shadow;
  double	state;
  int		i;

  i = 0;
  nb_shadow = 0;
  get_inter_normal(rpt, rpt->vpt, k, lpt);
  copy_color(lpt->c_color, obj->color);
  apply_ambient(rpt->light, lpt->c_color, &lpt->mx_cos);
  while (rpt->light[i].on == 1)
    {
      if (rpt->light[i].ambient == 0)
	{
	  if ((state = shadows(rpt, rpt->cpt->pos, rpt->light[i].pos,
			       lpt->obj_coor)) < 1)
	    get_light_color(&rpt->light[i], lpt, rpt, 1.0 - state);
	  nb_shadow += state;
	}
      ++i;
    }
  return (apply_light(lpt->c_color, lpt->mx_cos, nb_shadow / (double)i, obj));
}
