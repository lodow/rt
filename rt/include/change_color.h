/*
** change_color.h for change in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Mar 27 17:42:09 2013 luc sinet
** Last update Mon Apr 29 14:45:59 2013 Adrien
*/

#ifndef CHANGE_COLOR_H_
# define CHANGE_COLOR_H_

# define FOG_DIST 2500000.0
# define FOG_COLOR1 180.0
# define FOG_COLOR2 180.0
# define FOG_COLOR3 180.0
# define MAX_R 40

typedef	struct s_lco	t_lco;

unsigned int	apply_light(unsigned char *c, double cosa, t_obj *ept);
void	   	decomp_color(unsigned int color, unsigned char *ncolor);
unsigned int   	recomp_color(unsigned char *color);
unsigned int	refrac(t_rt *rpt, t_cam *cpt, t_lco *lpt, unsigned int color);
unsigned int	reflection(t_rt *rpt, t_lco *lpt, unsigned int color, double k);
unsigned int	apply_fog(unsigned int color, double *fog, double distance);
unsigned int	apply_indice(unsigned int color, unsigned int obj_color,
			     double indice);
unsigned int    transparency(t_rt *rpt, t_lco *lpt, unsigned int color,
			     double k);

#endif
