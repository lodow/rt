/*
** lightning.h for light in /home/sinet_l//rtv1-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Mar 14 13:09:39 2013 luc sinet
** Last update Sun Mar 17 19:05:18 2013 luc sinet
*/

#ifndef LIG_H_
# define LIG_H_

# define NX(type, xp) (type == 1) ? 0.0 : xp;
# define NY(type, yp) (type == 1) ? 0.0 : yp;
# define NZ(t, c, zp) (t == 1) ? 100 : (t == 2) ? (-c * zp) : (t == 3) ? 0 : zp

typedef struct	s_lig	t_lig;
typedef struct	s_elem	t_elem;

typedef struct	s_lco
{
  double	ocor[3];
  double	tlcor[3];
  double	lvec[3];
  double	nvec[3];
  int		obj;
}		t_lco;

void	get_normal(t_elem *ept, t_lco *lpt, int type);
int	new_color(int color, double cosa, t_lig *lpt, t_elem *ept);
void	rotate_vec(t_elem *ept, double *vt);

#endif
