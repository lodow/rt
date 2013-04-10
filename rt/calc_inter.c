/*
** calc_inter.c for inter in /home/sinet_l//rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Mar 20 16:55:47 2013 luc sinet
** Last update Wed Apr 10 02:30:53 2013 luc sinet
*/

#include <math.h>
#include "main.h"
#include "inter.h"
#include "change_color.h"
#include "supersampling.h"

void	assign_function(t_rt *rpt)
{
  rpt->eptr[0] = &sphere;
  rpt->eptr[1] = &plan;
  rpt->eptr[2] = &cone;
  rpt->eptr[3] = &cylinder;
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
	  rpt->old_k = k;
	  rpt->obj_num = i;
	}
      ++i;
    }
}

void		new_coor(t_vec *vpt, t_cam *cpt, double x, double y)
{
  vpt->vx = DIST - cpt->cx;
  vpt->vy = (WINX / 2.0 - x) - cpt->cy;
  vpt->vz = (WINY / 2.0 - y) - cpt->cz;
  rotate_veccam(vpt, cpt->ccos, cpt->csin);
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
      color = get_light(rpt, k, &rpt->obj[rpt->obj_num]);
      /* color = shadow(rpt, &rpt->light[0], color); */
    }
  return (color);
}

void		calc_pixel(t_rt *rpt, t_cam *cpt, t_vec *vpt, t_par *ppt)
{
  t_samp	spt;
  int		x;
  int		y;

  y = 0;
  assign_function(rpt);
  spt.square = sqrt(SSP);
  spt.spacing = 1 / spt.square;
  if ((spt.pixel = malloc(sizeof(unsigned int) * SSP)) == NULL)
    return ;
  while (y < WINY)
    {
      x = 0;
      while (x < WINX)
	{
	  new_coor(vpt, cpt, x, y);
	  my_pixel_put_to_image(x, y, ppt, get_pixel_color(rpt));
	  fill_img_param(x, y, rpt, ppt);
	  ++x;
	}
      ++y;
    }
  detect_edge(rpt, ppt);
  apply_supersampling(rpt, &spt, ppt);
}
