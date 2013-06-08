/*
** main.h for main in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Feb 25 11:18:51 2013 luc sinet
** Last update Sat Jun  8 18:07:30 2013 adrien dellamaggiora
*/

#ifndef MAIN_H_
# define MAIN_H_

#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include "pp_image.h"
#include "str.h"
#include "nb.h"

# define UNUSED __attribute__((unused))

# define ZERO 0.00000001
# define IVAL -1000000
# define RANG(ang) ((ang) < 0) ? -(ang) : ang
# define RAD(ang) (ang * 3.1415926 / 180)
# define ABS(val) (((val) < 0) ? -(val) : (val))
# define DIST 1000
# define K_ESC 65307
# define GMAX(y, x) ((y) < 0 || (x) < 0) ? -1 : ((x) > (y)) ? (x) : (y)
# define K_P 112
# define K_O 111

typedef struct	s_samp	t_samp;
typedef struct	s_lco	t_lco;
typedef struct	s_bmp	t_bmp;

typedef struct	s_cam
{
  double	pos[3];
  double	ccos[3];
  double	csin[3];
  double	ctmp[3];
}		t_cam;

typedef struct	s_angle
{
  double	ocos[4];
  double	osin[4];
  double	acos[3];
  double	asin[3];
}		t_angle;

typedef struct	s_indice
{
  double	indice[4];
  double	perlin[2];
  double	bump;
  int		checker;
  int		rate;
}		t_indice;

typedef struct	s_obj
{
  int		type;
  double	pos[3];
  double	angle[4];
  unsigned char	color[3];
  double	size[2];
  double	bright;
  double	limit[9];
  double	pert[6];
  double	dist;
  double	cst;
  double	v1[3];
  double	v2[3];
  double	normal[4];
  t_bmp		*texture;
  t_indice	*ipt;
  t_angle	*apt;
}		t_obj;

/*
** Indice tab:
** 0 - alpha
** 1 - n
** 2 - reflection
*/

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
  int		filter;
  double	gamma;
  double	contrast;
  int		shadows_type;
}		t_opt;

typedef struct	s_vec
{
  double	nx;
  double	ny;
  double	nz;
  double	vec[3];
}		t_vec;

typedef	struct	s_text
{
  char		**name;
  t_bmp		**text;
}		t_text;

typedef struct	s_rt
{
  int		obj_num;
  t_vec		*vpt;
  t_cam		*cpt;
  t_obj		*obj;
  t_lig		*light;
  t_opt		*opt;
  t_text	*text;
  t_par		*ppt;
  double	(*eptr[13])(double *cam, double *vec, t_obj *opt);
}		t_rt;

void		calc_inter(t_rt *rpt, double *kmin);
unsigned int	modifie_p_color(t_rt *rpt, double k, char opt);
void		assign_function(t_rt *rpt);
void		calc_pixel(t_rt *rpt, t_cam *cpt, t_vec *vpt, t_par *ppt);
int		print_i(t_par *ppt);
int		merror(char *msg, int ret);
void		*merrorptr(char *error, void *val);
double		move_cam(t_rt *rpt, double *rvec, double *cam, t_obj *obj);
void		init_cos(t_obj *tab);
void		rotate_x(double *p, double cosin, double sinus);
void		rotate_y(double *p, double cosin, double sinus);
void		rotate_z(double *p, double cosin, double sinus);
unsigned int	get_light(t_rt *rpt, double k, t_obj *obj, t_lco *lpt);
void		copy_tab(void *tab, void *ctab, int size);
void		modif_cam(double *c_pos, double *o_pos);
void		rotate(double *p, double *cosin, double *sinus, char opt);
void		new_coor(t_vec *vpt, t_cam *cpt, t_par *ppt, double *pos);
double		*deref_cam(t_cam *cpt, double *cam);
double		*deref_vec(t_vec *vpt, double *vec);
double		get_min(double *k, int size);
double		get_max(double *k, int size);
double		solve_second(double *a, double *k);
int		get_color_diff(unsigned int pixel1, unsigned int pixel2);
double		point_distance(double *p1, double *p2);
double		test_limit(double *cam, double *vec, double *k, double *limit);
double		test_side_limit(double *cam, double *vec,
				double *limit, double *k);
double		test_depth_limit(double *cam, double *vec,
				 double *limit, double *k);
unsigned int	get_pixel_color(t_rt *rpt);
void		get_impact(double *imp, double *cam, double k, double *vec);
void		get_inter(double *cam, double *vec, double k, double *inter);
void		detect_edge(t_rt *rpt, t_par *ppt);
void		apply_supersampling(t_rt *rpt, t_par *ppt, t_samp *spt);
void		fill_img_param(double *dpos, unsigned int color,
			       UNUSED t_rt *rpt, t_par *ppt);
void		delta_neg_third(double *k, double delta, double *pq);
void		delta_nul_third(double *k, double *pq);
void		delta_pos_third(double *k, double *pq);
unsigned int	transparency(t_rt *rpt, t_lco *lpt, unsigned int color,
			     double k);
void		my_putbyte(const void *ptr, int fd, int strlen);
void		my_mem_cpy(void *dest, void *src, int size);
void		*adjust_mem_size(void *mem, int size, int nsize, int dfree);
double		get_pow(double nb);
void		my_memset(void *elem, int val, int size);
unsigned int	perlin(double *inter, unsigned char *color_obj,
		       double *carac);
unsigned int	filter_color(unsigned int color, t_opt *opt);
unsigned int	revers_filter(unsigned int color, t_opt *opt);
unsigned int	apply_contrast(unsigned int color, t_opt *opt);
void		apply_bump(double *nvec, double *obj_coor, double ratio);
int		output_bmp(t_par *ppt);
double		fade(double curve);
double		lerp(double curve, double a, double b);
unsigned int	xorus_filter(unsigned int color, t_opt *opt);
int		output_tga(t_par *ppt);
char		*get_file_name(char *name, char *ext);
void		nb_to_str(char *str, int nb, int size);
void		my_perror(char *str);
int		check_perror(char *str, int err);

#endif /* !MAIN_H_ */
