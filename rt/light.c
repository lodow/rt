/*
** light.c for light in /home/sinet_l//rt/rt/rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Mar 21 15:37:38 2013 luc sinet
** Last update Thu Mar 21 17:47:28 2013 adrien dellamaggiora
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
      lpt->nvec[2] = -0.5 * lpt->obj_coor[2];
    }
  else if (type == 3)
    {
      lpt->nvec[0] = lpt->obj_coor[0];
      lpt->nvec[1] = lpt->obj_coor[1];
      lpt->nvec[2] = 0;
    }
}

void	get_inter_normal(t_rt *rpt, t_vec *vpt, double k, t_lco *lpt)
{
  lpt->obj_coor[0] = rpt->cpt->cx + k * vpt->vx;
  lpt->obj_coor[1] = rpt->cpt->cy + k * vpt->vy;
  lpt->obj_coor[2] = rpt->cpt->cz + k * vpt->vz;
  if (rpt->obj[rpt->obj_num].type < 2)
    assign_normal1(lpt, rpt->obj[rpt->obj_num].type);
  else
    assign_normal2(lpt, rpt->obj[rpt->obj_num].type);
  lpt->nvec[0] = lpt->nvec[0] - rpt->obj[rpt->obj_num].pos[0];
  lpt->nvec[1] = lpt->nvec[1] - rpt->obj[rpt->obj_num].pos[1];
  lpt->nvec[2] = lpt->nvec[2] - rpt->obj[rpt->obj_num].pos[2];
  rotate_x(&lpt->nvec[2], &lpt->nvec[1], rpt->obj[rpt->obj_num].ocos[0],
	   rpt->obj[rpt->obj_num].osin[0]);
  rotate_y(&lpt->nvec[2], &lpt->nvec[0], rpt->obj[rpt->obj_num].ocos[1],
	   rpt->obj[rpt->obj_num].osin[1]);
  rotate_z(&lpt->nvec[2], &lpt->nvec[1], rpt->obj[rpt->obj_num].ocos[2],
	   rpt->obj[rpt->obj_num].osin[2]);
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
