/*
** calc_inter.c for inter in /home/sinet_l//rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Mar 20 16:55:47 2013 luc sinet
** Last update Mon Jun  3 23:52:35 2013 luc sinet
*/

#include <math.h>
#include "main.h"
#include "inter.h"
#include "change_color.h"
#include "light.h"
#include "supersampling.h"

void		calc_inter(t_rt *rpt, double *kmin)
{
  t_obj		*obj;
  double	k;
  int		i;

  i = 0;
  obj = &(rpt->obj[i]);
  *kmin = -1;
  rpt->obj_num = 0;
  while (obj->type >= 0 && obj->type < 12)
    {
      k = move_cam(rpt, rpt->vpt, rpt->cpt, obj);
      if (k > ZERO && (k < *kmin || *kmin == -1))
	{
	  *kmin = k;
	  rpt->obj_num = i;
	}
      ++i;
      obj = &(rpt->obj[i]);
    }
}

void		get_obj_color(t_rt *rpt, t_obj *obj, double k, t_lco *lpt)
{
  double       	inter[3];

  get_impact(inter, rpt->cpt->pos, k, rpt->vpt->vec);
  if (obj->checker != 0)
    checkerboard_color(inter, obj->color, obj->checker);
  else if (obj->perlin[0] != -1)
    perlin(inter, obj->color, obj->perlin);
  get_color_texture(obj, lpt, k, rpt);
}

unsigned int	modifie_p_color(t_rt *rpt, double k, char opt)
{
  static int	pass = 0;
  unsigned int	color;
  double	distance;
  t_lco		lpt;
  t_obj		*obj;

  if (pass == 10 && opt > 0)
    return (0xFFFFFF);
  pass = (opt > 0) ? pass + 1 : 0;
  distance = 200 * FOG_DIST;
  obj = &rpt->obj[rpt->obj_num];
  get_obj_color(rpt, obj, k, &lpt);
  color = get_light(rpt, k, obj, &lpt);
  distance = rpt->obj[rpt->obj_num].dist;
  if (opt != 2)
    color = reflection(rpt, &lpt, color, k);
  if (opt != 1)
    color = transparency(rpt, &lpt, color, k);
  color = apply_fog(color, rpt->opt->fog, distance);
  return (color);
}

unsigned int	get_pixel_color(t_rt *rpt)
{
  double	k;
  unsigned int	color;

  color = 0x000000;
  calc_inter(rpt, &k);
  if (k != -1 && rpt->light[0].on == 1)
    {
      color = recomp_color(rpt->obj[rpt->obj_num].color);
      color = modifie_p_color(rpt, k, 0);
    }
  color = filter_color(color, rpt->opt);
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
  /* exit(0); */
  detect_edge(rpt, ppt);
  apply_supersampling(rpt, ppt, &spt);
}
