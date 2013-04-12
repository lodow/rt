/*
** shadows.c for rt in /home/dellam_a/Projet/rt/rt
**
** Made by Adrien Della Maggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Tue Apr  9 10:14:18 2013 Adrien Della Maggiora
** Last update Fri Apr 12 14:41:23 2013 Adrien Della Maggiora
*/

#include <math.h>
#include "include/main.h"
#include "include/light.h"

int		shadows(t_rt *rpt, t_cam *cpt, t_lig *spot, t_lco *lpt)
{
  double	cam[3];
  double	k;
  int		obj;

  obj = rpt->obj_num;
  cam[0] = cpt->cx;
  cam[1] = cpt->cy;
  cam[2] = cpt->cz;
  cpt->cx = lpt->obj_coor[0];
  cpt->cy = lpt->obj_coor[1];
  cpt->cz = lpt->obj_coor[2];
  rpt->vpt->vx = spot->pos[0] - lpt->obj_coor[0];
  rpt->vpt->vy = spot->pos[1] - lpt->obj_coor[1];
  rpt->vpt->vz = spot->pos[2] - lpt->obj_coor[2];
  calc_inter(rpt, &k);
  cpt->cx = cam[0];
  cpt->cy = cam[1];
  cpt->cz = cam[2];
 if (rpt->obj_num != obj && (k > ZERO && k < 1))
    return (0);
  return (1);
}
