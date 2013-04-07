/*
** supersampling.h for supersampling in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri Apr  5 11:07:49 2013 luc sinet
** Last update Sun Apr  7 18:34:13 2013 luc sinet
*/

#ifndef SUPERSAMPLING_H_
# define SUPERSAMPLING_H_

# define SSP 1.0

typedef struct	s_samp
{
  double	square;
  double	spacing;
  unsigned int	*pixel;
}		t_samp;

unsigned int	supersampling(t_rt *rpt, t_samp *spt, int x, int y);

#endif
