/*
** change_color.h for change in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Mar 27 17:42:09 2013 luc sinet
** Last update Tue Apr  2 19:56:21 2013 Adrien Della Maggiora
*/

#ifndef CHANGE_COLOR_H_
# define CHANGE_COLOR_H_

typedef	struct s_lco	t_lco;

unsigned int	apply_light(unsigned char *c, double cosa, t_obj *ept);
void	   	decomp_color(unsigned int color, unsigned char *ncolor);
unsigned int   	recomp_color(unsigned char *color);
unsigned int	refrac(t_rt *rpt, t_cam *cpt, t_lco *lpt, unsigned int color);

#endif
