/*
** main.h for main in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Feb 25 11:18:51 2013 luc sinet
** Last update Sun Mar 17 16:16:53 2013 luc sinet
*/

#ifndef MAIN_H_
# define MAIN_H_

#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include "pp_image.h"
#include "str.h"
#include "nb.h"
#include "lightning.h"

# define ZERO 0.000001
# define IVAL -1000000
# define RANG(ang) (ang < 0) ? (ang * -1) : ang
# define RAD(ang) (ang * 3.1415926 / 180)
# define DIST 1000;
# define K_ESC 65307

typedef struct	s_obj t_obj;

typedef struct	s_cam
{
  double	cx;
  double	cy;
  double	cz;
  double	tx;
  double	ty;
  double	tz;
}		t_cam;

typedef struct	s_elem
{
  int		type;
  double	pos[3];
  double	angle[4];
  unsigned int	color;
  double	rayon;
  double	bright;
}		t_elem;

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
  double	vtx;
  double	vty;
  double	vtz;
}		t_vec;

typedef struct	s_rt
{
  char		**err;
  t_lco		*lpt;
  t_vec		*vpt;
  t_cam		*cpt;
  t_elem	*tab;
  t_lig		*ltab;
  double	(*eptr[4])(t_cam *cpt, t_vec *vpt, t_elem *ept);
}		t_rt;

int	check_inter(t_rt *rpt, t_elem *tab, double *kmin, int *color);
void	get_addr(t_rt *rpt);
void	new_coor(t_vec *vpt, t_cam *cpt, int x, int y);
int	start_render(t_rt *rpt, t_par *ppt);
int	pars(t_rt *rpt, char *fname);
int	fill_tab(t_obj *opt, t_elem *tab, char *name);
int	fill_light(t_obj *opt, t_lig *ltab, char *name);
void	solve_param(t_rt *rpt, int i, double k, int type);
int	get_light(t_rt *rpt, double k, int type, int color);
int	init(t_cam *cpt);
void	init_pt(t_rt *rpt);
void	init_light(t_lig *ltab, t_obj *opt);
void	init_elem(t_elem *tab, t_obj *opt);
int	merror(char *err, int val);
void	rotate_x(t_vec *vpt, t_cam *cpt, t_elem *elem);
void	rotate_y(t_vec *vpt, t_cam *cpt, t_elem *elem);
void	rotate_z(t_vec *vpt, t_cam *cpt, t_elem *elem);
double	move_cam(t_rt *rpt, t_elem *elem, int type);
double	get_min(double k1, double k2);
double	sphere(t_cam *cpt, t_vec *vpt, t_elem *ept);
double	cone(t_cam *cpt, t_vec *vpt, t_elem *ept);
double	plan(t_cam *cpt, t_vec *vpt, t_elem *ept);
double	cylinder(t_cam *cpt, t_vec *vpt, t_elem *ept);
double	shadow(t_rt *rpt, t_lig *lpt, int color);
void	transl_cam_to_spot(t_rt *rpt, t_lig *lpt);
int	print_i(t_par *ppt);

#endif
