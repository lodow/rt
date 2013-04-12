/*
** refraction.c for rt in /home/dellam_a/Projet/rt/rt
**
** Made by Adrien Della Maggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Mon Apr  1 12:31:29 2013 Adrien Della Maggiora
** Last update Thu Apr 11 10:04:10 2013 Adrien Della Maggiora
*/

#include <math.h>
#include "main.h"
#include "light.h"
#include "change_color.h"

unsigned int	apply_refrac(unsigned int color1, double alpha,
			     unsigned int color2)
{
  unsigned char	c1[3];
  unsigned char	c2[3];

  decomp_color(color1, c1);
  decomp_color(color2, c2);
  c1[0] = (alpha * c2[0]) + ((1 - alpha) * c1[0]);
  c1[1] = (alpha * c2[1]) + ((1 - alpha) * c1[1]);
  c1[2] = (alpha * c2[2]) + ((1 - alpha) * c1[2]);
  return (recomp_color(c1));
}

void		get_new_vec(t_vec *res, double *nor, double *vec, double n)
{
  double	norme;
  double	cosa;
  double	sina;

  norme = (sqrt(pow(nor[0], 2) + pow(nor[1], 2) + pow(nor[2], 2))
	   * sqrt(pow(vec[0], 2) + pow(vec[1], 2)));
  if (norme < ZERO && norme > -ZERO)
    return ;
  cosa = (nor[0] * vec[0] + nor[1] * vec[1] + nor[2] * vec[2]) / norme;
  sina = pow(n, 2)  * (1.0 - pow(cosa, 2));
  if (sina > 1.0)
    return ;
  res->vx = n * vec[0] - (n + sqrt(1.0 - sina) * nor[0]);
  res->vy = n * vec[1] - (n + sqrt(1.0 - sina) * nor[1]);
  res->vz = n * vec[2] - (n + sqrt(1.0 - sina) * nor[2]);
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
  if (rpt->obj[rpt->obj_num].n > 0.000001)
    get_new_vec(&vec_tmp, lpt->nvec, lpt->lvec, n / rpt->obj[rpt->obj_num].n);
  calc_inter(rpt, &k);
  cpt->cx = save.cx;
  cpt->cy = save.cy;
  cpt->cz = save.cz;
  if (k != -1)
    return (recomp_color(rpt->obj[rpt->obj_num].color));
  return (0x000000);
}

unsigned int	transparency(t_rt *rpt, t_cam *cpt, t_lco *lpt,
			     unsigned int color)
{
  double	alpha;
  double	n;
  int		obj_num;
  unsigned int	color2;
  unsigned int	color_obj;

  n = 1;
  color_obj = recomp_color(rpt->obj[rpt->obj_num].color);
  obj_num = -1;
  while (rpt->obj[rpt->obj_num].alpha > 0.0000001 && obj_num != rpt->obj_num)
    {
      obj_num = rpt->obj_num;
      color2 = get_new_color(rpt, cpt, lpt, n);
      alpha = rpt->obj[rpt->obj_num].alpha;
      if (color2 != color_obj || obj_num != rpt->obj_num)
	color = apply_refrac(color, alpha, color2);
      n = rpt->obj[rpt->obj_num].n;
      obj_num = rpt->obj_num;
    }
  return (color);
}
