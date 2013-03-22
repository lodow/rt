/*
** light.c for light in /home/sinet_l//rt/rt/rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Mar 21 15:37:38 2013 luc sinet
** Last update Fri Mar 22 00:52:33 2013 etienne debas
*/

#include <math.h>
#include "main.h"
#include "light.h"

void	assign_normal1(t_lco *lpt, int type)
{
  if (type == 0)
    {
      lpt->nvec[0] = lpt->obj_coor[0];
      lpt->nvec[1] = lpt->obj_coor[1];
      lpt->nvec[2] = lpt->obj_coor[2];
    }
  else if (type == 1)
    {
      lpt->nvec[0] = 0;
      lpt->nvec[1] = 0;
      lpt->nvec[2] = 100;
    }
}

void	assign_normal2(t_lco *lpt, int type)
{
  if (type == 2)
    {
      lpt->nvec[0] = lpt->obj_coor[0];
      lpt->nvec[1] = lpt->obj_coor[1];
      lpt->nvec[2] = -0.6 * lpt->obj_coor[2];
    }
  else if (type == 3)
    {
      lpt->nvec[0] = lpt->obj_coor[0];
      lpt->nvec[1] = lpt->obj_coor[1];
      lpt->nvec[2] = 0;
    }
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

  vpt->vx = spot->pos[0] - lpt->obj_coor[0];
  vpt->vy = spot->pos[1] - lpt->obj_coor[1];
  vpt->vz = spot->pos[2] - lpt->obj_coor[2];
  bnorme = (sqrt(pow(lpt->nvec[0], 2) + pow(lpt->nvec[1], 2)
		 + pow(lpt->nvec[2], 2))
	    * sqrt(pow(vpt->vx, 2) + pow(vpt->vy, 2)
		   + pow(vpt->vz, 2)));
  if (bnorme < ZERO && bnorme > -ZERO)
    return (0);
  cosa = (lpt->nvec[0] * vpt->vx
	  + lpt->nvec[1] * vpt->vy
	  + lpt->nvec[2] * vpt->vz) / bnorme;
  return (cosa);
}

unsigned int	get_light(t_rt *rpt, double k, unsigned int color)
{
  t_lco		lpt;
  double	cosa;
  int		i;

  i = 0;
  get_inter_normal(rpt, rpt->vpt, k, &lpt);
  while (rpt->light[i].on == 1)
    {
      if ((cosa = get_light_vector(rpt, rpt->vpt, &lpt, &rpt->light[i])) < ZERO)
	return (0x000000);
      color = apply_light(color, cosa, &rpt->light[i++]);
    }
  return (color);
}
