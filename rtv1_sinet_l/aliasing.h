/*
** aliasing.h for aliasing in /home/sinet_l//rtv1-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri Mar 15 20:21:31 2013 luc sinet
** Last update Sun Mar 17 11:46:58 2013 luc sinet
*/

#ifndef ALI_H_
# define ALI_H_

# define LCOL(x) (x >= 0) ? (1) : (0)
# define RCOL(x) (x <= WINX) ? 1 : 0
# define ULINE(y) (y >= 0) ? 1 : 0
# define DLINE(y) (y <= WINY) ? 1 : 0
# define ALCOL(x, val) (x >= 0) ? val : 0
# define ARCOL(x, val) (x <= WINX) ? val : 0
# define AULINE(y, val) (y >= 0) ? val : 0
# define ADLINE(y, val) (y <= WINY) ? val : 0
# define COLOR_COMP(t, c1, c2, c3) (t == 0) ? c1 : (t == 1) ? c2 : c3
# define BIGGEST(nb1 , nb2) ? (nb1 > nb2) ? nb1 : nb2
# define SMALLEST(nb1, nb2) ? (nb1 < nb2) ? nb1 : nb2
# define ABS(nb1) (nb1 < 0) ? -nb1 : nb1
# define CHECK_DIFF(oc, nc, diff) (diff > 25) ? nc : oc

typedef struct	s_col
{
  int		on;
  unsigned char	r;
  unsigned char	g;
  unsigned char	b;
}		t_col;

typedef struct	s_calc
{
  int		x;
  int		y;
  int		div;
  unsigned char	nb1;
  unsigned char	nb2;
  unsigned char	nb3;
  unsigned char	nb4;
}		t_calc;

int	calc_new_color(t_col *cor, t_par *ppt, t_calc *cpt);
void	aliasing(t_par *ppt);
void	get_border(t_col *cor, t_par *ppt, int x , int y);
void	get_color(t_par *ppt, t_col *cpt, int x, int y);

#endif
