/*
** fill_elem.c for fill elem in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Mar 11 23:15:31 2013 luc sinet
** Last update Mon May  6 10:37:15 2013 Adrien
*/

#include "../include/main.h"
#include "../include/pars.h"

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
	return (file_error(line, *y, -1));
      ++(*y);
    }
  return (0);
}

int	fill_shape(char **file, int *y, t_obj *tab, int i)
{
  char	*shape[10];
  char	*line;
  int	x;

  shape[0] = "Sphere";
  shape[1] = "Plan";
  shape[2] = "Cone";
  shape[3] = "Cylinder";
  shape[4] = "Circle";
  shape[5] = "Square";
  shape[6] = "Triangle";
  shape[7] = "Paraboloide";
  shape[8] = "Hyperboloide";
  shape[9] = "Moebius";
  x = 10;
  while (x == 10 && file[*y])
    {
      line = file[*y];
      x = 0;
      while (x < 10 && my_strcmp(shape[x], line) != 0)
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
