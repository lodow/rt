/*
** refraction.c for rt in /home/dellam_a/Projet/rt/rt
**
** Made by Adrien Della Maggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Mon Apr  1 12:31:29 2013 Adrien Della Maggiora
** Last update Tue May  7 10:06:35 2013 luc sinet
*/

#include <math.h>
#include "include/main.h"
#include "include/light.h"
#include "include/change_color.h"

void		calc_refrac(t_rt *rpt, t_vec *vpt, t_lco *lpt,
			    double k, double n)
{
  double        vec[3];
  double        scal;
  double	tmp;

  get_inter_normal(rpt, vpt, k, lpt);
  vec[0] = lpt->obj_coor[0] - rpt->cpt->pos[0];
  vec[1] = lpt->obj_coor[1] - rpt->cpt->pos[1];
  vec[2] = lpt->obj_coor[2] - rpt->cpt->pos[2];
  rpt->cpt->pos[0] = lpt->obj_coor[0];
  rpt->cpt->pos[1] = lpt->obj_coor[1];
  rpt->cpt->pos[2] = lpt->obj_coor[2];
  unitaire(vec);
  unitaire(lpt->nvec);
  scal = scale(vec, lpt->nvec);
  tmp = 1 + (n * n) * ((scal * scal) - 1);
  tmp = (tmp > ZERO) ? sqrt(tmp) : 0;
  vpt->vec[0] = n * vec[0] + (n * scal - tmp) * lpt->nvec[0];
  vpt->vec[1] = n * vec[1] + (n * scal - tmp) * lpt->nvec[1];
  vpt->vec[2] = n * vec[2] + (n * scal - tmp) * lpt->nvec[2];
}
