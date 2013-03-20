/*
** calc_inter.c for inter in /home/sinet_l//rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Mar 20 16:55:47 2013 luc sinet
** Last update Wed Mar 20 23:29:04 2013 luc sinet
*/

#include "main.h"
#include "inter.h"

void	assign_function(t_rt *rpt)
{
  rpt->eptr[0] = &sphere;
  rpt->eptr[1] = &plan;
  rpt->eptr[2] = &cone;
  rpt->eptr[3] = &cylinder;
}

void		calc_inter(t_rt *rpt, double *kmin, unsigned int *color)
{
  double	k;
  int		i;

  i = 0;
  *kmin = -1;
  *color = 0x000000;
  while (rpt->obj[i].type != -1)
    {
      k = move_cam(rpt, rpt->vpt, i);
      if (k >= ZERO && (k < *kmin || *kmin == -1))
	{
	  *kmin = k;
	  *color = rpt->obj[i].color;
	  rpt->obj_num = i;
	}
      ++i;
    }
}

void		new_coor(t_vec *vpt, t_cam *cpt, int x, int y)
{
  cpt->cx = -400;
  cpt->cy = 0.0;
  cpt->cz = 100.0;
  vpt->vx = DIST - cpt->cx;
  vpt->vy = (WINX / 2.0 - x) - cpt->cy;
  vpt->vz = (WINY / 2.0 - y) - cpt->cz;
}

int		get_color(t_rt *rpt, int x, int y)
{
  unsigned int	color;
  double	k;

  calc_inter(rpt, &k, &color);
  if (k != -1 && rpt->light[0].on == 1)
    {
      /* color = get_light(rpt, k, type, color); */
      /* color = shadow(rpt, &rpt->light[0], color); */
    }
  return (color);
}

void		calc_pixel(t_rt *rpt, t_par *ppt)
{
  int		x;
  int		y;
  unsigned int	color;

  y = 0;
  assign_function(rpt);
  while (y < WINY)
    {
      x = 0;
      while (x < WINX)
	{
	  new_coor(rpt->vpt, rpt->cpt, x , y);
	  if ((color = get_color(rpt, x, y)) != 0x000000)
	    my_pixel_put_to_image(x, y, ppt, color);
	  ++x;
	}
      ++y;
    }
}
