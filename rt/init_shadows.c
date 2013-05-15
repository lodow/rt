/*
** init_shadows.c for init_shadows.c in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue May 14 17:09:58 2013 luc sinet
** Last update Wed May 15 14:34:34 2013 luc sinet
*/

#include "main.h"
#include "light.h"

void	add_to_coor(t_shadow *spt, int i, double *coor)
{
  int	x;

  x = 0;
  while (x < 3)
    {
      spt->coor[i][x] = coor[x];
      ++x;
    }
}

void	remove_from_coor(t_shadow *spt, int i)
{
  int	x;

  x = 0;
  while (x < 3)
    spt->coor[i][x++] = -1;
}

void   	init_shadows(t_shadow *spt, t_rt *rpt, double *cpos, t_lco *lpt)
{
  spt->slpt = lpt;
  spt->sdw_coef = 1.0;
  spt->vpos = rpt->vpt->vec;
  copy_tab(spt->vpos, spt->vec, 3);
  copy_tab(cpos, spt->cam, 3);
  copy_tab(lpt->obj_coor, spt->inter, 3);
  spt->obj[0] = rpt->obj_num;
  spt->hit = 0;
}
