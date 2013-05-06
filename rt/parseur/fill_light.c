/*
** fill_light.c for fill_light in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Mar 13 20:12:16 2013 luc sinet
** Last update Sat May  4 13:10:41 2013 luc sinet
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/main.h"
#include "../include/pars.h"
#include "../include/get_next_line.h"
#include "../include/str.h"
#include "../include/nb.h"

void	fill_lcenter(t_lig *ltab, int i, char *line)
{
  int	pl;
  int	x;

  pl = 0;
  x = 0;
  if (!line[pl])
    return ;
  while (x < 3)
    {
      if (line[pl] == ',' || line[pl] == ';')
	return ;
      ltab[i].pos[x] = my_sgetnbr(line, &pl);
      if (line[pl])
	pl++;
      if (!line[pl])
	return ;
      x++;
    }
}

int	get_value(char **tab, int *x, t_lig *ltab, int i)
{
  char	*line;
  int	s;

  while (my_strcmp(tab[*x], "}") != 0)
    {
      line = tab[*x];
      s = 0;
      while (line[s] == ' ')
	s++;
      if (my_strncmp("Center = ", &line[s], 9) == 0)
	fill_lcenter(ltab, i, &line[s + 9]);
      else if (light_carac(&line[s], ltab, i) == -1)
	return (file_error(line, *x, -1));
      ++(*x);
    }
  ltab[i].on = 1;
  return (0);
}

int	fill_light(t_pars *opt, t_lig *ltab)
{
  int	x;
  int	i;

  i = 0;
  x = 0;
  while (i < opt->nb_light)
    {
      while (my_strcmp(opt->file[x], "Light") != 0)
	++x;
      x += 2;
      if (get_value(opt->file, &x, ltab, i) == -1)
	return (-1);
      ++i;
    }
  return (0);
}
