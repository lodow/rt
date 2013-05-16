/*
** init_pars.c for init_pars in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu May 16 14:37:50 2013 luc sinet
** Last update Thu May 16 14:40:30 2013 luc sinet
*/

#include "main.h"
#include "pars.h"

void	init_objptr(void (**objptr)(char *line, t_obj *ept, t_text *text))
{
  objptr[0] = &pars_color;
  objptr[1] = &pars_brightness;
  objptr[2] = &pars_texture;
  objptr[3] = &pars_absorbance;
  objptr[4] = &pars_limits;
  objptr[5] = &pars_perturbations;
  objptr[6] = &pars_normal1;
  objptr[7] = &pars_normal2;
  objptr[8] = &pars_normal;
  objptr[9] = &pars_alpha;
  objptr[10] = &pars_refraction;
  objptr[11] = &pars_reflection;
  objptr[12] = &pars_cst;
  objptr[13] = &pars_size;
}
