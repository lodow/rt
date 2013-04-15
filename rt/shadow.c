/*
** shadow.c for shadow in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun Apr  7 10:31:24 2013 luc sinet
** Last update Sun Apr  7 10:47:01 2013 luc sinet
*/

#include "main.h"
#include "light.h"

void		transl_cam_to_spot(double *hit_pos, double *lig_pos,
				   t_vec *vpt, t_cam *cpt)
{
  double	vt[3];

  cpt->cx = hit_pos[0] + lig_pos[0];
  cpt->cy = hit_pos[1] + lig_pos[1];
  cpt->cz = hit_pos[2] + lig_pos[2];
  /* vt[0] = vpt->vx; */
  /* vt[1] = vpt->vy; */
  /* vt[2] = vpt->vz; */
  vpt->vx = lig_pos[0] - cpt->cx;
  vpt->vy = lig_pos[1] - cpt->cy;
  vpt->vz = lig_pos[2] - cpt->cz;
}

int		shadow(t_rt *rpt, t_lig *light, t_lco *lpt)
{
  double	k;

  transl_cam_to_spot(lpt->obj_coor, light->pos, rpt->vpt, rpt->cpt);
  calc_inter(rpt, &k);
  return ((k > ZERO && k < 1.0) ? 0 : 1);
}
