/*
** render.c for render in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Feb 25 18:24:34 2013 luc sinet
** Last update Wed Mar 13 23:50:41 2013 luc sinet
*/

#include <math.h>
#include "main.h"
#include "inter.h"

void		  color_pixel(int x, int y, t_par *ppt, int color)
{
  my_pixel_put_to_image(x, y, ppt, color);
}

int		check_inter(t_rt *rpt, t_elem *tab)
{
  double	(*eptr[4])(t_cam *cpt, t_vec *vpt, t_elem *ept);
  double	k;
  double	kmin;
  int		color;
  int		i;
  int		x;

  i = 0;
  kmin = -IVAL;
  color = 0x000000;
  eptr[0] = &sphere;
  eptr[1] = &plan;
  eptr[2] = &cone;
  eptr[3] = &cylinder;
  while (tab[i].type != -1)
    {
      k = eptr[tab[i].type](rpt->cpt, rpt->vpt, &tab[i]);
      if (k >= ZERO && k < kmin)
	{
	  kmin = k;
	  color = tab[i].color;
	}
      i++;
    }
  return (color);
}

void		new_coor(t_vec *vpt, t_cam *cpt, int x, int y)
{
  vpt->nx = DIST;
  vpt->ny = WINX / 2.0 - x;
  vpt->nz = WINY / 2.0 - y;
  vpt->vx = vpt->nx - cpt->cx;
  vpt->vy = vpt->ny - cpt->cy;
  vpt->vz = vpt->nz - cpt->cz;
}

int		start_render(t_rt *rpt, t_par *ppt)
{
  int		x;
  int		y;
  int		color;

  y = 0;
  while (y < WINY)
    {
      x = 0;
      while (x < WINX)
	{
	  new_coor(rpt->vpt, rpt->cpt, x , y);
	  color = check_inter(rpt, rpt->tab);
	  color_pixel(x, y, ppt, color);
	  x++;
	}
      y++;
    }
  return (0);
}
