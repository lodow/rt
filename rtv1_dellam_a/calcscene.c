/*
** calcscene.c for calcscene in /home/dellam_a/Projet/Igraph/RT_V1
**
** Made by Adrien dellamaggiora
** Login   <dellam_a@epitech.eu>
**
** Started on  Tue Feb  5 12:41:37 2013 Adrien dellamaggiora
** Last update Fri Mar 15 19:00:07 2013 Adrien
*/

#include "include.h"

void	calclpixel(t_coord *pixel, int x, int y)
{
  pixel->x = D;
  pixel->y = (SIZE_X / 2) - (float)x;
  pixel->z = (SIZE_Y / 2) - (float)y;
}

float	findk(t_rt *rt, t_obj *obj)
{
  float	(*func[6])(t_rt *, t_obj *);

  func[0] = &sphere;
  func[1] = &plan;
  func[2] = &cylindre;
  func[3] = &cone;
  func[4] = &paraboloide;
  func[5] = &hyperboloide;
  return (func[obj->type - 1](rt, obj));
}

void	inter(t_rt *rt, t_coord *pos)
{
  int	i;
  int	nbobj;
  float	l;
  float	tmp;

  i = 0;
  tmp = 0;
  l = -1;
  nbobj = -1;
  while (i < rt->objlengh)
    {
      tmp = findk(rt, &(rt->obj[i]));
      if ((tmp < l && l > 0 && tmp > 0) || (l < 0 && tmp > 0))
	{
	  l = tmp;
	  nbobj = i;
	}
      i++;
    }
  if (nbobj != -1 && l > 0)
    mlx_my_pixel_put(rt->init, *pos, calc_color(rt, &rt->obj[nbobj], l));
  else
    mlx_my_pixel_put(rt->init, *pos, 0);
}

void		calcscene(t_rt *rt)
{
  t_coord	pixel;
  t_coord	pos;

  pos.x = 0;
  pos.y = 0;
  while (pos.x < SIZE_X)
    {
      calclpixel(&pixel, pos.x, pos.y);
      eq_droite(rt, &pixel);
      inter(rt, &pos);
      pos.x++;
      if (pos.x == SIZE_X && pos.y < SIZE_Y)
	{
	  pos.x = 0;
	  pos.y++;
	}
    }
  mlx_put_image_to_window((rt->init)->in, (rt->init)->win,
			  (rt->init)->img, 0, 0);
}
