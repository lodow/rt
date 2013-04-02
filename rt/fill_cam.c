/*
** fill_cam.c for fill_cam in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Apr  1 21:38:56 2013 luc sinet
** Last update Mon Apr  1 22:12:24 2013 luc sinet
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"
#include "pars.h"
#include "get_next_line.h"

void	skip_adds(char *line, int *i)
{
  while (line[*i] == ',' || line[*i] == ';' || line[*i] == ' ')
    ++(*i);
}

void	get_cam_coor(t_cam *cpt, char *line)
{
  int	i;

  i = 0;
  cpt->cx = my_sgetnbr(line, &i);
  skip_adds(line, &i);
  cpt->cy = my_sgetnbr(line, &i);
  skip_adds(line, &i);
  cpt->cz = my_sgetnbr(line, &i);
}

int	get_cam_carac(t_cam *cpt, int fd)
{
  int	i;
  char	*line;

  free((line = get_next_line(fd)));
  while (my_strcmp((line = get_next_line(fd)), "}") != 0)
    {
      i = 0;
      while (line[i] == ' ')
	++i;
      if (my_strncmp(&line[i], "Center = ", 9) == 0)
	get_cam_coor(cpt, &line[i + 9]);
      else
	{
	  my_putstr("Line ", 2);
	  my_putstr(line, 2);
	  return (merror(" is invalid\n", -1));
	}
      free(line);
    }
  return (0);
}

int	fill_cam(t_cam *cpt, char *name)
{
  int	fd;
  char	*line;

  if ((fd = open(name, O_RDONLY)) == -1)
    return (merror("Could open the file", -1));
  while ((line = get_next_line(fd)))
    {
      if (my_strcmp(line, "Cam") == 0 && get_cam_carac(cpt, fd) == -1)
	return (-1);
      free(line);
    }
  close (fd);
  return (0);
}
