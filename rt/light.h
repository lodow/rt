/*
** lightning.h for light in /home/sinet_l//rtv1-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Mar 14 13:09:39 2013 luc sinet
** Last update Tue Apr  2 15:38:50 2013 luc sinet
*/

#ifndef LIG_H_
# define LIG_H_

# define NX(type, xp) (type == 1) ? 0.0 : xp;
# define NY(type, yp) (type == 1) ? 0.0 : yp;
# define NZ(t, c, zp) (t == 1) ? 100 : (t == 2) ? (-c * zp) : (t == 3) ? 0 : zp
# define MAX(x, y) (x > y) ? x : y

# define DISTM 50000.0

typedef struct	s_lco
{
  double	obj_coor[3];
  double	nvec[3];
  double	lvec[3];
  double	max_cos;
  unsigned char	c_color[3];
}		t_lco;

long int	point_distance(double *p1, double *p2);
double		apply_distance(t_lco *lpt, t_lig *obj, double cosa);
void		assign_normal1(t_lco *lpt, int type);
void		assign_normal2(t_lco *lpt, int type);
void		apply_light_color(unsigned char *col_o, unsigned char *col_l, double lg_i);

#endif
