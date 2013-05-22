/*
** perlin_effect.c for rt in /tmp/rt/rt
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Sat May 18 22:44:56 2013 etienne debas
** Last update Wed May 22 16:42:30 2013 luc sinet
*/

#include <math.h>
#include "main.h"
#include "perlin.h"
#include "pp_image.h"
#include "pars.h"
#include "change_color.h"

unsigned int	perlin_fire(double *inter, unsigned char *color_obj,
			     t_perl *ppt, double frequency)
{
  fill_tab_from_str(ppt->col, "192, 15, 5, 255, 180, 0", 6);
  ppt->pn = fabs(get_perlin(frequency * inter[0],
  			    frequency * inter[1],
  			    frequency * inter[2]));
  color_obj[2] = LIMIT((ppt->col[2] * ppt->pn)
		       + ppt->col[5] * ((1 - ppt->pn)), 0, 255);
  color_obj[1] = LIMIT((ppt->col[1] * ppt->pn)
		       + ppt->col[4] * ((1 - ppt->pn)), 0, 255);
  color_obj[0] = LIMIT((ppt->col[0] * ppt->pn)
		       + ppt->col[3] * ((1 - ppt->pn)), 0, 255);
  return (recomp_color(color_obj));
}

unsigned int	perlin_cloud(double *inter, unsigned char *color_obj,
			     t_perl *ppt)
{
  fill_tab_from_str(ppt->sval, "0.01, 0.4, 0.6", 3);
  fill_tab_from_str(ppt->col,
		    "100, 100, 200, 255, 255, 255, 100, 100, 200", 9);
  ppt->pn = (get_perlin(0.01 * inter[0],
			0.01 * inter[1],
			0.01 * inter[2]));
  interpolation(color_obj, ppt->pn, ppt->sval, ppt->col);
  return (recomp_color(color_obj));
}

unsigned int	perlin_wood(double *inter, unsigned char *color_obj,
			    t_perl *ppt, double frequency)
{
  ppt->pn = 0;
  fill_tab_from_str(ppt->sval, "0.2, 0.4, 0.6", 3);
  fill_tab_from_str(ppt->col, "206, 103, 0, 128, 64, 0, 89, 45, 0", 9);
  ppt->pn += 20 * fabs((get_perlin(frequency * inter[0],
				   frequency * inter[1],
				   frequency * inter[2])));
  ppt->pn = ppt->pn - (int)ppt->pn;
  interpolation(color_obj, ppt->pn, ppt->sval, ppt->col);
  return (recomp_color(color_obj));
}

unsigned int	perlin_mercury(double *inter, unsigned char *color_obj,
			       t_perl *ppt)
{
  fill_tab_from_str(ppt->sval, "0.01, 0.4, 0.6", 3);
  fill_tab_from_str(ppt->col, "84, 255, 95, 28, 59, 255, 100, 37, 17", 9);
  ppt->pn = get_perlin(0.05 * inter[0],
		       0.05 * inter[1],
		       0.05 * inter[2]);
  interpolation(color_obj, ppt->pn, ppt->sval, ppt->col);
  return (recomp_color(color_obj));
}

unsigned int	perlin(double *inter, unsigned char *color_obj,
		       double *carac)
{
  t_perl	ppt;
  int		i;
  unsigned int	(*ptr[7])(double *inter, unsigned char *color_obj,
			  t_perl *ppt, double frequency);

  i = 0;
  /* copy_tab(coor_pixel, copy_coor, 2); */
  ptr[0] = &perlin_marble;
  ptr[1] = &perlin_zebra;
  ptr[2] = &perlin_cloud;
  ptr[3] = &perlin_wood;
  ptr[4] = &perlin_mercury;
  ptr[5] = &perlin_disco;
  ptr[6] = &perlin_fire;
  while (i < 7 && i != carac[0])
    ++i;
  return (ptr[i](inter, color_obj, &ppt, carac[1]));
}
