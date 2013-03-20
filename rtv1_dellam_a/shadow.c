/*
** shadow.c for shadow in /home/adrien/Projet/Igraph/RT_V1/Test
** 
** Made by Adrien
** Login   <adrien@adrien>
** 
** Started on  Fri Mar  8 10:32:26 2013 Adrien
** Last update Sat Mar 16 22:49:29 2013 Adrien
*/

#include "include.h"

int		calc_color(t_rt *rt, t_obj *obj, float k)
{
  t_coord	pos;
  t_coord	vec;
  int		i;
  int		j;

  i = 0;
  j = 0;
  calcpt(&pos, k, rt);
  while (i < rt->lightlengh)
    {
      vec.x = rt->light[i].x - pos.x;
      vec.y = rt->light[i].y - pos.y;
      vec.z = rt->light[i].z - pos.z;
      if ((calc_shadow(rt, &pos, &vec)) == 0)
	j++;
      i++;
    }
  if (j == rt->lightlengh && j > 0)
    return (0);
  return (light(rt, obj, k));
}

t_coord	*save_cam(t_rt *rt, t_coord *cam, t_coord *pos, t_coord *vec)
{
  if ((cam = malloc(sizeof(t_coord) * 2)) == NULL)
    exit(0);
  cam[0].x = rt->eye.x;
  cam[0].y = rt->eye.y;
  cam[0].z = rt->eye.z;
  cam[1].x = rt->droite.x;
  cam[1].y = rt->droite.y;
  cam[1].z = rt->droite.z;
  rt->eye.x = pos->x;
  rt->eye.y = pos->y;
  rt->eye.z = pos->z;
  rt->droite.x = vec->x;
  rt->droite.y = vec->y;
  rt->droite.z = vec->z;
  return (cam);
}

void	restore_cam(t_rt *rt, t_coord *cam)
{
  rt->eye.x = cam[0].x;
  rt->eye.y = cam[0].y;
  rt->eye.z = cam[0].z;
  rt->droite.x = cam[1].x;
  rt->droite.y = cam[1].y;
  rt->droite.z = cam[1].z;
  free(cam);
}

int		calc_shadow(t_rt *rt, t_coord *pos, t_coord *vec)
{
  int		i;
  float		l;
  t_coord	*cam;
  float		tmp;

  i = 0;
  tmp = 0;
  l = -1;
  cam = save_cam(rt, cam, pos, vec);
  while (i < rt->objlengh)
    {
      tmp = findk(rt, &(rt->obj[i]));
      if ((tmp < l && l > 0 && tmp > 0) || (l < 0 && tmp > 0))
	l = tmp;
      i++;
    }
  restore_cam(rt, cam);
  if (l < 1 && l > 0.000001)
    return (0);
  else
    return (-1);
}

