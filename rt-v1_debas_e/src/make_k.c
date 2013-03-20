/*
** make_k.c for rtv1 in /home/debas_e//Desktop/projet/rt-v1
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Sun Mar 17 16:19:52 2013 etienne debas
** Last update Sun Mar 17 18:41:43 2013 etienne debas
*/

#include "../rtv1.h"

double		make_k_sphere(t_vector *vector, t_cam *cam, t_object obj)
{
  double	delta;
  double	a;
  double	b;
  double	c;
  double	k;

  a = pow(vector->vx, 2)
    + pow(vector->vy, 2)
    + pow(vector->vz, 2);
  b = 2 * (((vector->vx) * cam->xcam)
	   + ((vector->vy) * cam->ycam)
	   + ((vector->vz) * cam->zcam));
  c = pow(cam->xcam, 2) + pow(cam->ycam, 2)
    + pow(cam->zcam, 2) - pow(obj.rayon, 2);
  delta = pow(b, 2) - (4 * a * c);
  k = make_k(a, b, c , delta);
  return (k);
}

double		make_k_cylindre(t_vector *vector, t_cam *cam, t_object obj)
{
  double	delta;
  double	a;
  double	b;
  double	c;
  double	k;

  a = pow(vector->vx, 2) + pow(vector->vy, 2);
  b = 2 * (cam->xcam * (vector->vx)
	   + cam->ycam * (vector->vy));
  c = pow(cam->xcam, 2) + pow(cam->ycam, 2) - pow(obj.rayon, 2);
  delta = pow(b, 2) - (4 * a * c);
  k = make_k(a, b, c , delta);
  return (k);
}

double		make_k_cone(t_vector *vector, t_cam *cam, t_object obj)
{
  double	delta;
  double	a;
  double	b;
  double	c;
  double	k;
  double	angle;

  angle = obj.rayon /  180.0 * M_PI;
  a = (pow(vector->vx, 2) * pow(tan(angle), 2)
       + (pow(vector->vy, 2) * pow(tan(angle), 2))
       - pow(vector->vz, 2));
  b = (2 * cam->xcam * (vector->vx) * pow(tan(angle), 2)
       + 2 * cam->ycam * (vector->vy) * pow(tan(angle), 2)
       - 2 * cam->zcam * (vector->vz));
  c = (pow(cam->xcam, 2) * pow(tan(angle), 2)
       + pow(cam->ycam, 2) * pow(tan(angle), 2)
       - pow(cam->zcam, 2));
  delta = pow(b, 2) - (4 * a * c);
  k = make_k(a, b, c , delta);
  return (k);
}

double		make_k_plan(t_vector *vector, t_cam *cam, t_object obj)
{
  double	k;

  if (vector->vx != (double)0)
    k = -(cam->zcam) / (vector->vz);
  else
    k = -1;
  return (k);
}
