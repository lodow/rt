/*
** main.h for main in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Feb 25 11:18:51 2013 luc sinet
** Last update Sun Apr 14 12:42:00 2013 Adrien Della Maggiora
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
# define ABS(val) ((val) < 0) ? -(val) : val
# define DIST 1000
# define K_ESC 65307

typedef struct	s_samp	t_samp;
typedef struct	s_lco	t_lco;

typedef struct	s_cam
{
  double	cx;
  double	cy;
  double	cz;
  double	ccos[3];
  double	csin[3];
  double	tx;
  double	ty;
  double	tz;
}		t_cam;

typedef struct	s_obj
{
  int		type;
  double	pos[3];
  double	angle[4];
  unsigned char	color[3];
  double	rayon;
  double	bright;
  double	ocos[4];
  double	osin[4];
  double	acos[3];
  double	asin[3];
  double	limit[9];
  double	pert[6];
  double	dist;
  double	reflec;
  double	alpha;
  double	n;
}		t_obj;

typedef struct	s_lig
{
  int		on;
  int		ambient;
  double	pos[3];
  double	intensity;
  unsigned char	lcolor[3];
}		t_lig;

typedef struct	s_opt
{
  int		aa;
  double	fog[2];
}		t_opt;

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
  t_opt		*opt;
  double	(*eptr[4])(double *cam, double *vec, t_obj *opt);
}		t_rt;

void		calc_inter(t_rt *rpt, double *kmin);
void		calc_pixel(t_rt *rpt, t_cam *cpt, t_vec *vpt, t_par *ppt);
int		print_i(t_par *ppt);
int		merror(char *msg, int ret);
double		move_cam(t_rt *rpt, t_vec *vpt, t_cam *cpt, t_obj obj);
void		init_cos(t_obj *tab);
void		rotate_x(double *z, double *y, double cosin, double sinus);
void		rotate_y(double *z, double *x, double cosin, double sinus);
void		rotate_z(double *x, double *y, double cosin, double sinus);
unsigned int	get_light(t_rt *rpt, double k, t_obj *obj, t_lco *lpt);
t_cam		modif_cam(t_cam *cam, t_obj obj);
t_vec		rotate_vec(t_vec *vec, t_obj obj);
void		rotate_cam(t_cam *cam, t_obj obj);
void		rotate_veccam(t_vec *vec, double ccos[3], double csin[3]);
void		new_coor(t_vec *vpt, t_cam *cpt, double x, double y);
double		*deref_cam(t_cam *cpt, double *cam);
double		*deref_vec(t_vec *vpt, double *vec);
double		get_min(double *k, int size);
double		get_max(double *k, int size);
int		solve_second(double *a, double *k);
int		get_color_diff(unsigned int pixel1, unsigned int pixel2);
double		point_distance(double *p1, double *p2);
double		test_limit(double *cam, double *vec, double *k, double *limit);
double		test_side_limit(double *cam, double *vec,
				double *limit, double *k);
double		test_depth_limit(double *cam, double *vec,
				double *limit, double *k);
unsigned int	get_pixel_color(t_rt *rpt);
void		get_inter(double *cam, double *vec, double k, double *inter);
void		detect_edge(t_rt *rpt, t_par *ppt);
void		apply_supersampling(t_rt *rpt, t_par *ppt, t_samp *spt);
void		fill_img_param(int *pos, unsigned int color,
			       t_rt *rpt, t_par *ppt);

#endif
