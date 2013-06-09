/*
** reflection.c for reflection in /tmp/rt/rt
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Tue Apr  2 18:25:49 2013 etienne debas
** Last update Sun Jun  9 06:46:08 2013 adrien dellamaggiora
*/

#include <math.h>
#include "main.h"
#include "change_color.h"
#include "light.h"

void		calc_reflec_vector(t_rt *rpt, t_vec *vpt, t_lco *lpt, double k)
{
  double	vec[3];
  double	scal;

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
  vpt->vec[0] = (-2 * lpt->nvec[0] * scal) + vec[0];
  vpt->vec[1] = (-2 * lpt->nvec[1] * scal) + vec[1];
  vpt->vec[2] = (-2 * lpt->nvec[2] * scal) + vec[2];
}

unsigned int	apply_indice(unsigned int color, unsigned int obj_color,
			     double indice)
{
  unsigned char	c[3];
  unsigned char	c_obj[3];

  decomp_color(color, c);
  decomp_color(obj_color, c_obj);
  c[0] = (double)c[0] * (1.0 - indice) + (double)c_obj[0] * indice;
  c[1] = (double)c[1] * (1.0 - indice) + (double)c_obj[1] * indice;
  c[2] = (double)c[2] * (1.0 - indice) + (double)c_obj[2] * indice;
  return (recomp_color(c));
}

unsigned int	apply_reflec_color(t_reflec *reflec)
{
  unsigned int	res;

  res = reflec->color[--reflec->count];
  --reflec->count;
  while (reflec->count >= 0)
    {
      res = apply_indice(reflec->color[reflec->count], res,
			 reflec->alpha[reflec->count]);
      --reflec->count;
    }
  return (res);
}

unsigned int	reflection(t_rt *rpt, t_lco *lpt,
			   unsigned int color, double k)
{
  t_reflec	reflec;
  double	ctmp[6];
  int		i;
  int		obj;

  i = 0;
  reflec.count = 0;
  obj = rpt->obj_num;
  copy_tab(rpt->cpt->pos, ctmp, 3);
  reflec.alpha[reflec.count] = rpt->obj[rpt->obj_num].ipt->indice[2];
  reflec.color[reflec.count++] = color;
  while (i < MAX_R && rpt->obj[rpt->obj_num].ipt->indice[2] >= ZERO
         && k > ZERO)
    {
      calc_reflec_vector(rpt, rpt->vpt, lpt, k);
      calc_inter(rpt, &k);
      reflec.alpha[reflec.count] = rpt->obj[rpt->obj_num].ipt->indice[2];
      reflec.color[reflec.count++] = modifie_p_color(rpt, k, 2);
      ++i;
    }
  copy_tab(ctmp, rpt->cpt->pos, 3);
  rpt->obj_num = obj;
  return (apply_reflec_color(&reflec));
}
