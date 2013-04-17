/*
** supersampling.h for supersampling in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri Apr  5 11:07:49 2013 luc sinet
** Last update Tue Apr 16 20:41:14 2013 luc sinet
*/

#ifndef SUPERSAMPLING_H_
# define SUPERSAMPLING_H_

# define IN(x) (x == 0) ? (0) : (1)

typedef struct	s_samp
{
  double	square;
  double	spacing;
  unsigned int	*pixel;
}		t_samp;

unsigned int	supersampling(t_rt *rpt, t_samp *spt, int x, int y);

#endif
