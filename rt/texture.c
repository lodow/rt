/*
** color.c for color in /home/adrien/Projet/rt/rt
**
** Made by Adrien Della Maggiora
** Login   <adrien@mint>
**
** Started on  Mon May 13 10:15:38 2013 Adrien Della Maggiora
** Last update Thu May 30 21:43:45 2013 etienne debas
*/

#include <math.h>
#include "main.h"
#include "light.h"
#include "bmp_loader.h"
#include "change_color.h"

void		texture_color(t_obj *obj, double u, double v)
{
  int		color;
  int		x;
  int		y;
  int		len;

  len = obj->texture->widht * obj->texture->height;
  x = (u * obj->texture->widht);
  y = (v * obj->texture->height);
  color = ((y * obj->texture->widht + x) * 2) % len;
  color = color - color % 3;
  obj->color[0] = obj->texture->texture[color];
  obj->color[1] = obj->texture->texture[color + 1];
  obj->color[2] = obj->texture->texture[color + 2];
}

void		texture_sphere(t_obj *obj, t_lco *lpt, double k, t_rt *rpt)
{
  double	v;
  double	u;
  int		x;
  int		y;
  int		p;

  get_inter_normal(rpt, rpt->vpt, k, lpt);
  unitaire(lpt->nvec);
  u = 0.5 + atan2(lpt->nvec[0], lpt->nvec[1]) / (2 * M_PI);
  v = 0.5 - 2 * (asin(lpt->nvec[2]) / (2 * M_PI));
  texture_color(obj, u, v);
}

void	texture_plan(t_obj *obj, t_lco *lpt, double k, t_rt *rpt)
{
  double	u;
  double	v;

  get_inter_normal(rpt, rpt->vpt, k, lpt);
  u = lpt->obj_coor[1];
  if (u < ZERO)
    while (u < ZERO)
      u += obj->texture->widht;
  if (u >= obj->texture->widht)
    while (u >= obj->texture->widht)
      u -= obj->texture->widht;
  v = lpt->obj_coor[0];
  if (v < ZERO)
    while (v < ZERO)
      v += obj->texture->height;
  if (v >= obj->texture->height)
    while (v >= obj->texture->height)
      v -= obj->texture->height;
  texture_color(obj, (u + obj->texture->widht / 2) / obj->texture->widht,
		((obj->texture->height - v) + obj->texture->height / 2)
		/ obj->texture->height);
}

void	texture_cylinder(t_obj *obj, t_lco *lpt, double k, t_rt *rpt)
{
  double	u;
  double	v;

  get_inter_normal(rpt, rpt->vpt, k, lpt);
  u = (atan(lpt->obj_coor[2] / lpt->obj_coor[1]) / (2 * M_PI));
}

void	get_color_texture(t_obj *obj, t_lco *lpt, double k, t_rt *rpt)
{
  if (obj->texture == NULL)
    return ;
  if (obj->type == 1)
    texture_plan(obj, lpt, k, rpt);
  else if (obj->type == 0)
    texture_sphere(obj, lpt, k, rpt);
}
