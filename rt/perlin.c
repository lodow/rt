/*
** perlin3.c for rt in /tmp
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Sun May 19 18:23:43 2013 etienne debas
** Last update Thu May 30 13:02:39 2013 luc sinet
*/

#include <math.h>
#include <stdio.h>

static int table[512];
static int permutation[] =
  {
    151,160,137,91,90,15,
    131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,142,8,99,37,240,21,10,23,
    190, 6,148,247,120,234,75,0,26,197,62,94,252,219,203,117,35,11,32,57,177,33,
    88,237,149,56,87,174,20,125,136,171,168, 68,175,74,165,71,134,139,48,27,166,
    77,146,158,231,83,111,229,122,60,211,133,230,220,105,92,41,55,46,245,40,244,
    102,143,54, 65,25,63,161, 1,216,80,73,209,76,132,187,208, 89,18,169,200,196,
    135,130,116,188,159,86,164,100,109,198,173,186, 3,64,52,217,226,250,124,123,
    5,202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,58,17,182,189,28,42,
    223,183,170,213,119,248,152, 2,44,154,163, 70,221,153,101,155,167, 43,172,9,
    129,22,39,253, 19,98,108,110,79,113,224,232,178,185, 112,104,218,246,97,228,
    251,34,242,193,238,210,144,12,191,179,162,241, 81,51,145,235,249,14,239,107,
    49,192,214, 31,181,199,106,157,184, 84,204,176,115,121,50,45,127, 4,150,254,
    138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,156,180
  };

void	init_noise(int *c_unit, double *x, double *y, double *z)
{
  int	i;

  i = 0;
  while (i < 256)
    {
      table[i] = permutation[i];
      table[256 + i] = table[i];
      ++i;
    }
  c_unit[0] = (int)floor(*x) & 255;
  c_unit[1] = (int)floor(*y) & 255;
  c_unit[2] = (int)floor(*z) & 255;
  *x -= floor(*x);
  *y -= floor(*y);
  *z -= floor(*z);
}

double	fade(double curve)
{
  return (curve * curve * curve * (curve * (curve * 6 - 15) + 10));
}

double	lerp(double curve, double a, double b)
{
  return (a + curve * (b - a));
}

double		grad(int hash, double x, double y, double z)
{
  int		h;
  double	vec1;
  double	vec2;

  h = hash & 15;
  if (h < 8 || h == 12 || h == 13)
    vec1 = x;
  else
    vec1 = y;
  if (h < 4 || h == 12 || h == 13)
    vec2 = y;
  else
    vec2 = z;
  return (((h & 1) == 0 ? vec1 : -vec1) + ((h & 2) == 0 ? vec2 : -vec2));
}

double		get_perlin(double x, double y, double z)
{
  double	vec[3];
  int		c_unit[3];
  int       	coor[6];

  init_noise(c_unit, &x, &y, &z);
  vec[0] = fade(x);
  vec[1] = fade(y);
  vec[2] = fade(z);
  coor[0] = table[c_unit[0]] + c_unit[1];
  coor[1] = table[coor[0]] + c_unit[2];
  coor[2] = table[coor[0] + 1] + c_unit[2];
  coor[3] = table[c_unit[0] + 1] + c_unit[1];
  coor[4] = table[coor[3]] + c_unit[2];
  coor[5] = table[coor[3] + 1] + c_unit[2];
  return (lerp(vec[2], lerp(vec[1], lerp(vec[0], grad(table[coor[1]], x, y, z),
					 grad(table[coor[4]], x - 1, y, z)),
			    lerp(vec[0], grad(table[coor[2]], x, y - 1, z),
				 grad(table[coor[5]], x - 1, y - 1, z))),
	       lerp(vec[1], lerp(vec[0], grad(table[coor[1] + 1], x, y, z - 1),
				 grad(table[coor[4] + 1], x-1, y  , z - 1)),
		    lerp(vec[0], grad(table[coor[2] + 1], x  , y - 1, z - 1),
			 grad(table[coor[5] + 1], x - 1, y - 1, z - 1)))));
}
