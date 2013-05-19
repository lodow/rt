/*
** modif_cam.c for modif_cam in /tmp/rt/rt
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Thu Mar 21 23:31:20 2013 etienne debas
** Last update Sun May 19 20:11:45 2013 luc sinet
*/

#include "main.h"
#include "light.h"

void		copy_tab(void *tab, void *ctab, int size)
{
  double	*ptr1;
  double	*ptr2;
  int		i;

  ptr1 = tab;
  ptr2 = ctab;
  i = 0;
  while (i < size)
    {
      ptr2[i] = ptr1[i];
      ++i;
    }
}

void	get_impact(double *imp, double *cam, double k, double *vec)
{
  imp[0] = cam[0] + k * vec[0];
  imp[1] = cam[1] + k * vec[1];
  imp[2] = cam[2] + k * vec[2];
}

void		modif_cam(double *c_pos, double *o_pos)
{
  c_pos[0] -= o_pos[0];
  c_pos[1] -= o_pos[1];
  c_pos[2] -= o_pos[2];
}

void	rotate(double *p, double *cosin, double *sinus, char opt)
{
  if (opt == 0)
    {
      rotate_x(p, cosin[0], sinus[0]);
      rotate_y(p, cosin[1], sinus[1]);
      rotate_z(p, cosin[2], sinus[2]);
    }
  else
    {
      rotate_z(p, cosin[2], sinus[2]);
      rotate_y(p, cosin[1], sinus[1]);
      rotate_x(p, cosin[0], sinus[0]);
    }
}
