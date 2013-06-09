/*
** pars_contrast.c for pars_contrast in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun Jun  2 16:52:28 2013 luc sinet
** Last update Sun Jun  9 03:23:39 2013 luc sinet
*/

#include "main.h"
#include "pars.h"

void	get_contrast(t_opt *opt, char *line, UNUSED int l)
{
  opt->contrast = my_fgetnbr(line);
  if (opt->contrast < 0)
    {
      my_putstr("Warning: line ", 2);
      my_put_nbr(l, 2);
      my_putstr("value must be > 0\n", 2);
    }
  opt->contrast = LIMIT(opt->contrast, 0 , 500);
}

void	get_saturation(t_opt *opt, char *line, int l)
{
  opt->saturation = my_fgetnbr(line);
  if (opt->saturation < 0)
    {
      my_putstr("Warning: line ", 2);
      my_put_nbr(l, 2);
      my_putstr("value must be > 0\n", 2);
    }
  opt->saturation = LIMIT(opt->saturation, 0, 500);
}
