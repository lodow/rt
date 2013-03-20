/*
** aliasing.h for aliasing in /home/sinet_l//rtv1-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri Mar 15 20:21:31 2013 luc sinet
** Last update Sat Mar 16 21:27:37 2013 etienne debas
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
# define COLOR(t, v1, v2, v3) (t == 1) ? v1 : (t == 2) ? v2 : v3

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

int	calc_new_color(t_col *cor, t_param_win *ppt, t_calc *cpt);
void	aliasing(t_param_win *ppt);
void	get_border(t_col *cor, t_param_win *ppt, int x , int y);
void	get_color(t_param_win *ppt, t_col *cpt, int x, int y);

#endif
