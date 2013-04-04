/*
** render.c for render in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Feb 25 18:24:34 2013 luc sinet
** Last update Thu Apr  4 16:43:31 2013 Adrien Della Maggiora
*/

#include <math.h>
#include "main.h"
#include "inter.h"
#include "lightning.h"
#include "aliasing.h"

void	get_addr(t_rt *rpt)
{
  rpt->eptr[0] = &sphere;
  rpt->eptr[1] = &plan;
  rpt->eptr[2] = &cone;
  rpt->eptr[3] = &cylinder;
}

int		check_inter(t_rt *rpt, t_elem *tab, double *kmin, int *color)
{
  double	k;
  int		i;
  int		save;

  i = 0;
  save = 0;
  get_addr(rpt);
  *kmin = -IVAL;
  *color = 0x000000;
  while (tab[i].type != -1)
    {
      k = move_cam(rpt, &tab[i], tab[i].type);
      if (k >= ZERO && k < *kmin)
	{
	  save = tab[i].type;
	  rpt->lpt->obj = i;
	  *kmin = k;
	  *color = tab[i].color;
	}
      i++;
    }
  return (save);
}

void		new_coor(t_vec *vpt, t_cam *cpt, int x, int y)
{
  vpt->nx = 1200;
  vpt->ny = WINX / 2.0 - x;
  vpt->nz = WINY / 2.0 - y;
  cpt->cx = -400;
  cpt->cy = 0.0;
  cpt->cz = 100.0;
  vpt->vx = vpt->nx - cpt->cx;
  vpt->vy = vpt->ny - cpt->cy;
  vpt->vz = vpt->nz - cpt->cz;
}

int		add_modif(t_rt *rpt, int x, int y)
{
  int		color;
  int		type;
  double	k;

  new_coor(rpt->vpt, rpt->cpt, x , y);
  type = check_inter(rpt, rpt->tab, &k, &color);
  if (k != -IVAL && rpt->ltab[0].on == 1)
    {
      color = get_light(rpt, k, type, color);
      color = shadow(rpt, &rpt->ltab[0], color);
    }
  return (color);
}

int		start_render(t_rt *rpt, t_par *ppt)
{
  t_lco		lpt;
  int		x;
  int		y;

  y = 0;
  rpt->lpt = &lpt;
  while (y < WINY)
    {
      x = 0;
      while (x < WINX)
	{
	  my_pixel_put_to_image(x, y, ppt, add_modif(rpt, x, y));
	  ++x;
	}
      print_i(ppt);
      ++y;
    }
  ppt->data = mlx_get_data_addr
    (ppt->img_ptr, &ppt->bpp, &ppt->sizeline, &ppt->endian);
  aliasing(ppt);
  return (0);
}
