/*
** draw.c for rtv1 in /home/debas_e//Desktop/projet/rt-v1
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Thu Feb 28 23:53:13 2013 etienne debas
** Last update Sun Mar 17 17:34:25 2013 etienne debas
*/

#include "../rtv1.h"

void		draw_px(t_scene *scene, t_vector *vector, int x, int y)
{
  double	k;
  int		i;
  int		nearest;
  int		color_brightness;
  t_object	obj_nearest;

  obj_nearest = get_nearest_obj(scene->obj);
  if (obj_nearest.k > 0.01)
    {
      color_brightness = determinate_color(scene, vector, obj_nearest);
      if (color_brightness != -1)
	my_pixel_put_to_image(x, y, scene->win, color_brightness);
      else
      	my_pixel_put_to_image(x, y, scene->win, 0x0);
    }
  else
    my_pixel_put_to_image(x, y, scene->win, 0x0);
}

int		determinate_color(t_scene *scene, t_vector *vector, t_object obj)
{
  double	cosa;
  t_cam		normal;
  t_vector	light;
  t_cam		impact;
  t_cam		cam_tmp;
  t_vector	vector_tmp;

  cam_tmp = modif_cam(scene->cam, obj);
  cam_tmp = rotate_cam(&cam_tmp, obj);
  vector_tmp = rotate_vector(vector, obj);
  normal = get_normal(obj, cam_tmp, vector_tmp);
  impact = get_impact(scene->cam, obj, vector);
  light = get_vector_light(scene->cam, obj, vector);
  cosa = get_cos(normal, light);
  if (get_ombre(&light, &impact, scene, obj) != 0)
    return (make_color(obj.color * (1 - obj.brightness)
		       + 0xFFFF00 * obj.brightness, cosa * 0.25));
  else if (cosa > 0.0000001 && cosa < 1.0)
    return (make_color(obj.color * (1 - obj.brightness)
		       + 0xFFFF00 * obj.brightness, cosa));
  else
    return (-1);
}

int		get_ombre(t_vector *light, t_cam *impact,
			  t_scene *scene, t_object obj_cur)
{
  t_object	obj;

  fill_k_obj(light, impact, scene->obj);
  obj = get_nearest_obj(scene->obj);
  if ((obj.k > 0.0) && (obj.k <= (double)1.000) && (obj.type != obj_cur.type))
    return (-1);
  else
    return (0);
}

int		make_color(int color, float cosa)
{
  int		r;
  int		g;
  int		b;
  int		color_tmp;

  r = (color & 0xFF) * cosa;
  g = ((color >> 8) & 0xFF) * cosa;
  b = ((color >> 16) & 0xFF) * cosa;
  color_tmp = 0;
  color_tmp = color_tmp | b;
  color_tmp <<= 8;
  color_tmp = color_tmp | g;
  color_tmp <<= 8;
  color_tmp = color_tmp | r;
  return (color_tmp);
}
