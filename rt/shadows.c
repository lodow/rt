/*
** shadows.c for rt in /home/dellam_a/Projet/rt/rt
**
** Made by Adrien Della Maggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Tue Apr  9 10:14:18 2013 Adrien Della Maggiora
** Last update Mon Apr 15 23:12:04 2013 luc sinet
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
  cam[0] = cpt->pos[0];
  cam[1] = cpt->pos[1];
  cam[2] = cpt->pos[2];
  cpt->pos[0] = lpt->obj_coor[0];
  cpt->pos[1] = lpt->obj_coor[1];
  cpt->pos[2] = lpt->obj_coor[2];
  rpt->vpt->vec[0] = spot->pos[0] - lpt->obj_coor[0];
  rpt->vpt->vec[1] = spot->pos[1] - lpt->obj_coor[1];
  rpt->vpt->vec[2] = spot->pos[2] - lpt->obj_coor[2];
  calc_inter(rpt, &k);
  cpt->pos[0] = cam[0];
  cpt->pos[1] = cam[1];
  cpt->pos[2] = cam[2];
 if (rpt->obj_num != obj && (k > ZERO && k < 1))
    return (0);
  return (1);
}
