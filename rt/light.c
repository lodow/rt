/*
** light.c for light in /home/sinet_l//rt/rt/rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Mar 21 15:37:38 2013 luc sinet
** Last update Wed Apr 10 14:31:18 2013 luc sinet
** Last update Thu Apr  4 18:17:31 2013 luc sinet
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
  rotate_cam(&cam_tmp, rpt->obj[rpt->obj_num]);
  vec_tmp = rotate_vec(vpt, rpt->obj[rpt->obj_num]);
  lpt->obj_coor[0] = cam_tmp.cx + k * vec_tmp.vx;
  lpt->obj_coor[1] = cam_tmp.cy + k * vec_tmp.vy;
  lpt->obj_coor[2] = cam_tmp.cz + k * vec_tmp.vz;
  get_obj_distance(&rpt->obj[rpt->obj_num], &cam_tmp, lpt->obj_coor);
  if (rpt->obj[rpt->obj_num].type < 2)
    assign_normal1(lpt, rpt->obj[rpt->obj_num].type);
  else
    assign_normal2(lpt, rpt->obj[rpt->obj_num].type);
}

double		get_light_vector(t_vec *vpt, t_lco *lpt, double *spot_pos)
{
  double	bnorme;
  double	cosa;

  vpt->vx = spot_pos[0] - lpt->obj_coor[0];
  vpt->vy = spot_pos[1] - lpt->obj_coor[1];
  vpt->vz = spot_pos[2] - lpt->obj_coor[2];
  bnorme = (sqrt(pow(lpt->nvec[0], 2) + pow(lpt->nvec[1], 2)
		 + pow(lpt->nvec[2], 2))
	    * sqrt(pow(vpt->vx, 2) + pow(vpt->vy, 2)
		   + pow(vpt->vz, 2)));
  if (bnorme < ZERO && bnorme > -ZERO)
    return (0);
  cosa = (lpt->nvec[0] * vpt->vx
	  + lpt->nvec[1] * vpt->vy
	  + lpt->nvec[2] * vpt->vz) / bnorme;
  return (cosa < ZERO ? 0.0 : cosa);
}

t_lig		move_light(double *pos, double intensity,
			   unsigned char *lcolor, double *obj_pos)
{
  t_lig		new_ligth;

  new_ligth.pos[0] = pos[0] - obj_pos[0];
  new_ligth.pos[1] = pos[1] - obj_pos[1];
  new_ligth.pos[2] = pos[2] - obj_pos[2];
  new_ligth.intensity = intensity;
  new_ligth.lcolor[0] = lcolor[0];
  new_ligth.lcolor[1] = lcolor[1];
  new_ligth.lcolor[2] = lcolor[2];
  return (new_ligth);
}

unsigned int	get_light(t_rt *rpt, double k, t_obj *obj)
{
  t_lco		lpt;
  double	*obj_pos;
  int		i;
  int		state;
  int		shadow;

  i = 0;
  shadow = 0;
  obj_pos = rpt->obj[rpt->obj_num].pos;
  get_inter_normal(rpt, rpt->vpt, k, &lpt);
  copy_color(lpt.c_color, obj->color);
  apply_ambient(rpt->light, lpt.c_color, &lpt.mx_cos);
  while (rpt->light[i].on == 1)
    {
      if (rpt->light[i].ambient == 0)
	{
	  /* if ((state = shadows(rpt, rpt->cpt, &rpt->light[i], &lpt)) == 1) */
	    lpt.mx_cos = get_light_color(&rpt->light[i], obj_pos, &lpt, rpt->vpt);
	  shadow += state;
	}
      else
	++shadow;
      ++i;
    }
  return (apply_light(lpt.c_color, lpt.mx_cos /* * ((double)shadow / (double)i) */, obj));
}
