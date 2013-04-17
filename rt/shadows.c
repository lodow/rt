/*
** shadows.c for rt in /home/dellam_a/Projet/rt/rt
**
** Made by Adrien Della Maggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Tue Apr  9 10:14:18 2013 Adrien Della Maggiora
** Last update Wed Apr 17 16:09:06 2013 Adrien
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
  copy_tab(cpt->pos, cam, 3);
  copy_tab(lpt->obj_coor, cpt->pos, 3);
  cpt->pos[0] += rpt->obj[obj].pos[0];
  cpt->pos[1] += rpt->obj[obj].pos[1];
  cpt->pos[2] += rpt->obj[obj].pos[2];
  rpt->vpt->vec[0] = spot->pos[0] - cpt->pos[0];
  rpt->vpt->vec[1] = spot->pos[1] - cpt->pos[1];
  rpt->vpt->vec[2] = spot->pos[2] - cpt->pos[2];
  calc_inter(rpt, &k);
  copy_tab(cam, cpt->pos, 3);
  if (rpt->obj_num != obj && (k > ZERO && k < 1))
    return (0);
  return (1);
}
