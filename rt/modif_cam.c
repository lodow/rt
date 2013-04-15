/*
** modif_cam.c for modif_cam in /tmp/rt/rt
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Thu Mar 21 23:31:20 2013 etienne debas
** Last update Mon Apr 15 23:09:19 2013 luc sinet
*/

#include "include/main.h"
#include "include/light.h"

t_cam		modif_cam(t_cam *cam, t_obj obj)
{
  t_cam		cam_tmp;

  cam_tmp.pos[0] = cam->pos[0] - obj.pos[0];
  cam_tmp.pos[1] = cam->pos[1] - obj.pos[1];
  cam_tmp.pos[2] = cam->pos[2] - obj.pos[2];
  return (cam_tmp);
}

t_vec		rotate_vec(t_vec *vec, t_obj obj)
{
  t_vec		vec_tmp;

  vec_tmp.vec[0] = vec->vec[0];
  vec_tmp.vec[1] = vec->vec[1];
  vec_tmp.vec[2] = vec->vec[2];
  rotate_x(&vec_tmp.vec[2], &vec_tmp.vec[1], obj.ocos[0], obj.osin[0]);
  rotate_y(&vec_tmp.vec[2], &vec_tmp.vec[0], obj.ocos[1], obj.osin[1]);
  rotate_z(&vec_tmp.vec[0], &vec_tmp.vec[1], obj.ocos[2], obj.osin[2]);
  return (vec_tmp);
}

void		rotate_cam(t_cam *cam, t_obj obj)
{
  rotate_x(&cam->pos[2], &cam->pos[1], obj.ocos[0], obj.osin[0]);
  rotate_y(&cam->pos[2], &cam->pos[0], obj.ocos[1], obj.osin[1]);
  rotate_z(&cam->pos[0], &cam->pos[1], obj.ocos[2], obj.osin[2]);
}

void	rotate_veccam(t_vec *vec, double ccos[3], double csin[3])
{
  rotate_x(&vec->vec[2], &vec->vec[1], ccos[0], csin[0]);
  rotate_y(&vec->vec[2], &vec->vec[0], ccos[1], csin[1]);
  rotate_z(&vec->vec[0], &vec->vec[1], ccos[2], csin[2]);
}
