/*
** pars_seed.c for pars_seed in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri May 31 12:54:07 2013 luc sinet
** Last update Fri May 31 13:06:16 2013 luc sinet
*/

#include "main.h"
#include "pars.h"

void	get_seed(t_opt *opt, char *line, int l)
{
  (void)l;
  if (my_strncmp("Random", line, 6) == 0)
    opt->seed[0] = 2;
  else
    {
      opt->seed[0] = 1;
      opt->seed[1] = my_getnbr(line);
    }
}
