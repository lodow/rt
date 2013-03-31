/*
** lightning.h for light in /home/sinet_l//rtv1-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Mar 14 13:09:39 2013 luc sinet
** Last update Sun Mar 31 13:29:49 2013 luc sinet
*/

#ifndef LIG_H_
# define LIG_H_

# define NX(type, xp) (type == 1) ? 0.0 : xp;
# define NY(type, yp) (type == 1) ? 0.0 : yp;
# define NZ(t, c, zp) (t == 1) ? 100 : (t == 2) ? (-c * zp) : (t == 3) ? 0 : zp

# define DISTM 100000.0

typedef struct	s_lco
{
  double	obj_coor[3];
  double	nvec[3];
  double	lvec[3];
}		t_lco;

unsigned int	get_light(t_rt *rpt, double k, unsigned int color);
long int	point_distance(double *p1, double *p2);
double		apply_distance(t_lco *lpt, t_lig *obj, double cosa);
void		assign_normal1(t_lco *lpt, int type);
void		assign_normal2(t_lco *lpt, int type);

#endif
