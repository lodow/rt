/*
** lightning.c for lightning in /home/sinet_l//rtv1-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Mar 14 11:27:11 2013 luc sinet
** Last update Sun Mar 17 19:57:07 2013 luc sinet
*/

#include <math.h>
#include "lightning.h"
#include "main.h"

void		solve_param(t_rt *rpt, int i, double k, int type)
{
  double	vt[3];

  vt[0] = rpt->vpt->vx;
  vt[1] = rpt->vpt->vy;
  vt[2] = rpt->vpt->vz;
  rotate_vec(&rpt->tab[rpt->lpt->obj], vt);
  rpt->cpt->tx = rpt->cpt->cx - rpt->tab[rpt->lpt->obj].pos[0];
  rpt->cpt->ty = rpt->cpt->cy - rpt->tab[rpt->lpt->obj].pos[1];
  rpt->cpt->tz = rpt->cpt->cz - rpt->tab[rpt->lpt->obj].pos[2];
  rpt->lpt->ocor[0] = rpt->cpt->tx + k * vt[0];
  rpt->lpt->ocor[1] = rpt->cpt->ty + k * vt[1];
  rpt->lpt->ocor[2] = rpt->cpt->tz + k * vt[2];
  rpt->lpt->lvec[0] = rpt->ltab[i].pos[0] - rpt->lpt->ocor[0];
  rpt->lpt->lvec[1] = rpt->ltab[i].pos[1] - rpt->lpt->ocor[1];
  rpt->lpt->lvec[2] = rpt->ltab[i].pos[2] - rpt->lpt->ocor[2];
}

void	get_normal(t_elem *ept, t_lco *lpt, int type)
{
  lpt->nvec[0] = (double)NX(type, lpt->ocor[0]);
  lpt->nvec[1] = (double)NY(type, lpt->ocor[1]);
  lpt->nvec[2] = (double)NZ(type, 0.5, lpt->ocor[2]);
  rotate_vec(ept, lpt->nvec);
}

int	new_color(int color, double cosa, t_lig *lpt, t_elem *ept)
{
  int	ncolor;
  int	r;
  int	g;
  int	b;

  ncolor = 0;
  color = color * (1 - ept->bright) + lpt->lcolor * ept->bright;
  b = (color & 0xff) * cosa * lpt->intensity;
  g = ((color >> 8) & 0xff) * cosa * lpt->intensity;
  r = ((color >> 16) & 0xff) * cosa * lpt->intensity;
  ncolor = (ncolor | r) << 8;
  ncolor = (ncolor | g) << 8;
  ncolor = (ncolor | b);
  return (ncolor);
}

int		get_light(t_rt *rpt, double k, int type, int color)
{
  double	bnorme;
  double	cosa;

  solve_param(rpt, 0, k, type);
  get_normal(&rpt->tab[rpt->lpt->obj], rpt->lpt, type);
  bnorme = (sqrt(pow(rpt->lpt->nvec[0], 2) + pow(rpt->lpt->nvec[1], 2)
		 + pow(rpt->lpt->nvec[2], 2))
	    * sqrt(pow(rpt->lpt->lvec[0], 2) + pow(rpt->lpt->lvec[1], 2)
		   + pow(rpt->lpt->lvec[2], 2)));
  cosa = (rpt->lpt->nvec[0] * rpt->lpt->lvec[0]
	  + rpt->lpt->nvec[1] * rpt->lpt->lvec[1]
	  + rpt->lpt->nvec[2] * rpt->lpt->lvec[2]) / bnorme;
  return ((cosa < ZERO) ? 0x000000 :
	  new_color(color, cosa, &rpt->ltab[0], &rpt->tab[rpt->lpt->obj]));
}
