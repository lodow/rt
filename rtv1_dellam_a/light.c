/*
** light.c for rtv1 in /home/dellam_a//Projet/Igraph/RT_V1
**
** Made by adrien dellamaggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Thu Feb 14 09:41:36 2013 adrien dellamaggiora
** Last update Fri Mar 15 18:55:56 2013 Adrien
*/

#include "include.h"

void	calcpt(t_coord *pos, float k, t_rt *rt)
{
  pos->x = rt->droite.x * k + rt->eye.x;
  pos->y = rt->droite.y * k + rt->eye.y;
  pos->z = rt->droite.z * k + rt->eye.z;
}

int	transcolor(int c, float cosa)
{
  int	r;
  int	g;
  int	b;

  if (cosa < 0.000001)
    cosa = 0;
  b = (c & 255) * cosa;
  g = ((c >> 8) & 255) * cosa;
  r = ((c >> 16) & 255) * cosa;
  c = 0;
  c = (c | r) << 8;
  c = (c | g) << 8;
  c = c | b;
  return (c);
}

float	calc_cos(t_coord *nor, t_coord *vecdir)
{
  float	cosa;
  float	norme_n;
  float	norme_v;

  cosa = 0;
  norme_n = sqrt((nor->x * nor->x ) + (nor->y * nor->y) + (nor->z * nor->z));
  norme_v = sqrt((vecdir->x * vecdir->x) + (vecdir->y * vecdir->y)
		 + (vecdir->z * vecdir->z));
  if (norme_v != 0 && norme_n != 0)
    cosa = (((nor->x * vecdir->x) + (nor->y * vecdir->y)
	     + (nor->z * vecdir->z)) / (norme_n * norme_v));
  return (cosa);
}

t_coord		getnormal(t_obj *obj, t_coord *pos)
{
  t_coord	res;
  t_coord	(*func[6])(t_coord , t_coord *, t_obj *);

  func[0] = norsphere;
  func[1] = norplan;
  func[2] = norcylindre;
  func[3] = norcone;
  func[4] = norparaboloide;
  func[5] = norhyperboloide;
  return (func[obj->type - 1](res, pos, obj));
}

int		light(t_rt *rt, t_obj *obj, float k)
{
  t_coord	pos;
  t_coord	vecdir;
  t_coord	nor;
  float		res;
  float		cosa;
  int		i;

  if (rt->lightlengh == 0)
    return (obj->color);
  calcpt(&pos, k, rt);
  i = 0;
  res = 0;
  cosa = 0;
  while (i < rt->lightlengh)
    {
      vecdir.x = rt->light[i].x - pos.x;
      vecdir.y = rt->light[i].y - pos.y;
      vecdir.z = rt->light[i].z - pos.z;
      nor = getnormal(obj, &pos);
      cosa = calc_cos(&nor, &vecdir);
      res = MAX(res, cosa);
      ++i;
    }
  return (transcolor(obj->color, res));
}
