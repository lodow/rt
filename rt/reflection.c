/*
** reflection.c for reflection in /tmp/rt/rt
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Tue Apr  2 18:25:49 2013 etienne debas
** Last update Mon Apr 15 22:43:37 2013 luc sinet
*/

#include <math.h>
#include "include/main.h"
#include "include/change_color.h"
#include "include/light.h"

t_vec		get_vec_reflection(double lvec[3], double nvec[3], double scalar)
{
  t_vec		vec_reflection;

  vec_reflection.vx = lvec[0] - 2 * scalar * nvec[0];
  vec_reflection.vx = lvec[1] - 2 * scalar * nvec[1];
  vec_reflection.vx = lvec[2] - 2 * scalar * nvec[2];
  return (vec_reflection);
}

/* float		vec_to_tab(t_vec *vec) */
/* { */
/*   float		tab[3]; */

/*   tab[0] = vec->vx; */
/*   tab[1] = vec->vy; */
/*   tab[2] = vec->vz; */
/*   return (tab); */
/* } */

/* double		get_scalar(double tab1[3], double tab2[3]) */
/* { */
/*   double		scalar; */

/*   scalar = tab1[0] * tab2[0] + tab1[1] * tab2[1] + tab1[2] * tab2[2]; */
/*   return (scalar); */
/* } */

/* double		get_angle_specular(double lvec[3], double nvec[3], t_lco *lpt) */
/* { */
/*   double	bnorme; */
/*   double	angle; */
/*   t_vec		reflection; */
/*   double	scalar; */

/*   scalar = get_scalar(lvec, nvec); */
/*   reflection = get_vec_reflection(lvec, nvec, scalar); */
/*   bnorme = (sqrt(pow(reflection.vx, 2) + pow(reflection.vy, 2) */
/* 		 + pow(reflection.vz, 2)) */
/* 	    * sqrt(pow(lvec[0], 2) + pow(lvec[1], 2) */
/* 		   + pow(lvec[2], 2))); */
/*   angle = (reflection.vx * lvec[0] */
/* 	   + reflection.vy * lvec[1] */
/* 	   + reflection.vz * lvec[2]) / bnorme; */
/*   angle = acos(angle); */
/*   return (angle); */
/* } */

double	get_specular(t_vec *vpt, double vec[3])
{
  double	bnorme;

  bnorme = (sqrt(pow(vec[0], 2) + pow(vec[1], 2) + pow(vec[2], 2))
	    * sqrt(pow(vpt->vx, 2) + pow(vpt->vy, 2) + pow(vpt->vz, 2)));
  if (bnorme > ZERO)
    return ((vec[0] * vpt->vx + vec[1] * vpt->vy + vec[2] * vpt->vz) / bnorme);
  else
    return (1.0);
}

void		calc_reflec_vector(t_vec *vpt, t_cam *cpt, t_lco *lpt, t_obj *obj)
{
  double	res[3];
  double	vec[3];
  double	scal;
  double	norme_vec;
  double	norme_nor;

  cpt->tx = cpt->pos[0];
  cpt->ty = cpt->pos[1];
  cpt->tz = cpt->pos[2];
  vec[0] = lpt->obj_coor[0] - cpt->pos[0];
  vec[1] = lpt->obj_coor[1] - cpt->pos[1];
  vec[2] = lpt->obj_coor[2] - cpt->pos[2];
  /* cpt->pos[0] = lpt->obj_coor[0]; */
  /* cpt->pos[1] = lpt->obj_coor[1]; */
  /* cpt->pos[2] = lpt->obj_coor[2]; */
  norme_vec = sqrt(pow(vec[0], 2) + pow(vec[1], 2) + pow(vec[2], 2));
  norme_nor = sqrt(pow(lpt->nvec[0], 2) + pow(lpt->nvec[1], 2) + pow(lpt->nvec[2], 2));
  scal = vec[0] * lpt->nvec[0] + vec[1] * lpt->nvec[1] + vec[2] * lpt->nvec[2];
  res[0] = (-2 * (lpt->nvec[0] / norme_nor)) * scal + (vec[0] / norme_vec);
  res[1] = (-2 * (lpt->nvec[1] / norme_nor)) * scal + (vec[1] / norme_vec);
  res[2] = (-2 * (lpt->nvec[2] / norme_nor)) * scal + (vec[2] / norme_vec);
  vpt->vx = res[0];
  vpt->vy = res[1];
  vpt->vz = res[2];
  lpt->spec = get_specular(vpt, vec);
}

unsigned int	apply_reflection(unsigned int color, unsigned int obj_color,
				 double indice)
{
  unsigned char	c[3];
  unsigned char	c_obj[3];

  decomp_color(color, c);
  decomp_color(obj_color, c_obj);
  c[0] = c[0] * (1 - indice) + c_obj[0] * indice;
  c[1] = c[1] * (1 - indice) + c_obj[1] * indice;
  c[2] = c[2] * (1 - indice) + c_obj[2] * indice;
  return (recomp_color(c));
}

unsigned int	reflection(t_rt *rpt, t_lco *lpt, unsigned int color)
{
  double	indice;
  double	k;
  int		i;

  i = 0;
  while (i < MAX_R && rpt->obj[rpt->obj_num].reflec >= ZERO)
    {
      indice = rpt->obj[rpt->obj_num].reflec;
      calc_reflec_vector(rpt->vpt, rpt->cpt, lpt, &rpt->obj[rpt->obj_num]);
      calc_inter(rpt, &k);
      if (k != -1)
	color = apply_reflection(color,
				 get_light(rpt, k, &rpt->obj[rpt->obj_num], lpt),
				 indice);
      else
	color = apply_reflection(color, 0x000000, indice);
      ++i;
      rpt->cpt->pos[0] = rpt->cpt->tx;
      rpt->cpt->pos[1] = rpt->cpt->ty;
      rpt->cpt->pos[2] = rpt->cpt->tz;
    }
  return (color);
}
