/*
** other_perlin_effect.c for other_perlin_effect in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun May 19 18:38:43 2013 luc sinet
** Last update Tue May 21 18:38:01 2013 etienne debas
*/

#include <math.h>
#include "main.h"
#include "perlin.h"
#include "pp_image.h"
#include "pars.h"
#include "change_color.h"

/* unsigned int	perlin_disco(double *inter, unsigned char *color_obj, */
/* 			     t_perl *ppt) */
/* { */
/*   double	pn_r; */
/*   double	pn_v; */
/*   double	pn_b; */

/*   (void)ppt; */
/*   pn_r = get_perlin(inter[0] / 100, */
/* 		    inter[1] / 100, */
/* 		    inter[2] / 100); */
/*   pn_v = get_perlin(inter[0] / 100, */
/* 		    inter[1] / 100, */
/* 		    inter[2] / 100); */
/*   pn_b = get_perlin(inter[0] / 100, */
/* 		    inter[1] / 100, */
/* 		    inter[2] / 100); */
  /* pn_v = get_perlin(coor_pixel[0] / (double)WINX, */
  /* 		    coor_pixel[1] / (double)WINY, */
  /* 		    3, 0.2, 2, 3); */
  /* pn_b = get_perlin(coor_pixel[0] / (double)WINX, */
  /* 		    coor_pixel[1] / (double)WINY, */
  /* 		    2, 0.2, 2, 3); */
/*   color_obj[0] = LIMIT(pn_r * 200 + 100, 0, 255); */
/*   color_obj[1] = LIMIT(pn_v * 200 + 50, 0, 255); */
/*   color_obj[2] = LIMIT(pn_b * 200 + 50, 0, 255); */
/*   return (recomp_color(color_obj)); */
/* } */

unsigned int	perlin_marble(double *inter, unsigned char *color_obj,
			      t_perl *ppt)
{
  unsigned int	cret;
  int		level;

  level = 1;
  ppt->pn = 0;
  while (level < 5)
    {
      ppt->pn += (1.0f / level)
	* fabs(get_perlin(level * inter[0],
			  level * inter[1],
			  level * inter[2]));
      level++;
    }
  ppt->pn = 0.5f * sinf((inter[0] + inter[1]) * 0.05f + ppt->pn) + 0.5f;
  /* color_obj[0] = color_obj[0] */
  color_obj[0] = LIMIT(255 * (1 - ppt->pn), 0, 255);
  color_obj[1] = LIMIT(255 * (1 - ppt->pn), 0, 255);
  color_obj[2] = LIMIT(255 * (1 - ppt->pn), 0, 255);
  return (recomp_color(color_obj));
}

/* unsigned int	perlin_zebra(int *coor_pixel, unsigned char *color_obj, */
/* 			     t_perl *ppt) */
/* { */
/*   ppt->pn = cos(coor_pixel[0] / 30.0 */
/* 		+ get_perlin(coor_pixel[0] / (double)WINX, */
/* 			     coor_pixel[1] / (double)WINY, */
/* 			     0, 3, 3, 1) * 70); */
/*   color_obj[2] = LIMIT(255 * (1 - ppt->pn), 0, 255); */
/*   color_obj[1] = LIMIT(255 * (1 - ppt->pn), 0, 255); */
/*   color_obj[0] = LIMIT(255 * (1 - ppt->pn), 0, 255); */
/*   return (recomp_color(color_obj)); */
/* } */
