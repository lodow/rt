/*
** perlin3.c for rt in /tmp
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Sun May 19 18:23:43 2013 etienne debas
** Last update Thu May 30 17:39:00 2013 luc sinet
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"

static int table[512];
static int permutation[256] = {-1};

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

void	init_permutation()
{
  int	i;

  i = 0;
  while (i < 256)
    permutation[i++] = rand() % 256;
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

  if (permutation[0] == -1)
    init_permutation();
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
