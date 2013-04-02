/*
** fill_light.c for fill_light in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Mar 13 20:12:16 2013 luc sinet
** Last update Tue Apr  2 14:47:46 2013 luc sinet
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"
#include "pars.h"
#include "get_next_line.h"
#include "str.h"
#include "nb.h"

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

int	get_value(t_lig *ltab, int i, int fd)
{
  char	*line;
  int	s;

  while ((line = get_next_line(fd)) && my_strcmp(line, "}") != 0)
    {
      s = 0;
      while (line[s] == ' ')
	s++;
      if (my_strncmp("Center = ", &line[s], 9) == 0)
	fill_lcenter(ltab, i, &line[s + 9]);
      else if (light_carac(&line[s], ltab, i) == -1)
	return (merror("Unknown argument\n", -1));
      free(line);
    }
  ltab[i].on = 1;
  free(line);
  return (0);
}

int	get_linfo(t_lig *ltab, int i, char *line, int fd)
{
  int	rv;

  rv = 1;
  while (rv != 0)
    {
      if ((line = get_next_line(fd)) == NULL)
	return (0);
      rv = my_strcmp(line, "Light");
      free(line);
    }
  free((line = get_next_line(fd)));
  return (get_value(ltab, i, fd));
}

int	fill_light(t_pars *opt, t_lig *ltab, char *name)
{
  int	fd;
  int	i;

  if ((fd = open(name, O_RDONLY)) == -1)
    return (merror("Could open the file\n", -1));
  i = 0;
  while (i < opt->nb_light)
    {
      if (get_linfo(ltab, i, "abc" , fd) == -1)
	{
	  close(fd);
	  return (-1);
	}
      i++;
    }
  close(fd);
  return (0);
}
