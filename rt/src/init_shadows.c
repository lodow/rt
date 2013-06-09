/*
** init_shadows.c for init_shadows.c in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue May 14 17:09:58 2013 luc sinet
** Last update Sat Jun  8 18:12:31 2013 maxime lavandier
*/

#include "main.h"
#include "light.h"

void	add_to_coor(double *tab, double *coor)
{
  int	x;

  x = 0;
  while (x < 3)
    {
      tab[x] = coor[x];
      ++x;
    }
}

void	remove_from_coor(double *tab)
{
  int	x;

  x = 0;
  while (x < 3)
    tab[x++] = -1;
}

void	init_shadows(t_shadow *spt, t_rt *rpt, double *cpos, t_lco *lpt)
{
  spt->slpt = lpt;
  spt->sdw_coef = 1.0;
  spt->vpos = rpt->vpt->vec;
  copy_tab(spt->vpos, spt->vec, 3);
  copy_tab(cpos, spt->cam, 3);
  copy_tab(lpt->obj_coor, spt->inter, 3);
  spt->obj[0] = rpt->obj_num;
  spt->hit = 0;
  my_memset(spt->coor, 256 * 3, -1);
}
