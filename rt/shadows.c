/*
** shadows.c for rt in /home/dellam_a/Projet/rt/rt
**
** Made by Adrien Della Maggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Tue Apr  9 10:14:18 2013 Adrien Della Maggiora
** Last update Tue Apr  9 18:15:26 2013 Adrien Della Maggiora
*/

#include <math.h>
#include "main.h"
#include "light.h"

void		re_init(t_vec *vpt, t_cam *cpt, double angle[4])
{
  double	icos[3];
  double	isin[3];

  rotate_x(&vpt->vz, &vpt->vy, cos((-angle[0]) * M_PI / 180),
	   sin((-angle[0]) * M_PI / 180));
  rotate_y(&vpt->vz, &vpt->vx, cos((-angle[1]) * M_PI / 180),
	   sin((-angle[1]) * M_PI / 180));
  rotate_z(&vpt->vx, &vpt->vy, cos((-angle[2]) * M_PI / 180),
	   sin((-angle[2]) * M_PI / 180));
  rotate_x(&cpt->cz, &cpt->cy, cos((-angle[0]) * M_PI / 180),
	   sin((-angle[0]) * M_PI / 180));
  rotate_y(&cpt->cz, &cpt->cx, cos((-angle[1]) * M_PI / 180),
	   sin((-angle[1]) * M_PI / 180));
  rotate_z(&cpt->cx, &cpt->cy, cos((-angle[2]) * M_PI / 180),
	   sin((-angle[2]) * M_PI / 180));
}

int		shadows(t_rt *rpt, t_cam *cpt, t_lig *spot, t_lco *lpt)
{
  double	cam[3];
  double	k;
  int		obj;

  obj = rpt->obj_num;
  cam[0] = cpt->cx;
  cam[1] = cpt->cy;
  cam[2] = cpt->cz;
  cpt->cx = lpt->obj_coor[0] + rpt->obj[obj].pos[0];
  cpt->cy = lpt->obj_coor[1] + rpt->obj[obj].pos[1];
  cpt->cz = lpt->obj_coor[2] + rpt->obj[obj].pos[2];
  rpt->vpt->vx = spot->pos[0] - lpt->obj_coor[0];
  rpt->vpt->vy = spot->pos[1] - lpt->obj_coor[1];
  rpt->vpt->vz = spot->pos[2] - lpt->obj_coor[2];

  rotate_x(&rpt->vpt->vz, &rpt->vpt->vy, cos((rpt->obj[obj].angle[0]) * M_PI / 180),
	   sin((rpt->obj[obj].angle[0]) * M_PI / 180));
  rotate_y(&rpt->vpt->vz, &rpt->vpt->vx, cos((rpt->obj[obj].angle[1]) * M_PI / 180),
	   sin((rpt->obj[obj].angle[1]) * M_PI / 180));
  rotate_z(&rpt->vpt->vx, &rpt->vpt->vy, cos((rpt->obj[obj].angle[2]) * M_PI / 180),
	   sin((rpt->obj[obj].angle[2]) * M_PI / 180));
   rotate_x(&cpt->cz, &cpt->cy, cos((rpt->obj[obj].angle[0]) * M_PI / 180),
   	   sin((rpt->obj[obj].angle[0]) * M_PI / 180));
   rotate_y(&cpt->cz, &cpt->cx, cos((rpt->obj[obj].angle[1]) * M_PI / 180),
   	   sin((rpt->obj[obj].angle[1]) * M_PI / 180));
   rotate_z(&cpt->cx, &cpt->cy, cos((rpt->obj[obj].angle[2]) * M_PI / 180),
   	   sin((rpt->obj[obj].angle[2]) * M_PI / 180));
/* re_init(rpt->vpt, cpt, rpt->obj[obj].angle); */
  calc_inter(rpt, &k);
  cpt->cx = cam[0];
  cpt->cy = cam[1];
  cpt->cz = cam[2];
  if (rpt->obj_num != obj && (k > ZERO && k < 1))
    return (0);
  return (1);
}
