/*
** other_perlin_effect.c for other_perlin_effect in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun May 19 18:38:43 2013 luc sinet
** Last update Sun May 19 20:15:16 2013 luc sinet
*/

#include <math.h>
#include "main.h"
#include "perlin.h"
#include "pp_image.h"
#include "pars.h"
#include "change_color.h"

unsigned int	perlin_disco(int *coor_pixel, unsigned char *color_obj,
			     t_perl *ppt)
{
  double	pn_r;
  double	pn_v;
  double	pn_b;

  (void)ppt;
  pn_r = get_perlin(coor_pixel[0] / (double)WINX,
		    coor_pixel[1] / (double)WINY,
		    50, 0.2, 2, 3);
  pn_v = get_perlin(coor_pixel[0] / (double)WINX,
		    coor_pixel[1] / (double)WINY,
		    3, 0.2, 2, 3);
  pn_b = get_perlin(coor_pixel[0] / (double)WINX,
		    coor_pixel[1] / (double)WINY,
		    2, 0.2, 2, 3);
  color_obj[0] = LIMIT(pn_r * 200 + 100, 0, 255);
  color_obj[1] = LIMIT(pn_v * 200 + 50, 0, 255);
  color_obj[2] = LIMIT(pn_b * 200 + 50, 0, 255);
  return (recomp_color(color_obj));
}

unsigned int	perlin_marble(int *coor_pixel, unsigned char *color_obj,
			      t_perl *ppt)
{
  ppt->pn = cos(coor_pixel[0] / 30.0
		+ get_perlin(coor_pixel[0] / (double)WINX,
			     coor_pixel[1] / (double)WINY,
			     0, 1.5, 2.5, 10) * 70);
  color_obj[0] = LIMIT(255 * (1 - ppt->pn), 0, 255);
  color_obj[1] = LIMIT(255 * (1 - ppt->pn), 0, 255);
  color_obj[2] = LIMIT(255 * (1 - ppt->pn), 0, 255);
  return (recomp_color(color_obj));
}

unsigned int	perlin_zebra(int *coor_pixel, unsigned char *color_obj,
			     t_perl *ppt)
{
  ppt->pn = cos(coor_pixel[0] / 30.0
		+ get_perlin(coor_pixel[0] / (double)WINX,
			     coor_pixel[1] / (double)WINY,
			     0, 3, 3, 1) * 70);
  color_obj[2] = LIMIT(255 * (1 - ppt->pn), 0, 255);
  color_obj[1] = LIMIT(255 * (1 - ppt->pn), 0, 255);
  color_obj[0] = LIMIT(255 * (1 - ppt->pn), 0, 255);
  return (recomp_color(color_obj));
}
