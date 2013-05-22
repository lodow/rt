/*
** transparency.c for transparency in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun May  5 18:27:59 2013 luc sinet
** Last update Wed May 22 11:34:36 2013 Adrien Della Maggiora
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

double	get_refrac_ratio(t_obj *tab, t_obj *obj, int *pass, int obj_num)
{
  int	i;
  int	found;

  i = 0;
  found = find_in_tab(pass, obj_num, &i);
  add_to_tab(pass, obj_num);
  if (!found)
    {
      if (i == 0)
	return (obj->indice[1]);
      else
	return (obj->indice[1] / tab[pass[i - 1]].indice[1]);
    }
  else
    {
      if (i - 1 < 0)
	return (AIR);
      else
	return (tab[pass[i - 1]].indice[1] / obj->indice[1]);
    }
}

void		transparency_loop(t_rt *rpt, t_lco *lpt, t_trans *trans,
				  double k)
{
  double	refrac;
  int		obj;

  obj = rpt->obj_num;
  trans->alpha[trans->count] = rpt->obj[obj].indice[0];
  refrac = get_refrac_ratio(rpt->obj, &rpt->obj[obj],
			    trans->pass, obj);
  calc_refrac(rpt, rpt->vpt, lpt, k, refrac);
  calc_inter(rpt, &k);
  if (k > ZERO && rpt->obj_num != obj)
    trans->color[trans->count++] = modifie_p_color(rpt, k, 1);
  else if (k == -1)
    trans->color[trans->count++]  = 0x000000;
}

unsigned int    transparency(t_rt *rpt, t_lco *lpt, unsigned int color,
			     double k)
{
  int		save_obj;
  double	vec[3];
  double	ctmp[3];
  t_trans	trans;

  trans.count = 0;
  save_obj = rpt->obj_num;
  my_memset(trans.pass, -1, 256);
  copy_tab(rpt->vpt->vec, vec, 3);
  copy_tab(rpt->cpt->pos, ctmp, 3);
  while (trans.count < MAX_R && rpt->obj[rpt->obj_num].indice[0] > ZERO && k > ZERO)
    transparency_loop(rpt, lpt, &trans, k);
  copy_tab(ctmp, rpt->cpt->pos, 3);
  copy_tab(vec, rpt->vpt->vec, 3);
  rpt->obj_num = save_obj;
  return ((trans.count > 0) ? calc_trans(trans.color, trans.alpha,
					 trans.count - 1, color) : color);
}
