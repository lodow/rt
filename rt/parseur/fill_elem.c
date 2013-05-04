/*
** fill_elem.c for fill elem in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Mar 11 23:15:31 2013 luc sinet
** Last update Sat May  4 13:20:50 2013 luc sinet
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/main.h"
#include "../include/pars.h"
#include "../include/get_next_line.h"

int	get_args(t_obj *tab, char **file, int *y)
{
  char	*line;
  int	s;

  ++(*y);
  while (my_strcmp(file[*y], "}") != 0)
    {
      line = file[*y];
      s = 0;
      while (line[s] == ' ')
	s++;
      if (my_strncmp("Center = ", &line[s], 9) == 0)
	fill_center(tab, &line[s]);
      else if (my_strncmp("Angle = ", &line[s], 8) == 0)
	fill_angle(tab, &line[s]);
      else if (other_opt(&line[s], tab) == -1)
	return (merror("Unknown argument\n", -1));
      ++(*y);
    }
  return (0);
}

int	fill_shape(char **file, int *y, t_obj *tab, int i)
{
  char	*line;
  char	*shape[5];
  int	x;

  shape[0] = "Sphere";
  shape[1] = "Plan";
  shape[2] = "Cone";
  shape[3] = "Cylinder";
  shape[4] = "Moebius";
  x = 5;
  while (x == 5 && file[*y])
    {
      line = file[*y];
      /* printf("%s\n", line); */
      x = 0;
      while (x < 5 && my_strcmp(shape[x], line) != 0)
	x++;
      ++(*y);
    }
  tab[i].type = x;
  get_args(&tab[i], file, y);
  return (0);
}

int	fill_tab(t_pars *opt, t_obj *tab)
{
  int	y;
  int	i;

  i = 0;
  y = 0;
  while (i < opt->nb_shape)
    {
      if (fill_shape(opt->file, &y, tab, i) == -1)
	return (-1);
      i++;
    }
  return (0);
}
