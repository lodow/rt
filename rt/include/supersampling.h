/*
** supersampling.h for supersampling in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri Apr  5 11:07:49 2013 luc sinet
** Last update Sat Jun  8 17:53:06 2013 adrien dellamaggiora
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

#endif /* !SUPERSAMPLING_H_ */
