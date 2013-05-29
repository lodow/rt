/*
** fill_elem.c for fill elem in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Mar 11 23:15:31 2013 luc sinet
** Last update Wed May 29 13:29:53 2013 luc sinet
*/

#include "main.h"
#include "pars.h"
#include "model.h"

int	get_args(t_obj *obj, t_pars *opt, int *y)
{
  char	*line;
  int	s;

  ++(*y);
  while (my_strcmp(opt->file[*y], "}") != 0)
    {
      line = opt->file[*y];
      s = 0;
      while (line[s] == ' ')
	++s;
      if (my_strncmp("Center = ", &line[s], 9) == 0)
	fill_center(obj, &line[s + 9]);
      else if (my_strncmp("Angle = ", &line[s], 8) == 0)
	fill_angle(obj, &line[s + 8]);
      else if (other_opt(&line[s], obj, opt->text) == -1)
	return (file_error(line, *y, -1));
       ++(*y);
    }
  return (0);
}

int	fill_shape(t_pars *opt, int *y, t_obj *obj)
{
  char	*shape[12];
  char	*line;
  int	x;

  init_tab_names(shape);
  x = 12;
  while (x == 12 && opt->file[*y])
    {
      line = opt->file[*y];
      x = 0;
      while (x < 12 && my_strcmp(shape[x], line) != 0)
	x++;
      ++(*y);
    }
  obj->type = x;
  return (get_args(obj, opt, y));
}

int	fill_tab(t_pars *opt, t_obj *tab)
{
  int	y;
  int	i;

  i = 0;
  y = 0;
  while (i < opt->nb_shape)
    {
      if (fill_shape(opt, &y, &tab[i]) == -1)
	return (-1);
      i++;
    }
  return (0);
}
