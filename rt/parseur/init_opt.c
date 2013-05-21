/*
** init_opt.c for init_opt in /home/sinet_l//rt/rt/parseur
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue May 21 16:49:47 2013 luc sinet
** Last update Tue May 21 17:52:04 2013 luc sinet
*/

#include "main.h"
#include "pars.h"

void	init_opt(t_opt *opt)
{
  opt->aa = 1;
  opt->fog[0] = 0x000000;
  opt->fog[1] = -1;
  opt->filter = 0;
  opt->gamma = -1;
}

void	init_opt_carac(char **tab)
{
  tab[0] = "Filter = ";
  tab[1] = "Fog = ";
  tab[2] = "AA = ";
  tab[3] = "Gamma = ";
}

void	init_opt_pt(void (**fptr)(t_opt *opt, char *line, int l))
{
  fptr[0] = &get_opt_filter;
  fptr[1] = &get_opt_fog;
  fptr[2] = &get_aa_coef;
  fptr[3] = &get_gamma_coef;
}
