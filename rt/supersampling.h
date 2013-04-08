/*
** supersampling.h for supersampling in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri Apr  5 11:07:49 2013 luc sinet
** Last update Mon Apr  8 21:46:03 2013 luc sinet
*/

#ifndef SUPERSAMPLING_H_
# define SUPERSAMPLING_H_

# define SSP 4

typedef struct	s_samp
{
  double	square;
  double	spacing;
  unsigned int	*pixel;
}		t_samp;

unsigned int	supersampling(t_rt *rpt, t_samp *spt, int x, int y);

#endif
