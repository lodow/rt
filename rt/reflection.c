/*
** reflection.c for reflection in /tmp/rt/rt
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Tue Apr  2 18:25:49 2013 etienne debas
** Last update Mon Apr 22 14:26:31 2013 luc sinet
*/

#include <math.h>
#include "include/main.h"
#include "include/change_color.h"
#include "include/light.h"

void		calc_reflec_vector(t_vec *vpt, t_cam *cpt, t_lco *lpt, t_obj *obj)
{
  double	res[3];
  double	vec[3];
  double	scal;

  vec[0] = lpt->obj_coor[0] - cpt->pos[0];
  vec[1] = lpt->obj_coor[1] - cpt->pos[1];
  vec[2] = lpt->obj_coor[2] - cpt->pos[2];
  cpt->pos[0] = lpt->obj_coor[0];
  cpt->pos[1] = lpt->obj_coor[1];
  cpt->pos[2] = lpt->obj_coor[2];
  unitaire(vec);
  unitaire(lpt->nvec);
  scal = scale(vec, lpt->nvec);
  res[0] = (-2 * lpt->nvec[0] * scal) + vec[0];
  res[1] = (-2 * lpt->nvec[1] * scal) + vec[1];
  res[2] = (-2 * lpt->nvec[2] * scal) + vec[2];
  vpt->vec[0] = res[0];
  vpt->vec[1] = res[1];
  vpt->vec[2] = res[2];
 }

unsigned int	apply_reflection(unsigned int color, unsigned int obj_color,
				 double indice)
{
  unsigned char	c[3];
  unsigned char	c_obj[3];

  decomp_color(color, c);
  decomp_color(obj_color, c_obj);
  printf("%d %d %d\n", c[0], c[1], c[2]);
  c[0] = (double)c[0] * (1.0 - indice) + (double)c_obj[0] * indice;
  c[1] = (double)c[1] * (1.0 - indice) + (double)c_obj[1] * indice;
  c[2] = (double)c[2] * (1.0 - indice) + (double)c_obj[2] * indice;
  return (recomp_color(c));
}

unsigned int	reflection(t_rt *rpt, t_lco *lpt, unsigned int color)
{
  double	indice;
  double	k;
  int		i;

  i = 0;
  copy_tab(rpt->cpt->pos, rpt->cpt->ctmp, 3);
  while (i < MAX_R && rpt->obj[rpt->obj_num].indice[2] >= ZERO)
    {
      indice = rpt->obj[rpt->obj_num].indice[2];
      calc_reflec_vector(rpt->vpt, rpt->cpt, lpt, &rpt->obj[rpt->obj_num]);
      calc_inter(rpt, &k);
      color = apply_reflection(color, (k > ZERO) ?
			       get_light(rpt, k, &rpt->obj[rpt->obj_num], lpt)
			       : 0x000000, indice);
      ++i;
    }
  copy_tab(rpt->cpt->ctmp, rpt->cpt->pos, 3);
  return (color);
}
