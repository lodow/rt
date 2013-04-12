/*
** normals.c for normals in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun Mar 31 13:20:23 2013 luc sinet
** Last update Fri Apr 12 14:41:37 2013 Adrien Della Maggiora
*/

#include <math.h>
#include "include/main.h"
#include "include/light.h"

void	assign_normal1(t_lco *lpt, int type)
{
  if (type == 0)
    {
      lpt->nvec[0] = lpt->obj_coor[0];
      lpt->nvec[1] = lpt->obj_coor[1];
      lpt->nvec[2] = lpt->obj_coor[2];
      lpt->nvec[1] = lpt->nvec[1] + cos(lpt->obj_coor[1] / 1.0) * (vec_norme(lpt->nvec) / 1.0);
    }
  else if (type == 1)
    {
      lpt->nvec[0] = 0;
      lpt->nvec[1] = 0;
      lpt->nvec[2] = 100;
    }
}

void	assign_normal2(t_lco *lpt, int type)
{
  if (type == 2)
    {
      lpt->nvec[0] = lpt->obj_coor[0];
      lpt->nvec[1] = lpt->obj_coor[1];
      lpt->nvec[2] = -0.6 * lpt->obj_coor[2];
    }
  else if (type == 3)
    {
      lpt->nvec[0] = lpt->obj_coor[0];
      lpt->nvec[1] = lpt->obj_coor[1];
      lpt->nvec[2] = 0;
    }
}
