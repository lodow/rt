/*
** pars_color.c for pars_color.c in /home/sinet_l//rt/rt/parseur
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu May 16 11:20:43 2013 luc sinet
** Last update Sat May 18 23:55:01 2013 luc sinet
*/

#include "main.h"
#include "pars.h"

void	pars_color(char *line, t_obj *ept, t_text *text)
{
  (void)text;
  get_color(line, ept->color);
}

void	pars_brightness(char *line, t_obj *ept, t_text *text)
{
  (void)text;
  ept->bright = LIMIT(my_fgetnbr(line), 0, 1);
}

void	pars_texture(char *line, t_obj *ept, t_text *text)
{
  link_text(ept, line, text);
}
