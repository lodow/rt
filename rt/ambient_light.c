/*
** ambient_light.c for ambient_light.c in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun Apr  7 19:07:11 2013 luc sinet
** Last update Sat Apr 13 14:47:38 2013 luc sinet
*/

#include "include/main.h"
#include "include/change_color.h"
#include "include/light.h"

void		*apply_ambient(t_lig *light, unsigned char *color,
			      double *max_cos)
{
  int		i;
  double	cosa;

  i = 0;
  cosa = 0.0;
  *max_cos = 0.0;
  while (light[i].on == 1)
    {
      if (light[i].ambient == 1)
	{
	  cosa = light[i].intensity / 1.7;
	  apply_light_color(color, light[i].lcolor, cosa);
	  *max_cos = MAX(*max_cos, cosa);
	}
      ++i;
    }
  return (color);
}

double		get_light_color(t_lig *light, double *obj_pos,
				  t_lco *lpt, t_vec *vpt)
{
  t_lig		tmp_light;
  double	cosa;

  tmp_light = move_light(light->pos, light->intensity,
			 light->lcolor, obj_pos);
  if ((cosa = get_light_vector(vpt, lpt, tmp_light.pos)) > ZERO);
    /* cosa = apply_distance(lpt, &tmp_light, cosa); */
  apply_light_color(lpt->c_color, light->lcolor, cosa);
  return (MAX(lpt->mx_cos, cosa));
}
