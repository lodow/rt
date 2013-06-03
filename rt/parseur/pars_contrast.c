/*
** pars_contrast.c for pars_contrast in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun Jun  2 16:52:28 2013 luc sinet
** Last update Sun Jun  2 16:54:17 2013 luc sinet
*/

#include "main.h"
#include "pars.h"

void   	get_contrast(t_opt *opt, char *line, int l)
{
  (void)l;
  opt->contrast = my_fgetnbr(line);
}
