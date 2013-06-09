/*
** change_color.h for change in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Mar 27 17:42:09 2013 luc sinet
** Last update Sun Jun  9 06:44:12 2013 adrien dellamaggiora
*/

#ifndef CHANGE_COLOR_H_
# define CHANGE_COLOR_H_

# define FOG_DIST 2500000.0
# define FOG_COLOR1 180.0
# define FOG_COLOR2 180.0
# define FOG_COLOR3 180.0
# define MAX_R 40

typedef	struct	s_lco	t_lco;

typedef	struct	s_trans
{
  unsigned int	color[MAX_R];
  double	alpha[MAX_R];
  int		pass[256];
  int		nb_obj;
  int		count;
}		t_trans;

typedef	struct	s_reflec
{
  unsigned int	color[MAX_R + 1];
  double	alpha[MAX_R + 1];
  int		count;
}		t_reflec;

unsigned int	apply_light(unsigned char *c, double cosa,
			    double sdw_coef);
void	   	decomp_color(unsigned int color, unsigned char *ncolor);
unsigned int	recomp_color(unsigned char *color);
unsigned int	refrac(t_rt *rpt, t_cam *cpt, t_lco *lpt, unsigned int color);
unsigned int	reflection(t_rt *rpt, t_lco *lpt, unsigned int color,
			   double k);
unsigned int	apply_fog(unsigned int color, double *fog, double distance);
unsigned int	apply_indice(unsigned int color, unsigned int obj_color,
			     double indice);
unsigned int	transparency(t_rt *rpt, t_lco *lpt, unsigned int color,
			     double k);
unsigned int	darken_color(unsigned char *color, double sdw_coef);
void		change_shadow_color(unsigned char *obj_color,
				    t_obj *d_elem, t_lig *lpt);
void		get_color_texture(t_obj *obj, t_lco *lpt, double k, t_rt *rpt);
void		save_color_obj(unsigned char *color,
			       unsigned char *save);
void		reinit_color(unsigned char *color,
			     unsigned char *save);
void		checkerboard_color(double *inter, unsigned char *col,
				   int size);
void		init_texture_surface(t_rt *rpt, t_obj *obj, double *vcam);

#endif /* !CHANGE_COLOR_H_ */
