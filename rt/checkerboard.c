/*
** checkerboard.c for checkerboard in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon May 20 00:00:28 2013 luc sinet
** Last update Mon May 20 13:11:38 2013 luc sinet
*/

#include "main.h"

void		checkerboard_color(double *inter, unsigned char *col, int size)
{
  inter[0] = ABS(inter[0]);
  inter[1] = ABS(inter[1]);
  inter[0] += size / 4;
  inter[1] += size / 4;
  if (((int)inter[0] % size <= size / 2 && (int)inter[1] % size <= size / 2) ||
      ((int)inter[0] % size > size / 2 && (int)inter[1] % size > size / 2))
    {
      col[0] = 0;
      col[1] = 0;
      col[2] = 0;
    }
  else
    {
      col[0] = 255;
      col[1] = 255;
      col[2] = 255;
    }
}
