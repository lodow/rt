/*
** light.c for light in /home/sinet_l//rt/rt/rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Mar 21 15:37:38 2013 luc sinet
** Last update Mon Apr  1 22:43:36 2013 luc sinet
*/

#include <math.h>
#include "main.h"
#include "change_color.h"
#include "light.h"

void	copy_color(unsigned char *color1, unsigned char *color2)
{
  color1[0] = color2[0];
  color1[1] = color2[1];
  color1[2] = color2[2];
}

void		get_inter_normal(t_rt *rpt, t_vec *vpt, double k, t_lco *lpt)
{
  t_cam		cam_tmp;
  t_vec		vec_tmp;

  cam_tmp = modif_cam(rpt->cpt, rpt->obj[rpt->obj_num]);
  cam_tmp = rotate_cam(&cam_tmp, rpt->obj[rpt->obj_num]);
  vec_tmp = rotate_vec(vpt, rpt->obj[rpt->obj_num]);
  lpt->obj_coor[0] = cam_tmp.cx + k * vec_tmp.vx;
  lpt->obj_coor[1] = cam_tmp.cy + k * vec_tmp.vy;
  lpt->obj_coor[2] = cam_tmp.cz + k * vec_tmp.vz;
  if (rpt->obj[rpt->obj_num].type < 2)
    assign_normal1(lpt, rpt->obj[rpt->obj_num].type);
  else
    assign_normal2(lpt, rpt->obj[rpt->obj_num].type);
}

double		get_light_vector(t_rt *rpt, t_vec *vpt, t_lco *lpt, t_lig *spot)
{
  double	bnorme;
  double	cosa;

  lpt->lvec[0] = spot->pos[0] - lpt->obj_coor[0];
  lpt->lvec[1] = spot->pos[1] - lpt->obj_coor[1];
  lpt->lvec[2] = spot->pos[2] - lpt->obj_coor[2];
  bnorme = (sqrt(pow(lpt->nvec[0], 2) + pow(lpt->nvec[1], 2)
		 + pow(lpt->nvec[2], 2))
	    * sqrt(pow(lpt->lvec[0], 2) + pow(lpt->lvec[1], 2)
		   + pow(lpt->lvec[2], 2)));
  if (bnorme < ZERO && bnorme > -ZERO)
    return (0);
  cosa = (lpt->nvec[0] * lpt->lvec[0]
	  + lpt->nvec[1] * lpt->lvec[1]
	  + lpt->nvec[2] * lpt->lvec[2]) / bnorme;
  return (cosa < ZERO ? 0.0 : cosa);
}

unsigned int	get_light(t_rt *rpt, double k, t_obj *obj)
{
  t_lco		lpt;
  unsigned int	color;
  double	cosa;
  int		i;

  i = 0;
  get_inter_normal(rpt, rpt->vpt, k, &lpt);
  copy_color(lpt.c_color, obj->color);
  lpt.max_cos = 0.0;
  while (rpt->light[i].on == 1)
    {
      if ((cosa = get_light_vector(rpt, rpt->vpt, &lpt, &rpt->light[i])) > ZERO)
	cosa = apply_distance(&lpt, &rpt->light[i], cosa);
      lpt.max_cos = MAX(lpt.max_cos, cosa);
      apply_light_color(lpt.c_color, rpt->light[i].lcolor, cosa);
      ++i;
    }
  color = apply_light(lpt.c_color, lpt.max_cos, obj);
  return (color);
}
