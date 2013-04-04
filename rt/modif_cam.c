/*
** modif_cam.c for modif_cam in /tmp/rt/rt
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Thu Mar 21 23:31:20 2013 etienne debas
** Last update Thu Apr  4 17:03:13 2013 Adrien Della Maggiora
*/

#include "main.h"
#include "light.h"

t_cam		modif_cam(t_cam *cam, t_obj obj)
{
  t_cam		cam_tmp;

  cam_tmp.cx = cam->cx - obj.pos[0];
  cam_tmp.cy = cam->cy - obj.pos[1];
  cam_tmp.cz = cam->cz - obj.pos[2];
  return (cam_tmp);
}

t_vec		rotate_vec(t_vec *vec, t_obj obj)
{
  t_vec		vec_tmp;

  vec_tmp.vx = vec->vx;
  vec_tmp.vy = vec->vy;
  vec_tmp.vz = vec->vz;
  rotate_x(&vec_tmp.vz, &vec_tmp.vy, obj.ocos[0], obj.osin[0]);
  rotate_y(&vec_tmp.vz, &vec_tmp.vx, obj.ocos[1], obj.osin[1]);
  rotate_z(&vec_tmp.vx, &vec_tmp.vy, obj.ocos[2], obj.osin[2]);
  return (vec_tmp);
}

void		rotate_cam(t_cam *cam, t_obj obj)
{
  rotate_x(&cam->cz, &cam->cy, obj.ocos[0], obj.osin[0]);
  rotate_y(&cam->cz, &cam->cx, obj.ocos[1], obj.osin[1]);
  rotate_z(&cam->cx, &cam->cy, obj.ocos[2], obj.osin[2]);
}

void	rotate_veccam(t_vec *vec, double ccos[3], double csin[3])
{
  rotate_x(&vec->vz, &vec->vy, ccos[0], csin[0]);
  rotate_y(&vec->vz, &vec->vx, ccos[1], csin[1]);
  rotate_z(&vec->vx, &vec->vy, ccos[2], csin[2]);
}
