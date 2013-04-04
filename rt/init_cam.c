/*
** init_cam.c for init_cam in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Apr  1 21:31:16 2013 luc sinet
** Last update Thu Apr  4 16:58:33 2013 Adrien Della Maggiora
*/

#include "main.h"

void	init_cam(t_cam *cpt)
{
  cpt->cx = 0.0;
  cpt->cy = 0.0;
  cpt->cz = 0.0;
  cpt->ccos[0] = 1.0;
  cpt->ccos[1] = 1.0;
  cpt->ccos[2] = 1.0;
  cpt->csin[0] = 0.0;
  cpt->csin[1] = 0.0;
  cpt->csin[2] = 0.0;
}
