/*
** calc_inter.c for inter in /home/sinet_l//rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Mar 20 16:55:47 2013 luc sinet
** Last update Mon Apr 29 17:24:24 2013 Adrien
*/

#include <math.h>
#include "include/main.h"
#include "include/inter.h"
#include "include/change_color.h"
#include "include/light.h"
#include "include/supersampling.h"

void	assign_function(t_rt *rpt)
{
  rpt->eptr[0] = &sphere;
  rpt->eptr[1] = &plan;
  rpt->eptr[2] = &cone;
  rpt->eptr[3] = &cylinder;
  rpt->eptr[4] = &moebius;
}

void		calc_inter(t_rt *rpt, double *kmin)
{
  double	k;
  int		i;

  i = 0;
  *kmin = -1;
  while (rpt->obj[i].type != -1)
    {
      k = move_cam(rpt, rpt->vpt, rpt->cpt, rpt->obj[i]);
      if (k > ZERO && (k < *kmin || *kmin == -1))
	{
	  *kmin = k;
	  rpt->obj_num = i;
	}
      ++i;
    }
}

void		new_coor(t_vec *vpt, t_cam *cpt, double x, double y)
{
  vpt->vec[0] = DIST - cpt->pos[0];
  vpt->vec[1] = (WINX / 2.0 - x) - cpt->pos[1];
  vpt->vec[2] = (WINY / 2.0 - y) - cpt->pos[2];
  rotate(vpt->vec, cpt->ccos, cpt->csin, 0);
}

unsigned int	get_pixel_color(t_rt *rpt)
{
  double	k;
  double	distance;
  t_lco		lpt;
  unsigned int	color;

  color = 0x000000;
  calc_inter(rpt, &k);
  distance = 200 * FOG_DIST;
  if (k != -1 && rpt->light[0].on == 1)
    {
      color = recomp_color(rpt->obj[rpt->obj_num].color);
      color = get_light(rpt, k, &rpt->obj[rpt->obj_num], &lpt);
      color = reflection(rpt, &lpt, color, k);
      color = transparency(rpt, &lpt, color, k);
      distance = rpt->obj[rpt->obj_num].dist;
    }
  color = apply_fog(color, rpt->opt->fog, distance);
  return (color);
}

void		calc_pixel(t_rt *rpt, t_cam *cpt, t_vec *vpt, t_par *ppt)
{
  t_samp	spt;
  unsigned int	color;
  int		pos[2];

  pos[1] = 0;
  assign_function(rpt);
  if ((spt.pixel = malloc(sizeof(int) * rpt->opt->aa)) == NULL)
    return ;
  rpt->obj_num = 0;
  while (pos[1] < WINY)
    {
      pos[0] = 0;
      while (pos[0] < WINX)
	{
	  new_coor(vpt, cpt, pos[0], pos[1]);
	  color = get_pixel_color(rpt);
	  my_pixel_put_to_image(pos[0], pos[1], ppt, color);
	  fill_img_param(pos, color, rpt, ppt);
	  ++pos[0];
	}
      print_i(ppt);
      ++pos[1];
    }
  detect_edge(rpt, ppt);
  apply_supersampling(rpt, ppt, &spt);
}
