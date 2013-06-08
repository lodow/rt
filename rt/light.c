/*
** light.c for light in /home/sinet_l//rt/rt/rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Mar 21 15:37:38 2013 luc sinet
** Last update Sat Jun  8 16:04:53 2013 maxime lavandier
*/

#include <math.h>
#include "main.h"
#include "pars.h"
#include "change_color.h"
#include "light.h"

void		init_normals_pointers(void (**nptr)(double *nvec,
						    double *obj_coor,
						    double *pert, t_obj *obj))
{
  nptr[0] = &sphere_normal;
  nptr[1] = &plan_normal;
  nptr[2] = &cone_normal;
  nptr[3] = &cylinder_normal;
  nptr[4] = &plan_normal;
  nptr[5] = &plan_normal;
  nptr[6] = &plan_normal;
  nptr[7] = &paraboloide_normal;
  nptr[8] = &hyperboloide_normal;
  nptr[9] = &tangle_normal;
  nptr[10] = &tangle_normal;
  nptr[11] = &tangle_normal;
  nptr[12] = &tore_normal;
}

void		get_inter_normal(t_rt *rpt, t_vec *vpt, double k, t_lco *lpt)
{
  void		(*nptr[NB_OBJ])(double * nvec, double * obj_coor,
				double * pert, t_obj * obj);
  double	vcam[6];
  double	*ocos[4];
  t_obj		*obj;

  obj = &rpt->obj[rpt->obj_num];
  ocos[0] = obj->apt->ocos;
  ocos[1] = obj->apt->osin;
  ocos[2] = obj->apt->acos;
  ocos[3] = obj->apt->asin;
  copy_tab(rpt->cpt->pos, &vcam[3], 3);
  copy_tab(vpt->vec, vcam, 3);
  init_normals_pointers(nptr);
  modif_cam(&vcam[3], obj->pos);
  rotate(&vcam[3], ocos[0], ocos[1], 0);
  rotate(vcam, ocos[0], ocos[1], 0);
  get_impact(lpt->obj_coor, &vcam[3], k, vcam);
  nptr[obj->type](lpt->nvec, lpt->obj_coor, obj->pert, obj);
  rotate(lpt->nvec, ocos[2], ocos[3], 1);
  rotate(lpt->obj_coor, ocos[2], ocos[3], 1);
  lpt->obj_coor[0] += obj->pos[0];
  lpt->obj_coor[1] += obj->pos[1];
  lpt->obj_coor[2] += obj->pos[2];
  get_obj_distance(obj, &vcam[3], lpt->obj_coor);
}

double		get_light_vector(t_lco *lpt, double *spot_pos)
{
  double	cosa;

  lpt->lvec[0] = spot_pos[0] - lpt->obj_coor[0];
  lpt->lvec[1] = spot_pos[1] - lpt->obj_coor[1];
  lpt->lvec[2] = spot_pos[2] - lpt->obj_coor[2];
  cosa = cos_vector(lpt->nvec, lpt->lvec);
  return (cosa < ZERO ? 0.0 : cosa);
}

void   	copy_light(t_lig *tlight, t_lig *light)
{
  tlight->pos[0] = light->pos[0];
  tlight->pos[1] = light->pos[1];
  tlight->pos[2] = light->pos[2];
  tlight->intensity = light->intensity;
  tlight->lcolor[0] = light->lcolor[0];
  tlight->lcolor[1] = light->lcolor[1];
  tlight->lcolor[2] = light->lcolor[2];
}

unsigned int	get_light(t_rt *rpt, double k, t_obj *obj, t_lco *lpt)
{
  t_lig		tlight;
  double	nb_shadow;
  double	state;
  int		i;

  i = 0;
  nb_shadow = 0;
  get_inter_normal(rpt, rpt->vpt, k, lpt);
  copy_color(obj->color, lpt->c_color);
  apply_ambient(rpt->light, lpt->c_color, &lpt->mx_cos, obj->bright);
  while (rpt->light[i].on == 1)
    {
      lpt->light = &rpt->light[i];
      copy_light(&tlight, &rpt->light[i]);
      if (rpt->light[i].ambient == 0)
        {
          if ((state = shadows(rpt, rpt->cpt->pos, &tlight,
                               lpt)) < 1.0)
            get_light_color(&tlight, lpt, rpt, 1.0 - state);
          nb_shadow += state;
        }
      ++i;
    }
  return (apply_light(lpt->c_color, lpt->mx_cos, nb_shadow / (double)i));
}
