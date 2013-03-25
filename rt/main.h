/*
** main.h for main in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Feb 25 11:18:51 2013 luc sinet
** Last update Mon Mar 25 20:00:26 2013 luc sinet
*/

#ifndef MAIN_H_
# define MAIN_H_

#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include "pp_image.h"
#include "str.h"
#include "nb.h"

# define ZERO 0.000001
# define IVAL -1000000
# define RANG(ang) (ang < 0) ? (ang * -1) : ang
# define RAD(ang) (ang * 3.1415926 / 180)
# define DIST 1000
# define K_ESC 65307

typedef struct	s_cam
{
  double	cx;
  double	cy;
  double	cz;
  double	tx;
  double	ty;
  double	tz;
}		t_cam;

typedef struct	s_obj
{
  int		type;
  double	pos[3];
  double	angle[4];
  unsigned int	color;
  double	rayon;
  double	bright;
  double	ocos[4];
  double	osin[4];
}		t_obj;

typedef struct	s_lig
{
  int		on;
  double	pos[3];
  double	intensity;
  unsigned int	lcolor;
}		t_lig;

typedef struct	s_vec
{
  double	nx;
  double	ny;
  double	nz;
  double	vx;
  double	vy;
  double	vz;
}		t_vec;

typedef struct	s_rt
{
  int		obj_num;
  t_vec		*vpt;
  t_cam		*cpt;
  t_obj		*obj;
  t_lig		*light;
  double	(*eptr[4])(double *cam, double *vec, t_obj *opt);
}		t_rt;

void		calc_inter(t_rt *rpt, double *kmin, unsigned int *color);
void		calc_pixel(t_rt *rpt, t_cam *cpt, t_vec *vpt, t_par *ppt);
int		merror(char *msg, int ret);
double		move_cam(t_rt *rpt, t_vec *vpt, t_cam *cpt, int nb);
void		init_cos(t_obj *tab);
void		rotate_x(double *z, double *y, double cosin, double sinus);
void		rotate_y(double *z, double *x, double cosin, double sinus);
void		rotate_z(double *x, double *y, double cosin, double sinus);
unsigned int	get_light(t_rt *rpt, double k, unsigned int color);
t_cam		modif_cam(t_cam *cam, t_obj obj);
t_vec		rotate_vec(t_vec *vec, t_obj obj);
t_cam		rotate_cam(t_cam *cam, t_obj obj);
double		*deref_cam(t_cam *cpt, double *cam);
double		*deref_vec(t_vec *vpt, double *vec);

#endif
