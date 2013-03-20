/*
** rotate.c for test in /home/debas_e//Desktop/projet/rt-v1
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Thu Feb 28 14:23:23 2013 etienne debas
** Last update Sun Mar 17 16:51:30 2013 etienne debas
*/

#include "../rtv1.h"

void		rotate_x(double *z, double *y, int angle)
{
  double	cosin;
  double	sinus;
  double	nvy;
  double	nvz;

  cosin = cos(angle * M_PI / 180);
  sinus = sin(angle * M_PI / 180);
  nvz = (*y * sinus) + (*z * cosin);
  nvy = (*y * cosin) - (*z * sinus);
  *z = nvz;
  *y = nvy;
}

void		rotate_z(double *x, double *y, int angle)
{
  double	cosin;
  double	sinus;
  double	nvy;
  double	nvx;

  cosin = cos(angle * M_PI / 180);
  sinus = sin(angle * M_PI / 180);
  nvx = (*x * cosin) + (*y * sinus);
  nvy = (*x * -sinus) + (*y * cosin);
  *y = nvy;
  *x = nvx;
}

void		rotate_y(double *z, double *x, int angle)
{
  double	cosin;
  double	sinus;
  double	nvx;
  double	nvz;

  cosin = cos(angle * M_PI / 180);
  sinus = sin(angle * M_PI / 180);
  nvx = (*z * sinus) + (*x * cosin);
  nvz = (*x * (-sinus)) + (*z * cosin);
  *z = nvz;
  *x = nvx;
}

t_vector	rotate_vector(t_vector *vector, t_object obj)
{
  t_vector	vector_tmp;

  vector_tmp.vx = vector->vx;
  vector_tmp.vy = vector->vy;
  vector_tmp.vz = vector->vz;
  if (obj.rot->rx != 0)
    rotate_x(&vector_tmp.vz, &vector_tmp.vy, -obj.rot->rx);
  if (obj.rot->ry != 0)
    rotate_y(&vector_tmp.vz, &vector_tmp.vx, -obj.rot->ry);
  if (obj.rot->rz != 0)
    rotate_z(&vector_tmp.vx, &vector_tmp.vy, -obj.rot->rz);
  return (vector_tmp);
}

t_cam		rotate_cam(t_cam *cam, t_object obj)
{
  t_cam		cam_tmp;

  cam_tmp.xcam = cam->xcam;
  cam_tmp.ycam = cam->ycam;
  cam_tmp.zcam = cam->zcam;
  if (obj.rot->rx != 0)
    rotate_x(&cam_tmp.zcam, &cam_tmp.ycam, -obj.rot->rx);
  if (obj.rot->ry != 0)
    rotate_y(&cam_tmp.zcam, &cam_tmp.xcam, -obj.rot->ry);
  if (obj.rot->rz != 0)
    rotate_z(&cam_tmp.xcam, &cam_tmp.ycam, -obj.rot->rz);
  return (cam_tmp);
}

