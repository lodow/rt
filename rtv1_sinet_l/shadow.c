/*
** shadow.c for shadow in /home/sinet_l//rtv1-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri Mar 15 11:13:20 2013 luc sinet
** Last update Sun Mar 17 20:05:16 2013 luc sinet
*/

#include "main.h"
#include "lightning.h"

int	darken_color(int color)
{
  int	c[3];

  c[0] = (color & 0xFF) / 2;
  c[1] = ((color >> 8) & 0xFF) / 2;
  c[2] = ((color >> 16) & 0xFF) / 2;
  color = c[2] << 8;
  color = (color | c[1]) << 8;
  color = (color | c[0]);
  return (color);
}

void	transl_cam_to_spot(t_rt *rpt, t_lig *lpt)
{
  double        vt[3];

   rpt->cpt->cx = rpt->lpt->ocor[0] + rpt->tab[rpt->lpt->obj].pos[0];
  rpt->cpt->cy = rpt->lpt->ocor[1] + rpt->tab[rpt->lpt->obj].pos[1];
  rpt->cpt->cz = rpt->lpt->ocor[2] + rpt->tab[rpt->lpt->obj].pos[2];
  vt[0] = rpt->vpt->vx;
  vt[1] = rpt->vpt->vy;
  vt[2] = rpt->vpt->vz;
  rotate_vec(&rpt->tab[rpt->lpt->obj], vt);
  rpt->vpt->vx = lpt->pos[0] - rpt->cpt->cx;
  rpt->vpt->vy = lpt->pos[1] - rpt->cpt->cy;
  rpt->vpt->vz = lpt->pos[2] - rpt->cpt->cz;
}

double		shadow(t_rt *rpt, t_lig *lpt, int color)
{
  double	k;
  int		ncolor;

  transl_cam_to_spot(rpt, lpt);
  check_inter(rpt, rpt->tab, &k, &ncolor);
  return ((k > ZERO && k < 1.0) ? darken_color(color) : color);
}
