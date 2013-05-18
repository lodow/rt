/*
** perlin_noise2.c for rt in /home/debas_e/
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Sat May 18 17:31:50 2013 etienne debas
** Last update Sat May 18 20:26:54 2013 etienne debas
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "pp_image.h"

unsigned int recomp_color(unsigned char *);

#define B 0x100
#define BM 0xff
#define N 0x1000
#define NP 12
#define NM 0xfff

#define s_curve(t) ( t * t * (3. - 2. * t) )
#define lerp(t, a, b) ( a + t * (b - a) )

#define at2(rx,ry) ( rx * q[0] + ry * q[1] )
#define at3(rx,ry,rz) ( rx * q[0] + ry * q[1] + rz * q[2] )


static int p[B + B + 2];
static double g3[B + B + 2][3];
static double g2[B + B + 2][2];
static double g1[B + B + 2];
static int start = 1;

#ifndef ABS
# define ABS(x) ((x) < 0 ? (-x) : (x))
#endif

void normalize2(double v[2])
{
  double s;

  s = sqrt(v[0] * v[0] + v[1] * v[1]);
  v[0] = v[0] / s;
  v[1] = v[1] / s;
}

void normalize3(double v[3])
{
  double s;

  s = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
  v[0] = v[0] / s;
  v[1] = v[1] / s;
  v[2] = v[2] / s;
}

void init(void)
{
  int i, j, k;

  for (i = 0 ; i < B ; i++) {
    p[i] = i;
    g1[i] = (double)((rand() % (B + B)) - B) / B;

    for (j = 0 ; j < 2 ; j++)
      g2[i][j] = (double)((rand() % (B + B)) - B) / B;
    normalize2(g2[i]);

    for (j = 0 ; j < 3 ; j++)
      g3[i][j] = (double)((rand() % (B + B)) - B) / B;
    normalize3(g3[i]);
  }

  while (--i) {
    k = p[i];
    p[i] = p[j = rand() % B];
    p[j] = k;
  }

  for (i = 0 ; i < B + 2 ; i++) {
    p[B + i] = p[i];
    g1[B + i] = g1[i];
    for (j = 0 ; j < 2 ; j++)
      g2[B + i][j] = g2[i][j];
    for (j = 0 ; j < 3 ; j++)
      g3[B + i][j] = g3[i][j];
  }
}

double noise3(double vec[3])
{
  int bx0, bx1, by0, by1, bz0, bz1, b00, b10, b01, b11;
  double rx0, rx1, ry0, ry1, rz0, rz1, *q, sy, sz, a, b, c, d, t, u, v;
  int i, j;

  if (start) {
    start = 0;
    init();
  }

  t = vec[0] + N;
  bx0 = ((int)t) & BM;
  bx1 = (bx0+1) & BM;
  rx0 = t - (int)t;
  rx1 = rx0 - 1.;

  t = vec[1] + N;
  by0 = ((int)t) & BM;
  by1 = (by0+1) & BM;
  ry0 = t - (int)t;
  ry1 = ry0 - 1.;

  t = vec[2] + N;
  bz0 = ((int)t) & BM;
  bz1 = (bz0+1) & BM;
  rz0 = t - (int)t;
  rz1 = rz0 - 1.;


  i = p[ bx0 ];
  j = p[ bx1 ];

  b00 = p[ i + by0 ];
  b10 = p[ j + by0 ];
  b01 = p[ i + by1 ];
  b11 = p[ j + by1 ];

  t  = s_curve(rx0);
  sy = s_curve(ry0);
  sz = s_curve(rz0);

  q = g3[ b00 + bz0 ] ; u = at3(rx0,ry0,rz0);
  q = g3[ b10 + bz0 ] ; v = at3(rx1,ry0,rz0);
  a = lerp(t, u, v);

  q = g3[ b01 + bz0 ] ; u = at3(rx0,ry1,rz0);
  q = g3[ b11 + bz0 ] ; v = at3(rx1,ry1,rz0);
  b = lerp(t, u, v);

  c = lerp(sy, a, b);

  q = g3[ b00 + bz1 ] ; u = at3(rx0,ry0,rz1);
  q = g3[ b10 + bz1 ] ; v = at3(rx1,ry0,rz1);
  a = lerp(t, u, v);

  q = g3[ b01 + bz1 ] ; u = at3(rx0,ry1,rz1);
  q = g3[ b11 + bz1 ] ; v = at3(rx1,ry1,rz1);
  b = lerp(t, u, v);

  d = lerp(sy, a, b);

  return lerp(sz, c, d);
}

//Le somme des armoniques:
//Alpha : coefficient d'atténuation pour la prochaine fréquence, plus on diminue ce coef, et plus
//la fonction est bruité
//Beta  : espacement.
//n le nombre d'harmonique.
double get_perlin(double x,double y,double z,double alpha,double beta,int n)
{
  int i;
  double val,sum = 0;
  double p[3],scale = 1;

  p[0] = x;
  p[1] = y;
  p[2] = z;
  for (i=0;i<n;i++) {
    val = noise3(p);
    val = ABS(val);
    sum += val / scale;
    scale *= alpha;
    p[0] *= beta;
    p[1] *= beta;
    p[2] *= beta;
  }
  return (sum);
}


unsigned int	bruit_de_perlin(int *coor_pixel, unsigned char *color_obj,
				int perlin)
{
  float		pn;

  pn = cos(coor_pixel[0] / 30.0
  	   + get_perlin(coor_pixel[0]/(double)WINX,
			coor_pixel[1]/(double)WINY,
			0,5,5,5) * 70);
  pn = ABS(pn);
  color_obj[0] = 255 * (1 - pn);
  color_obj[1] = 255 * (1 - pn);
  color_obj[2] = 255 * (1 - pn);
  return (recomp_color(color_obj));
}
