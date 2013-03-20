/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "include.h"

float	cone(t_cam *cam, float r)
{
  float	res[2];
  float	a;
  float	b;
  float	c;
  float	k;
  float	tg;
  int	nb;


  tg = tan(r * 3.14156 / 180) * tan(r * 3.14156 / 180);
  a = (cam->dir.x * cam->dir.x) + (cam->dir.y * cam->dir.y)
      - ((cam->dir.z * cam->dir.z) / tg);
  b = 2 * (cam->dir.x * cam->pos.x + cam->dir.y * cam->pos.y
           - ((cam->dir.z * cam->pos.z) / tg));
  c = ((cam->pos.x * cam->pos.x) + (cam->pos.y * cam->pos.y)
       - ((cam->pos.z * cam->pos.z) / tg));
  if ((nb = equa_deg2(a, b, c, res)) > 0)
    {
      k = res[0];
      if (nb == 2)
        k = MIN(res[0], res[1]);
      return (k);
    }
  return (0.0);
}

float	cylindre(t_cam *cam, float r)
{
  float	res[2];
  float	a;
  float	b;
  float	c;
  float	k;
  int	nb;

  a = (cam->dir.y * cam->dir.y) + (cam->dir.x * cam->dir.x);
  b = 2 * ((cam->pos.y * cam->dir.y) + (cam->pos.x * cam->dir.x));
  c = (cam->pos.y * cam->pos.y) + (cam->pos.x * cam->pos.x) - (r * r);
  if ((nb = equa_deg2(a, b, c, res)) > 0)
    {
      k = res[0];
      if (nb == 2)
        k = MIN(res[0], res[1]);
      return (k);
    }
  return (0.0);
}

float	sphere(t_cam *cam, float r)
{
  float	res[2];
  float	a;
  float	b;
  float	c;
  float	k;
  int	nb;

  a = (cam->dir.x * cam->dir.x) + (cam->dir.y * cam->dir.y)
      + (cam->dir.z * cam->dir.z);
  b = 2 * ((cam->pos.x * cam->dir.x) + (cam->pos.y * cam->dir.y)
           + (cam->pos.z * cam->dir.z));
  c = (cam->pos.x * cam->pos.x) + (cam->pos.y * cam->pos.y)
      + (cam->pos.z * cam->pos.z) - (r * r);
  if ((nb = equa_deg2(a, b, c, res)) > 0)
    {
      k = res[0];
      if (nb == 2)
        k = MIN(res[0], res[1]);
      return (k);
    }
  return (0.0);
}

float	plan(t_cam *cam, t_vector3d *normale, float dep)
{
  float	k;

  k = -((normale->x * cam->pos.x + normale->y * cam->pos.y + normale->z
         * cam->pos.z + dep) / (normale->x * cam->dir.x + normale->y
                                * cam->dir.y + normale->z * cam->dir.z));
  return (k);
}
