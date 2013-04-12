/*
** change_color.h for change in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Mar 27 17:42:09 2013 luc sinet
** Last update Thu Apr 11 17:44:52 2013 luc sinet
*/

#ifndef CHANGE_COLOR_H_
# define CHANGE_COLOR_H_

# define FOG_DIST 2500000.0
# define FOG_COLOR1 180.0
# define FOG_COLOR2 180.0
# define FOG_COLOR3 180.0

typedef	struct s_lco	t_lco;

unsigned int	apply_light(unsigned char *c, double cosa, t_obj *ept);
void	   	decomp_color(unsigned int color, unsigned char *ncolor);
unsigned int   	recomp_color(unsigned char *color);
unsigned int	refrac(t_rt *rpt, t_cam *cpt, t_lco *lpt, unsigned int color);

#endif