/*
** perlin_effect.c for rt in /tmp/rt/rt
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Sat May 18 22:44:56 2013 etienne debas
** Last update Mon May 20 13:43:17 2013 luc sinet
*/

#include <math.h>
#include "main.h"
#include "perlin.h"
#include "pp_image.h"
#include "pars.h"
#include "change_color.h"

/* random */
/* épaisseur */
/* floutage */
/* bullshit bouger le dessin */

unsigned int	perlin_fire(int *coor_pixel, unsigned char *color_obj,
			     t_perl *ppt)
{
  fill_tab_from_str(ppt->sval, "0.1, 0.4, 0.6", 3);
  fill_tab_from_str(ppt->col, "192, 15, 5, 255, 204, 0", 6);
  ppt->pn = get_perlin((coor_pixel[0] - 500) / (double)WINX,
		       (coor_pixel[1] - 500) / (double)WINY,
		       0, 2, 2, 50);
  return (recomp_color(color_obj));
}

unsigned int	perlin_cloud(int *coor_pixel, unsigned char *color_obj,
			     t_perl *ppt)
{
  fill_tab_from_str(ppt->sval, "0.1, 0.4, 0.6", 3);
  fill_tab_from_str(ppt->col,
		    "100, 100, 200, 255, 255, 255, 100, 100, 200", 9);
  ppt->pn = get_perlin((coor_pixel[0] - 500) / (double)WINX,
		       (coor_pixel[1] - 500) / (double)WINY,
		       0.2, 2.15, 5, 1);
  return (recomp_color(color_obj));
}

unsigned int	perlin_wood(int *coor_pixel, unsigned char *color_obj,
			    t_perl *ppt)
{
  fill_tab_from_str(ppt->sval, "0.2, 0.4, 0.6", 3);
  fill_tab_from_str(ppt->col, "206, 103, 0, 128, 64, 0, 89, 45, 0", 9);
  ppt->pn = 20 * get_perlin(coor_pixel[0] / (double)WINX,
			    coor_pixel[1] / (double)WINY,
			    0.5, 1.5, 1.6, 20);
  ppt->pn = ppt->pn - (int)ppt->pn;
  interpolation(color_obj, ppt->pn, ppt->sval, ppt->col);
  return (recomp_color(color_obj));
}

unsigned int	perlin_mercury(int *coor_pixel, unsigned char *color_obj,
			       t_perl *ppt)
{
  fill_tab_from_str(ppt->sval, "0.001, 0.4, 0.6", 3);
  fill_tab_from_str(ppt->col, "84, 255, 95, 28, 59, 255, 255, 37, 17", 9);
  ppt->pn = get_perlin(coor_pixel[0] / (double)WINX,
		       coor_pixel[1] / (double)WINY,
		       0.1, 0.7, 3, 3.8);
  interpolation(color_obj, ppt->pn, ppt->sval, ppt->col);
  return (recomp_color(color_obj));
}

unsigned int	perlin(double *inter, unsigned char *color_obj,
		       int effect)
{
  t_perl	ppt;
  int		i;
  unsigned int	(*ptr[7])(int *inter, unsigned char *color_obj,
			  t_perl *ppt);

  i = 0;
  ptr[0] = &perlin_marble;
  ptr[1] = &perlin_zebra;
  ptr[2] = &perlin_cloud;
  ptr[3] = &perlin_wood;
  ptr[4] = &perlin_mercury;
  ptr[5] = &perlin_disco;
  ptr[6] = &perlin_fire;
  while (i < 7 && i != effect)
    ++i;
  return (ptr[i]((int *)inter, color_obj, &ppt));
}
