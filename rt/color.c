/*
** color.c for color in /home/adrien/Projet/rt/rt
**
** Made by Adrien Della Maggiora
** Login   <adrien@mint>
**
** Started on  Mon May 13 10:15:38 2013 Adrien Della Maggiora
** Last update Mon May 13 18:37:17 2013 Adrien Della Maggiora
*/

#include <math.h>
#include "main.h"
#include "light.h"
#include "bmp_loader.h"
#include "change_color.h"

void		texture_color(t_obj *obj, double u, double v)
{
  double	color;

  printf("%f, %f\n", u, v);
  if (v < ZERO)
    v = (-v);
  if (u < ZERO)
    u = (-u);
  printf("%f\n", fmod(u, 3.0));
  if (v > obj->texture->height)
    v = v - ((int)((int)v / obj->texture->height) * obj->texture->height);
  if (u > obj->texture->widht)
    u = u - ((int)((int)u / obj->texture->widht) * obj->texture->widht);
  color = u + v * obj->texture->widht;
  obj->color[0] = obj->texture->texture[(int)(color - fmod(color, 3.0))];
  obj->color[1] = obj->texture->texture[(int)(color + 1 - fmod(color, 3.0))];
  obj->color[2] = obj->texture->texture[(int)(color + 2 - fmod(color, 3.0))];
  printf("Color = %X\n\n", recomp_color(obj->color));
}

/* unsigned int	texture_sphere(t_obj *obj, t_lco *lpt, double k, t_rt *rpt) */
/* { */
/* } */

void	texture_plan(t_obj *obj, t_lco *lpt, double k, t_rt *rpt)
{
  double	vec[3];
  double	nvec[3];
  double	u;
  double	v;

  get_inter_normal(rpt, rpt->vpt, k, lpt);
  nvec[0] = lpt->nvec[1];
  nvec[1] = lpt->nvec[2];
  nvec[2] = -lpt->nvec[0];
  unitaire(lpt->nvec);
 unitaire(nvec);
  vec[0] = nvec[1] * lpt->nvec[2] - nvec[2] * lpt->nvec[1];
  vec[1] = nvec[2] * lpt->nvec[0] - nvec[0] * lpt->nvec[2];
  vec[2] = nvec[0] * lpt->nvec[1] - nvec[1] * lpt->nvec[0];
  u = scale(lpt->obj_coor, nvec);
  v = scale(lpt->obj_coor, vec);
  texture_color(obj, u, v);
}

void	get_color_texture(t_obj *obj, t_lco *lpt, double k, t_rt *rpt)
{
  if (obj->texture == NULL)
    return ;
  if (obj->type == 1)
    texture_plan(obj, lpt, k, rpt);
}
