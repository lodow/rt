/*
** transparency.c for transparency in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun May  5 18:27:59 2013 luc sinet
** Last update Mon May 20 12:34:46 2013 luc sinet
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

unsigned int    transparency(t_rt *rpt, t_lco *lpt, unsigned int color,
			     double k)
{
  int		obj;
  int		i;
  int		save_obj;
  double	n;
  double	vec[3];
  double	ctmp[3];
  double	alpha[MAX_R];
  unsigned int	all_color[MAX_R];
  int		pass[256];
  double       	refrac;

  n = 1;
  save_obj = obj = rpt->obj_num;
  my_memset(pass, -1, 256);
  copy_tab(rpt->vpt->vec, vec, 3);
  copy_tab(rpt->cpt->pos, ctmp, 3);
  i = 0;
  while (i < MAX_R && rpt->obj[rpt->obj_num].indice[0] > ZERO && n > ZERO
	 && k > ZERO)
    {
      obj = rpt->obj_num;
      alpha[i] = rpt->obj[obj].indice[0];
      refrac = get_refrac_ratio(rpt->obj, &rpt->obj[obj], pass, obj);
      calc_refrac(rpt, rpt->vpt, lpt, k, refrac);
      n = rpt->obj[obj].indice[1];
      calc_inter(rpt, &k);
      if (k > ZERO && rpt->obj_num != obj)
	all_color[i++] = modifie_p_color(rpt, k, 1);
      else if (k == -1)
	all_color[i++]  = 0x000000;
    }
  copy_tab(ctmp, rpt->cpt->pos, 3);
  copy_tab(vec, rpt->vpt->vec, 3);
  rpt->obj_num = save_obj;
  return ((i > 0) ? calc_trans(all_color, alpha, i - 1, color) : color);
}
