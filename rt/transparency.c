/*
** transparency.c for transparency in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun May  5 18:27:59 2013 luc sinet
** Last update Sat May 11 14:42:17 2013 Adrien Della Maggiora
*/

#include <math.h>
#include "main.h"
#include "light.h"
#include "change_color.h"

unsigned int	calc_trans(unsigned int *all_color, double *alpha, int i,
			   unsigned int color)
{
  unsigned int	res;

  res = all_color[i--];
  while (i >= 0)
    {
      res = apply_indice(all_color[i], res, alpha[i + 1]);
      --i;
    }
  res = apply_indice(color, res, alpha[0]);
  return (res);
}

unsigned int    transparency(t_rt *rpt, t_lco *lpt, unsigned int color,
			     double k)
{
  int		obj;
  int		i;
  int		save_obj;
  double	n;
  double	vec[3];
  double	alpha[MAX_R];
  unsigned int	all_color[MAX_R];

  n = 1;
  save_obj = obj = rpt->obj_num;
  copy_tab(rpt->vpt->vec, vec, 3);
  copy_tab(rpt->cpt->pos, rpt->cpt->ctmp, 3);
  i = 0;
  while (i < MAX_R && rpt->obj[rpt->obj_num].indice[0] > ZERO && n > ZERO
	 && k > ZERO)
    {
      obj = rpt->obj_num;
      alpha[i] = rpt->obj[obj].indice[0];
      calc_refrac(rpt, rpt->vpt, lpt, k, rpt->obj[obj].indice[1] / n);
      n = rpt->obj[obj].indice[1];
      calc_inter(rpt, &k);
      if (k > ZERO && rpt->obj_num != obj)
	all_color[i++] = get_light(rpt, k, &rpt->obj[rpt->obj_num], lpt);
      else if (k == -1)
	all_color[i++]  = 0x000000;
    }
  copy_tab(rpt->cpt->ctmp, rpt->cpt->pos, 3);
  copy_tab(vec, rpt->vpt->vec, 3);
  rpt->obj_num = save_obj;
  return ((i > 0) ? calc_trans(all_color, alpha, i - 1, color) : color);
}
