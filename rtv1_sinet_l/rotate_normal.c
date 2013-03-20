/*
** rotate_normal.c for rotate_normal in /home/sinet_l//rtv1-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun Mar 17 17:32:00 2013 luc sinet
** Last update Sun Mar 17 19:12:32 2013 luc sinet
*/

#include <math.h>
#include "main.h"
#include "lightning.h"

void		rotate_vec(t_elem *ept, double *vt)
{
  double        xcos;
  double        ysin;

  xcos = cosf(RAD(-ept->angle[0]));
  ysin = sinf(RAD(-ept->angle[0]));
  vt[1] = vt[1] * xcos - vt[2] * ysin;
  vt[2] = vt[1] * ysin + vt[2] * xcos;
  xcos = cosf(RAD(-ept->angle[1]));
  ysin = sinf(RAD(-ept->angle[1]));
  vt[0] = vt[0] * xcos - vt[2] * ysin;
  vt[2] = vt[0] * -ysin + vt[2] * xcos;
  xcos = cosf(RAD(-ept->angle[2]));
  ysin = sinf(RAD(-ept->angle[2]));
  vt[0] = vt[0] * xcos + vt[1] * -ysin;
  vt[1] = vt[0] * ysin + vt[1] * xcos;
}
