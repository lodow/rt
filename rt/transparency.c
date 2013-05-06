/*
** transparency.c for transparency in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun May  5 18:27:59 2013 luc sinet
** Last update Sun May  5 18:33:21 2013 luc sinet
*/

#include <math.h>
#include "include/main.h"
#include "include/light.h"
#include "include/change_color.h"

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
  copy_tab(rpt->vpt->vec, vec, 3);
  copy_tab(rpt->cpt->pos, rpt->cpt->ctmp, 3);
  while (rpt->obj[rpt->obj_num].indice[0] > ZERO
	 && rpt->obj[rpt->obj_num].indice[1] > ZERO && k > ZERO)
    {
      obj = rpt->obj_num;
      alpha = rpt->obj[obj].indice[0];
      calc_refrac(rpt, rpt->vpt, lpt, k, rpt->obj[obj].indice[1] / n);
      n = rpt->obj[obj].indice[1];
      calc_inter(rpt, &k);
      if (k > ZERO && rpt->obj_num != obj)
	color = apply_indice(color, get_light(rpt, k, &rpt->obj[rpt->obj_num],
					      lpt), alpha);
      else if (k == -1)
	color = apply_indice(color, 0x000000, alpha);
    }
  copy_tab(rpt->cpt->ctmp, rpt->cpt->pos, 3);
  copy_tab(vec, rpt->vpt->vec, 3);
  rpt->obj_num = save_obj;
  return (color);
}
