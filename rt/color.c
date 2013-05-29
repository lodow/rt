/*
** color.c for color in /home/adrien/Projet/rt/rt
**
** Made by Adrien Della Maggiora
** Login   <adrien@mint>
**
** Started on  Mon May 13 10:15:38 2013 Adrien Della Maggiora
** Last update Wed May 29 16:47:00 2013 etienne debas
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

  x = (u * obj->texture->widht);
  y = (v * obj->texture->height);
  color = ((y * obj->texture->widht + x) * 3) % (obj->texture->widht * obj->texture->height);
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
  double	vec[3];
  double	dist;
  double	nvec[3];
  double	u;
  double	v;

  get_inter_normal(rpt, rpt->vpt, k, lpt);
  /* nvec[0] = lpt->nvec[1]; */
  /* nvec[1] = lpt->nvec[2]; */
  /* nvec[2] = -lpt->nvec[0]; */
  /* vec[0] = nvec[1] * lpt->nvec[2] - nvec[2] * lpt->nvec[1]; */
  /* vec[1] = nvec[2] * lpt->nvec[0] - nvec[0] * lpt->nvec[2]; */
  /* vec[2] = nvec[0] * lpt->nvec[1] - nvec[1] * lpt->nvec[0]; */
  /* u = scale(lpt->obj_coor, nvec); */
  /* v = scale(lpt->obj_coor, vec); */
  unitaire(lpt->obj_coor);
  texture_color(obj, lpt->obj_coor[1], lpt->obj_coor[0]);
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
