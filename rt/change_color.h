/*
** change_color.h for change in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Mar 27 17:42:09 2013 luc sinet
** Last update Wed Mar 27 19:42:30 2013 Adrien Della Maggiora
*/

#ifndef CCL_H_
# define CCL_H_

unsigned int	apply_light(unsigned int color, double lamb, t_lig *lpt);
void	   	decomp_color(unsigned int color, unsigned char *ncolor);
unsigned int   	recomp_color(unsigned char *color);

#endif
