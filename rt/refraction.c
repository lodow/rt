/*
** refraction.c for rt in /home/dellam_a/Projet/rt/rt
**
** Made by Adrien Della Maggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Mon Apr  1 12:31:29 2013 Adrien Della Maggiora
** Last update Tue Apr  2 19:46:52 2013 Adrien Della Maggiora
*/

#include <math.h>
#include "main.h"
#include "light.h"
#include "change_color.h"

unsigned int	apply_refrac(unsigned int color1, double n, double alpha,
			     unsigned int color2)
{
  unsigned char	c1[3];
  unsigned char	c2[3];

  decomp_color(color1, c1);
  decomp_color(color2, c2);
  c1[0] = ((1 - alpha) * c2[0]) + (alpha * c1[0]);
  c1[1] = ((1 - alpha) * c2[1]) + (alpha * c1[1]);
  c1[2] = ((1 - alpha) * c2[2]) + (alpha * c1[2]);
  return (recomp_color(c1));
}

void		get_new_vec(t_vec *vec, t_lco *lpt, double n1, double n2)
{
  double	n;
  double	norme;
  double	cosa;
  double	sina;

  if (n2 == 0)
    return ;
  n = n1 / n2;
  norme = (sqrt(pow(lpt->nvec[0], 2) + pow(lpt->nvec[1], 2)
		+ pow(lpt->nvec[2], 2))
	   * sqrt(pow(lpt->lvec[0], 2) + pow(lpt->lvec[1], 2)));
  if (norme < ZERO && norme > -ZERO)
    return ;
  cosa = (lpt->nvec[0] * lpt->lvec[0]
	  + lpt->nvec[1] * lpt->lvec[1]
	  + lpt->nvec[2] * lpt->lvec[2]) / norme;
  sina = pow(n, 2)  * (1.0 - pow(cosa, 2));
  if (sina > 1.0)
    return ;
  vec->vx = n * lpt->lvec[0] - (n + sqrt(1.0 - sina) * lpt->nvec[0]);
  vec->vy = n * lpt->lvec[1] - (n + sqrt(1.0 - sina) * lpt->nvec[1]);
  vec->vz = n * lpt->lvec[2] - (n + sqrt(1.0 - sina) * lpt->nvec[2]);
}

unsigned int	get_new_color(t_rt *rpt, t_cam *cpt, t_lco *lpt, double n)
{
  double	k;
  t_cam		save;
  t_cam		cam_tmp;
  t_vec		vec_tmp;

  save.cx = cpt->cx;
  save.cy = cpt->cy;
  save.cz = cpt->cz;
  cam_tmp = modif_cam(rpt->cpt, rpt->obj[rpt->obj_num]);
  rotate_cam(&cam_tmp, rpt->obj[rpt->obj_num]);
  vec_tmp = rotate_vec(rpt->vpt, rpt->obj[rpt->obj_num]);
  cpt->cx = cam_tmp.cx + k * vec_tmp.vx;
  cpt->cy = cam_tmp.cy + k * vec_tmp.vy;
  cpt->cz = cam_tmp.cz + k * vec_tmp.vz;
  get_new_vec(&vec_tmp, lpt, n, rpt->obj[rpt->obj_num].n);
  calc_inter(rpt, &k);
  cpt->cx = save.cx;
  cpt->cy = save.cy;
  cpt->cz = save.cz;
  if (k != -1)
    return (recomp_color(rpt->obj[rpt->obj_num].color));
  return (0x000000);
}

unsigned int	refrac(t_rt *rpt, t_cam *cpt, t_lco *lpt, unsigned int color)
{
  double	alpha;
  double	n;
  unsigned int	color2;

  n = 1;
  while (rpt->obj[rpt->obj_num].alpha != 0)
    {
      color2 = get_new_color(rpt, cpt, lpt, n);
      alpha = rpt->obj[rpt->obj_num].alpha;
      color = apply_refrac(color, n, alpha, color2);
      n = rpt->obj[rpt->obj_num].n;
    }
  return (color);
}
