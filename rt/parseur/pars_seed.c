/*
** pars_seed.c for pars_seed in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri May 31 12:54:07 2013 luc sinet
** Last update Fri May 31 18:29:48 2013 luc sinet
*/

#include <stdlib.h>
#include <time.h>
#include "main.h"
#include "pars.h"

int	seed_generator(char *str)
{
  int	i;
  int	res;

  i = 0;
  res = 0;
  while (str[i])
    {
      if (res * 10 / 10 != res)
	return (0);
      res *= 1.5;
      res += ABS(str[i]);
      ++i;
    }
  return (res);
}

void	get_seed(t_opt *opt, char *line, int l)
{
  (void)l;
  if (my_strncmp("Random", line, 6) == 0)
    srand(time(NULL));
  else
    srand(seed_generator(line));
}
