/*
** reset_calc.c for reset_calc.c in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun May 19 22:41:07 2013 luc sinet
** Last update Sun May 19 22:42:22 2013 luc sinet
*/

#include "main.h"
#include "inter.h"

void	assign_function(t_rt *rpt)
{
  rpt->eptr[0] = &sphere;
  rpt->eptr[1] = &plan;
  rpt->eptr[2] = &cone;
  rpt->eptr[3] = &cylinder;
  rpt->eptr[4] = &circle;
  rpt->eptr[5] = &square;
  rpt->eptr[6] = &triangle;
  rpt->eptr[7] = &paraboloide;
  rpt->eptr[8] = &hyperboloide;
  rpt->eptr[9] = &moebius;
  rpt->eptr[10] = &tangle;
}

void		new_coor(t_vec *vpt, t_cam *cpt, double x, double y)
{
  vpt->vec[0] = DIST - cpt->pos[0];
  vpt->vec[1] = (WINX / 2.0 - x) - cpt->pos[1];
  vpt->vec[2] = (WINY / 2.0 - y) - cpt->pos[2];
  rotate(vpt->vec, cpt->ccos, cpt->csin, 0);
}
