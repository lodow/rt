/*
** color.c for color in /home/adrien/Projet/rt/rt
**
** Made by Adrien Della Maggiora
** Login   <adrien@mint>
**
** Started on  Mon May 13 10:15:38 2013 Adrien Della Maggiora
** Last update Mon May 13 15:00:28 2013 luc sinet
*/

#include "main.h"
#include "light.h"
#include "bmp_loader.h"
#include "change_color.h"

unsigned int	texture_color(t_bmp *text, double u, double v)
{
  unsigned char	color[3];

  if (v < ZERO)
    v = (-v);
  if (u < ZERO)
    u = (-u);
  if (v > (double)text->height)
    v = v - (v / text->height) * text->height;
  if (u > (double)text->widht)
    u = u - (u / text->widht) * text->widht;
  printf("%f, %f\n", u, v);
  color[2] = text->texture[(int)(u + v * (double)text->widht)];
  color[1] = text->texture[(int)((u + 1) + v * (double)text->widht)];
  color[0] = text->texture[(int)((u + 2) + v * (double)text->widht)];
  return (recomp_color(color));
}

/* unsigned int	texture_sphere(t_obj *obj, t_lco *lpt, double k, t_rt *rpt) */
/* { */
/* } */

unsigned int	texture_plan(t_obj *obj, t_lco *lpt, double k, t_rt *rpt)
{
  double	vec[3];
  double	nvec[3];
  double	u;
  double	v;

  get_inter_normal(rpt, rpt->vpt, k, lpt);
  nvec[0] = lpt->nvec[1];
  nvec[1] = lpt->nvec[2];
  nvec[2] = -lpt->nvec[0];
  vec[0] = nvec[1] * lpt->nvec[2] - nvec[2] * lpt->nvec[1];
  vec[1] = nvec[2] * lpt->nvec[0] - nvec[0] * lpt->nvec[2];
  vec[2] = nvec[0] * lpt->nvec[1] - nvec[1] * lpt->nvec[0];
  u = scale(rpt->cpt->pos, nvec);
  v = scale(rpt->cpt->pos, vec);
  return (texture_color(obj->texture, u, v));
}

unsigned int	get_color_texture(t_obj *obj, t_lco *lpt, double k, t_rt *rpt)
{
  if (obj->texture == NULL)
    return (recomp_color(obj->color));
  if (obj->type == 1)
    return (texture_plan(obj, lpt, k, rpt));
  return (0x0);
}
