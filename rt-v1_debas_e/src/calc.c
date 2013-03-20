/*
** calc.c for rtv1 in /home/debas_e//Desktop/projet/rt-v1
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Sun Mar 17 16:17:10 2013 etienne debas
** Last update Sun Mar 17 16:25:22 2013 etienne debas
*/

#include "../rtv1.h"

t_cam		modif_cam(t_cam *cam, t_object obj)
{
  t_cam		cam_tmp;

  cam_tmp.xcam = cam->xcam - (double)obj.x;
  cam_tmp.ycam = cam->ycam - (double)obj.y;
  cam_tmp.zcam = cam->zcam - (double)obj.z;
  return (cam_tmp);
}

t_vector	get_vector_light(t_cam *cam, t_object obj, t_vector *vector)
{
  t_vector	light;
  int		light_x;
  int		light_y;
  int		light_z;

  light.vx = ((double)LIGHTX - (cam->xcam + obj.k * (vector->vx)));
  light.vy = ((double)LIGHTY - (cam->ycam + obj.k * (vector->vy)));
  light.vz = ((double)LIGHTZ - (cam->zcam + obj.k * (vector->vz)));
  return (light);
}

double		get_cos(t_cam normal, t_vector light)
{
  double	cosa;

  cosa = ((normal.ycam * light.vy + normal.zcam
	   * light.vz + normal.xcam * light.vx) /
	  ((sqrt(pow(normal.ycam, 2) + pow(normal.zcam, 2)
		 + pow(normal.xcam, 2)))
	   * (sqrt(pow(light.vx, 2) + pow(light.vy, 2)
		   + pow(light.vz, 2)))));
  return (cosa);
}

t_cam		get_impact(t_cam *cam, t_object obj, t_vector *vector)
{
  t_cam		impact;

  impact.xcam = (int)(cam->xcam + obj.k * vector->vx);
  impact.ycam = (int)(cam->ycam + obj.k * vector->vy);
  impact.zcam = (int)(cam->zcam + obj.k * vector->vz);
  return (impact);
}
