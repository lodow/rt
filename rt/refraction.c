/*
** refraction.c for rt in /home/dellam_a/Projet/rt/rt
**
** Made by Adrien Della Maggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Mon Apr  1 12:31:29 2013 Adrien Della Maggiora
** Last update Mon Apr 29 14:30:09 2013 Adrien
*/

#include <math.h>
#include "include/main.h"
#include "include/light.h"
#include "include/change_color.h"

int		calc_refrac(t_rt *rpt, t_vec *vpt, t_lco *lpt, double k, double n)
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
  /* unitaire(vec);  */
  /* unitaire(lpt->nvec);  */
  /* scal = scale(vec, lpt->nvec);  */
  /* tmp = n * n * (1 - pow(scal, 2)); */
  /* tmp = sqrt(tmp);  */
  /* vpt->vec[0] = n * vec[0] + (n + tmp) * lpt->nvec[0];  */
  /* vpt->vec[1] = n * vec[1] + (n + tmp) * lpt->nvec[1];  */
  /* vpt->vec[2] = n * vec[2] + (n + tmp) * lpt->nvec[2];  */
  return (0);
}

unsigned int    transparency(t_rt *rpt, t_lco *lpt, unsigned int color,
			     double k)
{
  int		obj;
  int		save_obj;
  double	n;
  double	alpha;
  double	vec[3];

  n = 1;
  save_obj = obj = rpt->obj_num;
  if (rpt->obj[rpt->obj_num].indice[1] != 1)
    printf("%f\n", rpt->obj[rpt->obj_num].indice[1]);
  copy_tab(rpt->vpt->vec, vec, 3);
  copy_tab(rpt->cpt->pos, rpt->cpt->ctmp, 3);
  while (rpt->obj[rpt->obj_num].indice[0] > ZERO
	 && rpt->obj[rpt->obj_num].indice[1] > ZERO && k > ZERO)
    {
      alpha = rpt->obj[obj].indice[0];
      obj = rpt->obj_num;
      if (calc_refrac(rpt, rpt->vpt, lpt, k, n / rpt->obj[obj].indice[1]) != -1)
	{
	  n = rpt->obj[obj].indice[1];
	  calc_inter(rpt, &k);
	  if (k > ZERO && rpt->obj_num != obj)
	    color = apply_indice(color, get_light(rpt, k, &rpt->obj[rpt->obj_num], lpt), alpha);
	  else if (k == -1)
	    color = apply_indice(color, 0x000000, alpha);
	}
    }
  copy_tab(rpt->cpt->ctmp, rpt->cpt->pos, 3);
  copy_tab(vec, rpt->vpt->vec, 3);
  rpt->obj_num = save_obj;
  return (color);
}
