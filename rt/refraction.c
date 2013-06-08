/*
** refraction.c for rt in /home/dellam_a/Projet/rt/rt
**
** Made by Adrien Della Maggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Mon Apr  1 12:31:29 2013 Adrien Della Maggiora
** Last update Sat Jun  8 18:13:06 2013 etienne debas
*/

#include <math.h>
#include "main.h"
#include "light.h"
#include "change_color.h"

double		get_positive_scalar(double *vec1, double *vec2)
{
  double	scal;

  scal = scale(vec1, vec2);
  if (scal < ZERO)
    {
      invert_vec(vec1);
      scal = scale(vec2, vec1);
    }
  return (scal);
}

void		calc_refrac(t_rt *rpt, t_lco *lpt,
			    double k, double n)
{
  double	cvec[3];
  double	*vec;
  double	scal;
  double	tmp;

  vec = rpt->vpt->vec;
  get_inter_normal(rpt, rpt->vpt, k, lpt);
  cvec[0] = lpt->obj_coor[0] - rpt->cpt->pos[0];
  cvec[1] = lpt->obj_coor[1] - rpt->cpt->pos[1];
  cvec[2] = lpt->obj_coor[2] - rpt->cpt->pos[2];
  copy_tab(lpt->obj_coor, rpt->cpt->pos, 3);
  unitaire(cvec);
  unitaire(lpt->nvec);
  scal = get_positive_scalar(lpt->nvec, cvec);
  tmp = 1 + (n * n) * ((scal * scal) - 1);
  tmp = (tmp > ZERO) ? sqrt(tmp) : 0;
  vec[0] = n * cvec[0] + (n * scal - tmp) * lpt->nvec[0];
  vec[1] = n * cvec[1] + (n * scal - tmp) * lpt->nvec[1];
  vec[2] = n * cvec[2] + (n * scal - tmp) * lpt->nvec[2];
}
