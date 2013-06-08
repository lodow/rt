/*
** transparency.c for transparency in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun May  5 18:27:59 2013 luc sinet
** Last update Sat Jun  8 18:05:43 2013 etienne debas
*/

#include <math.h>
#include "main.h"
#include "light.h"
#include "change_color.h"

unsigned int	calc_trans(unsigned int *all_color, double *alpha, int i)
{
  unsigned int	res;

  res = all_color[i--];
  while (i >= 0)
    {
      res = apply_indice(all_color[i], res, alpha[i]);
      --i;
    }
  return (res);
}

double	get_refrac_ratio(t_obj *tab, double indice, int *pass, int obj_num)
{
  int	i;
  int	found;

  i = 0;
  found = find_in_tab(pass, obj_num, &i);
  if ((tab[obj_num].type > 2 && tab[obj_num].type < 7) || found)
    return ((i == 0) ? (AIR / indice) :
	    (tab[pass[i - 1]].ipt->indice[1] / indice));
  else
    return ((i == 0) ? indice : (indice / tab[pass[i - 1]].ipt->indice[1]));
}

double		transparency_loop(t_rt *rpt, t_lco *lpt, t_trans *trans,
				  double k)
{
  double	refrac;
  int		obj;
  int		found;
  int		i;

  i = 0;
  obj = rpt->obj_num;
  refrac = get_refrac_ratio(rpt->obj, rpt->obj[obj].ipt->indice[1],
			    trans->pass, obj);
  calc_refrac(rpt, lpt, k, refrac);
  add_to_tab(trans->pass, obj);
  calc_inter(rpt, &k);
  found = find_in_tab(trans->pass, rpt->obj_num, &i);
  if (k > ZERO && rpt->obj_num != obj && !found)
    {
      trans->alpha[trans->count] = rpt->obj[rpt->obj_num].ipt->indice[0];
      trans->color[trans->count++] = modifie_p_color(rpt, k, 1);
    }
  else if (k == -1)
    trans->color[trans->count++] = 0x000000;
  ++trans->nb_obj;
  return (k);
}

unsigned int    transparency(t_rt *rpt, t_lco *lpt, unsigned int color,
			     double k)
{
  int		save_obj;
  double	vec[3];
  double	ctmp[3];
  t_trans	trans;

  trans.count = 1;
  trans.nb_obj = 0;
  save_obj = rpt->obj_num;
  trans.alpha[trans.nb_obj] = rpt->obj[save_obj].ipt->indice[0];
  trans.color[trans.nb_obj++] = color;
  my_memset(trans.pass, -1, 256);
  copy_tab(rpt->vpt->vec, vec, 3);
  copy_tab(rpt->cpt->pos, ctmp, 3);
  while (trans.nb_obj < MAX_R &&
	 rpt->obj[rpt->obj_num].ipt->indice[0] > ZERO && k > ZERO)
    k = transparency_loop(rpt, lpt, &trans, k);
  copy_tab(ctmp, rpt->cpt->pos, 3);
  copy_tab(vec, rpt->vpt->vec, 3);
  rpt->obj_num = save_obj;
  return (calc_trans(trans.color, trans.alpha, trans.count - 1));
}
