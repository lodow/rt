/*
** aliasing.h for alaising in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Apr  2 19:58:47 2013 luc sinet
** Last update Sat Jun  8 18:01:17 2013 adrien dellamaggiora
*/

# ifndef ALIASING_H_
# define ALIASING_H_

# define COLOR_RATIO 20
# define AVERAGE(x , y) ((x + y) / 2.0)
# define AA 1

typedef struct	s_ali
{
  int		x;
  int		y;
  int		ratio;
  unsigned char	tcomp[3];
  unsigned char	fcomp[3];
  unsigned char	icomp[3];
}		t_ali;

unsigned int	recomp_color(unsigned char *color);

#endif /* !ALIASING_H_ */
