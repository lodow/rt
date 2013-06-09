/*
** init_texture_surface.c for init_texture_surface in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sat Jun  8 18:30:55 2013 luc sinet
** Last update Sat Jun  8 18:36:02 2013 luc sinet
*/

#include "main.h"
#include "light.h"
#include "bmp_loader.h"
#include "change_color.h"

void	init_texture_surface(t_rt *rpt, t_obj *obj, double *vcam)
{
  copy_tab(rpt->vpt->vec, vcam, 3);
  copy_tab(rpt->cpt->pos, &vcam[3], 3);
  modif_cam(&vcam[3], obj->pos);
  rotate(&vcam[3], obj->apt->ocos, obj->apt->osin, 0);
  rotate(vcam, obj->apt->ocos, obj->apt->osin, 0);
}
