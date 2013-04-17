/*
** refraction.c for rt in /home/dellam_a/Projet/rt/rt
**
** Made by Adrien Della Maggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Mon Apr  1 12:31:29 2013 Adrien Della Maggiora
** Last update Wed Apr 17 14:49:24 2013 Adrien
*/

#include <math.h>
#include "include/main.h"
#include "include/light.h"
#include "include/change_color.h"

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

void		get_new_vec(double *res, double *nor, double *vec, double n)
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
  res[0] = n * vec[0] - (n + sqrt(1.0 - sina) * nor[0]);
  res[1] = n * vec[1] - (n + sqrt(1.0 - sina) * nor[1]);
  res[2] = n * vec[2] - (n + sqrt(1.0 - sina) * nor[2]);
}

unsigned int	get_new_color(t_rt *rpt, t_cam *cpt, t_lco *lpt, double n)
{
  double	k;
  double	*cam_tmp;
  double	*vec_tmp;
  t_cam		save;

  save.pos[0] = cpt->pos[0];
  save.pos[1] = cpt->pos[1];
  save.pos[2] = cpt->pos[2];
  
  copy_tab(cpt->pos, cam_tmp, 3);
  copy_tab(rpt->vpt->vec, vec_tmp, 3);
  modif_cam(cam_tmp, rpt->obj[rpt->obj_num].pos);
  rotate(cam_tmp, rpt->obj[rpt->obj_num].ocos, rpt->obj[rpt->obj_num].osin, 0);
  rotate(vec_tmp, rpt->obj[rpt->obj_num].ocos, rpt->obj[rpt->obj_num].osin, 0);
  cpt->pos[0] = cam_tmp[0] + k * vec_tmp[0];
  cpt->pos[1] = cam_tmp[1] + k * vec_tmp[1];
  cpt->pos[2] = cam_tmp[2] + k * vec_tmp[2];
  if (rpt->obj[rpt->obj_num].indice[1] > 0.000001)
    get_new_vec(vec_tmp, lpt->nvec, lpt->lvec, n / rpt->obj[rpt->obj_num].indice[1]);
  calc_inter(rpt, &k);
  cpt->pos[0] = save.pos[0];
  cpt->pos[1] = save.pos[1];
  cpt->pos[2] = save.pos[2];
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
  while (rpt->obj[rpt->obj_num].indice[0] > 0.0000001 && obj_num != rpt->obj_num)
    {
      obj_num = rpt->obj_num;
      color2 = get_new_color(rpt, cpt, lpt, n);
      alpha = rpt->obj[rpt->obj_num].indice[0];
      if (color2 != color_obj || obj_num != rpt->obj_num)
	color = apply_refrac(color, alpha, color2);
      n = rpt->obj[rpt->obj_num].indice[1];
      obj_num = rpt->obj_num;
    }
  return (color);
}
