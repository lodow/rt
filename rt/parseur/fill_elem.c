/*
** fill_elem.c for fill elem in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Mar 11 23:15:31 2013 luc sinet
** Last update Fri Apr 12 17:35:56 2013 luc sinet
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/main.h"
#include "../include/pars.h"
#include "../include/get_next_line.h"

int	get_args(t_obj *tab, int i, int shape, int fd)
{
  char	*line;
  int	s;

  tab[i].type = shape;
  while ((line = get_next_line(fd)) && my_strcmp(line, "}") != 0)
    {
      s = 0;
      while (line[s] == ' ')
	s++;
      if (my_strncmp("Center = ", &line[s], 9) == 0)
	fill_center(&tab[i], &line[s]);
      else if (my_strncmp("Angle = ", &line[s], 8) == 0)
	fill_angle(&tab[i], &line[s]);
      else if (other_opt(&line[s], &tab[i]) == -1)
	return (merror("Unknown argument\n", -1));
      free(line);
    }
  free(line);
  return (0);
}

int	fill_shape(t_obj *tab, int i, char *line, int fd)
{
  char	*shape[4];
  int	x;

  shape[0] = "Sphere";
  shape[1] = "Plan";
  shape[2] = "Cone";
  shape[3] = "Cylinder";
  x = 4;
  while (x == 4)
    {
      if ((line = get_next_line(fd)) == NULL)
	return (0);
      x = 0;
      while (x < 4 && my_strcmp(shape[x], line) != 0)
	x++;
      free(line);
  }
  free((line = get_next_line(fd)));
  get_args(tab, i, x, fd);
  return (0);
}

int	fill_tab(t_pars *opt, t_obj *tab, char *name)
{
  int	fd;
  int	i;

  if ((fd = open(name, O_RDONLY)) == -1)
    return (merror("Couldn't open the file", -1));
  i = 0;
  while (i < opt->nb_shape)
    {
      if (fill_shape(tab, i, "abc", fd) == -1)
	{
	  close(fd);
	  return (-1);
	}
       i++;
    }
  close (fd);
  return (0);
}
