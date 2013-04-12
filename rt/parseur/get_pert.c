/*
** get_pert.c for pert in /home/sinet_l//rt/rt/parseur
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri Apr 12 16:59:39 2013 luc sinet
** Last update Fri Apr 12 19:12:35 2013 luc sinet
*/

#include "../include/main.h"
#include "../include/pars.h"
#include "../include/nb.h"

void	check_space_arg(char *line, double *pert, int *i)
{
  int	x;

  pert[0] = 1;
  if (line[0] == ':')
    pert[1] = my_fgetnbr(&line[1]);
  else
    return ;
  (*i) += 2;
  x = 1;
  while (line[x] >= '0' && line[x] <= '9')
    {
      ++(*i);
      ++x;
    }
}

void	fill_pert(char *line, double *pert)
{
  int	i;
  int	x;

  i = 0;
  x = 0;
  i = 0;
  while (line[i] && x < 3)
    {
      skip_adds(line, &i);
      if (line[i] == 'x' || line[i] == 'y' || line[i] == 'z')
	check_space_arg(&line[i + 1], &pert[2 * (line[i] - 'x')], &i);
      else
	return ;
      ++x;
      skip_adds(line, &i);
    }
}
