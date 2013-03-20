/*
** get_normal.c for rtv1 in /home/debas_e//Desktop/save_rtv1
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Fri Mar 15 15:17:20 2013 etienne debas
** Last update Sun Mar 17 17:36:21 2013 etienne debas
*/

#include "../rtv1.h"

t_cam		get_normal(t_object obj, t_cam cam_tmp, t_vector vector_tmp)
{
  t_cam		normal;

  if (obj.type == SPHERE)
    normal = get_normal_sphere(&cam_tmp, obj, &vector_tmp);
  else if (obj.type == PLAN)
    normal = get_normal_plan(&cam_tmp, obj, &vector_tmp);
  else  if (obj.type == CYLINDRE)
    normal = get_normal_cylindre(&cam_tmp, obj, &vector_tmp);
  else  if (obj.type == CONE)
    normal = get_normal_cone(&cam_tmp, obj, &vector_tmp);
  return (normal);
}

t_cam		get_normal_sphere(t_cam *cam, t_object obj, t_vector *vector)
{
  t_cam		normal;

  normal.xcam = (cam->xcam + obj.k * (vector->vx));
  normal.ycam = (cam->ycam + obj.k * (vector->vy));
  normal.zcam = (cam->zcam + obj.k * (vector->vz));
  return (normal);
}

t_cam		get_normal_plan(t_cam *cam, t_object obj, t_vector *vector)
{
  t_cam		normal;

  normal.xcam = 0;
  normal.ycam = 0;
  if (LIGHTZ < obj.z)
    normal.zcam = -100;
  else
    normal.zcam = 100;
  return (normal);
}

t_cam		get_normal_cylindre(t_cam *cam, t_object obj, t_vector *vector)
{
  t_cam		normal;

  normal.xcam = cam->xcam + obj.k * (vector->vx);
  normal.ycam = cam->ycam + obj.k * (vector->vy);
  normal.zcam = 0;
  return (normal);
}

t_cam		get_normal_cone(t_cam *cam, t_object obj, t_vector *vector)
{
  t_cam		normal;

  normal.xcam = cam->xcam + obj.k * (vector->vx);
  normal.ycam = cam->ycam + obj.k * (vector->vy);
  normal.zcam = -0.6 * (cam->zcam + obj.k * (vector->vz));
  return (normal);
}
