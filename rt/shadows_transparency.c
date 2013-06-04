/*
** shadows_transparency.c for shadows_transparency in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue May 14 18:05:07 2013 luc sinet
** Last update Tue Jun  4 11:40:12 2013 luc sinet
*/

#include "main.h"
#include "light.h"
#include "pars.h"
#include "change_color.h"

void	get_cur_coor(double *cpos, double *vec, double k, double *coor)
{
  coor[0] = cpos[0] + k * vec[0];
  coor[1] = cpos[1] + k * vec[1];
  coor[2] = cpos[2] + k * vec[2];
}

void		handle_transparency(t_shadow *spt, t_rt *rpt,
				    t_obj *obj, double k)
{
  double	cur_coor[3];
  double	distance;
  int		i;

  i = 0;
  if (obj->type == PLAN)
    filter_light_color(spt->light->lcolor, obj, PLAN_SIZE);
  else if (obj->ipt->indice[0] > ZERO)
    {
      get_cur_coor(rpt->cpt->pos, rpt->vpt->vec, k, cur_coor);
      if (find_in_tab(spt->pass, rpt->obj_num, &i) == 1)
	{
	  distance = point_distance(cur_coor, &(spt->coor[i * 3]));
	  remove_from_coor(&spt->coor[i * 3]);
	  filter_light_color(spt->light->lcolor, obj, distance);
	}
      else
	add_to_coor(&spt->coor[i * 3], cur_coor);
      add_to_tab(spt->pass, rpt->obj_num);
   }
}
