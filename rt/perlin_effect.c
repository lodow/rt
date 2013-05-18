/*
** perlin_effect.c for rt in /tmp/rt/rt
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Sat May 18 22:44:56 2013 etienne debas
** Last update Sun May 19 00:58:57 2013 etienne debas
*/

double get_perlin(double x, double y, double z,
		  double alpha, double beta, int n);
unsigned int recomp_color(unsigned char *);

# define Limit(x)	((x > 255) ? 255 : ((x < 0) ? 0 : x))
# include <math.h>
# include "main.h"
# include "pp_image.h"

unsigned int	perlin_disco(int *coor_pixel, unsigned char *color_obj)
{
  double	pn_r;
  double	pn_v;
  double	pn_b;

  pn_r = get_perlin(coor_pixel[0] / (double)WINX,
		    coor_pixel[1] / (double)WINY,
		    0, 0.2, 5, 2);
  pn_v = get_perlin(coor_pixel[0] / (double)WINX,
		    coor_pixel[1] / (double)WINY,
		    1, 0.2, 5, 2);
  pn_b = get_perlin(coor_pixel[0] / (double)WINX,
		    coor_pixel[1] / (double)WINY,
		    2, 0.2, 5, 2);
  color_obj[2] = (unsigned char)Limit(pn_b * 200 + 50);
  color_obj[1] = (unsigned char)Limit(pn_v * 200 + 50);
  color_obj[0] = (unsigned char)Limit(pn_r * 200 + 100);
  return (recomp_color(color_obj));
}

unsigned int	perlin_marble(int *coor_pixel, unsigned char *color_obj)
{
  double	pn;

  pn = cos(coor_pixel[0] / 30.0
	   + get_perlin(coor_pixel[0] / (double)WINX,
			coor_pixel[1] / (double)WINY,
			0, 4, 6.5, 6) * 70);
  color_obj[2] = (unsigned char)Limit(255 * (1 - pn));
  color_obj[1] = (unsigned char)Limit(255 * (1 - pn));
  color_obj[0] = (unsigned char)Limit(255 * (1 - pn));
  return (recomp_color(color_obj));
}

unsigned int	perlin_zebra(int *coor_pixel, unsigned char *color_obj)
{
  double	pn;

  pn = cos(coor_pixel[0] / 30.0
	   + get_perlin(coor_pixel[0] / (double)WINX,
			coor_pixel[1] / (double)WINY,
			0, 3, 3, 1) * 70);
  color_obj[2] = (unsigned char)Limit(255 * (1 - pn));
  color_obj[1] = (unsigned char)Limit(255 * (1 - pn));
  color_obj[0] = (unsigned char)Limit(255 * (1 - pn));
  return (recomp_color(color_obj));
}

unsigned int	perlin_cloud(int *coor_pixel, unsigned char *color_obj)
{
  double	S1=0.1,S2=0.4,S3=0.6;
  double	C1_R=100,C1_G=100,C1_B=200;
  double	C2_R=255,C2_G=255,C2_B=255;
  double	C3_R=100,C3_G=100,C3_B=200;
  double	pn;

  pn = get_perlin((coor_pixel[0] - 500) / (double)WINX,
		  (coor_pixel[1] - 500) / (double)WINY,
		  0.2, 2.15, 5, 4);
  if (pn < 0.4)
    {
      color_obj[2] = (unsigned char)Limit(C1_B * ((pn - S1) / (S2 - S1))
					  + C2_B * ((S2 - pn) / (S2 - S1)));
      color_obj[1] = (unsigned char)Limit(C1_G * ((pn - S1) / (S2 - S1))
					  + C2_G * ((S2 - pn)/(S2 - S1)));
      color_obj[0] = (unsigned char)Limit(C1_R * ((pn - S1) / (S2 - S1))
					  + C2_R * ((S2 - pn) / (S2 - S1)));
    }
  else if (pn < 0.6)
    {
      color_obj[2] = (unsigned char)Limit(C2_B * ((pn - S2) / (S3 - S2))
					  + C3_B * ((S3 - pn) / (S3 - S2)));
      color_obj[1] = (unsigned char)Limit(C2_G * ((pn - S2) / (S3 - S2))
					  + C3_G * ((S3 - pn) / (S3 - S2)));
      color_obj[0] = (unsigned char)Limit(C2_R * ((pn - S2) / (S3 - S2))
					  + C3_R * ((S3 - pn) / (S3 - S2)));
    }
  else
    {
      color_obj[2] = (unsigned char)C1_B;
      color_obj[1] = (unsigned char)C1_G;
      color_obj[0] = (unsigned char)C1_R;
    }
  return (recomp_color(color_obj));
}

unsigned int	perlin_wood(int *coor_pixel, unsigned char *color_obj)
{
  double	S1 = 0.2, S2 = 0.4, S3 = 0.6;
  double	C1_R = 206, C1_G = 103, C1_B = 0;
  double	C2_R = 128, C2_G = 64 , C2_B = 0;
  double	C3_R = 89, C3_G = 45, C3_B = 0;
  double	pn;

  pn = 20 * get_perlin(coor_pixel[0] / (double)WINX,
		       coor_pixel[1] / (double)WINY,
		       0.5, 1.5, 1.25, 10);
  pn = pn - (int)pn;
  if (pn < 0.4)
    {
      color_obj[2] = (unsigned char)Limit(C1_B * ((pn - S1) / (S2 - S1))
					  + C2_B * ((S2 - pn) / (S2 - S1)));
      color_obj[1] = (unsigned char)Limit(C1_G * ((pn - S1) / (S2 - S1))
					  + C2_G * ((S2 - pn)/(S2 - S1)));
      color_obj[0] = (unsigned char)Limit(C1_R * ((pn - S1) / (S2 - S1))
					  + C2_R * ((S2 - pn) / (S2 - S1)));
    }
  else if (pn < 0.6)
    {
      color_obj[2] = (unsigned char)Limit(C2_B * ((pn - S2) / (S3 - S2))
					  + C3_B * ((S3 - pn) / (S3 - S2)));
      color_obj[1] = (unsigned char)Limit(C2_G * ((pn - S2) / (S3 - S2))
					  + C3_G * ((S3 - pn) / (S3 - S2)));
      color_obj[0] = (unsigned char)Limit(C2_R * ((pn - S2) / (S3 - S2))
					  + C3_R * ((S3 - pn) / (S3 - S2)));
    }
  else
    {
      color_obj[2] = (unsigned char)C1_B;
      color_obj[1] = (unsigned char)C1_G;
      color_obj[0] = (unsigned char)C1_R;
    }
  return (recomp_color(color_obj));
}

unsigned int	perlin_mercury(int *coor_pixel, unsigned char *color_obj)
{
  double	S1 = 0.001, S2 = 0.4, S3 = 0.6;
  double	C1_R = 84, C1_G = 255, C1_B = 95;
  double	C2_R = 255, C2_G = 127, C2_B = 48;
  double	C3_R = 255, C3_G = 37, C3_B = 17;
  double	pn;

  pn = get_perlin(coor_pixel[0] / (double)WINX,
		  coor_pixel[1] / (double)WINY,
		  0.1, 0.7, 2.5, 2.8);
  color_obj[2] = C1_B;
  color_obj[1] = C1_G;
  color_obj[0] = C1_R;
  if (pn < 0.4)
    {
      color_obj[2] = (unsigned char)Limit(C1_B * ((pn - S1) / (S2 - S1))
					  + C2_B * ((S2 - pn) / (S2 - S1)));
      color_obj[1] = (unsigned char)Limit(C1_G * ((pn - S1) / (S2 - S1))
					  + C2_G * ((S2 - pn)/(S2 - S1)));
      color_obj[0] = (unsigned char)Limit(C1_R * ((pn - S1) / (S2 - S1))
					  + C2_R * ((S2 - pn) / (S2 - S1)));
    }
  else if (pn < 0.6)
    {
      color_obj[2] = (unsigned char)Limit(C2_B * ((pn - S2) / (S3 - S2))
					  + C3_B * ((S3 - pn) / (S3 - S2)));
      color_obj[1] = (unsigned char)Limit(C2_G * ((pn - S2) / (S3 - S2))
					  + C3_G * ((S3 - pn) / (S3 - S2)));
      color_obj[0] = (unsigned char)Limit(C2_R * ((pn - S2) / (S3 - S2))
					  + C3_R * ((S3 - pn) / (S3 - S2)));
    }
  else
    {
      color_obj[2] = (unsigned char)C1_B;
      color_obj[1] = (unsigned char)C1_G;
      color_obj[0] = (unsigned char)C1_R;
    }
  return (recomp_color(color_obj));
}

unsigned int	perlin(int *coor_pixel, unsigned char *color_obj,
		       int effect)
{
  int		i;
  unsigned int	(*ptr[7])(int *coor_pixel, unsigned char *color_obj);

  i = 0;
  ptr[0] = &perlin_marble;
  ptr[1] = &perlin_zebra;
  ptr[2] = &perlin_cloud;
  ptr[3] = &perlin_wood;
  ptr[4] = &perlin_mercury;
  ptr[5] = &perlin_disco;
  ptr[6] = &perlin_disco;
  while (i < 7)
    {
      if (effect == i)
	return (ptr[i](coor_pixel, color_obj));
      i++;
    }
  return (0);
}
