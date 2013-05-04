/*
** fill_cam.c for fill_cam in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Apr  1 21:38:56 2013 luc sinet
** Last update Sat May  4 20:34:07 2013 luc sinet
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include "../include/main.h"
#include "../include/pars.h"
#include "../include/get_next_line.h"

void	skip_adds(char *line, int *i)
{
  while (line[*i] == ',' || line[*i] == ';' || line[*i] == ' ')
    ++(*i);
}

void		get_cam_rot(t_cam *cpt, char *line)
{
  int		i;
  double	angle[3];

  i = 0;
  angle[0] = my_sgetnbr(line, &i);
  skip_adds(line, &i);
  angle[1] = my_sgetnbr(line, &i);
  skip_adds(line, &i);
  angle[2] = my_sgetnbr(line, &i);
  cpt->ccos[0] = cos(angle[0] * M_PI / 180);
  cpt->ccos[1] = cos(angle[1] * M_PI / 180);
  cpt->ccos[2] = cos(angle[2] * M_PI / 180);
  cpt->csin[0] = sin(angle[0] * M_PI / 180);
  cpt->csin[1] = sin(angle[1] * M_PI / 180);
  cpt->csin[2] = sin(angle[2] * M_PI / 180);
}

void	get_cam_coor(t_cam *cpt, char *line)
{
  int	i;

  i = 0;
  cpt->pos[0] = my_sgetnbr(line, &i);
  skip_adds(line, &i);
  cpt->pos[1] = my_sgetnbr(line, &i);
  skip_adds(line, &i);
  cpt->pos[2] = my_sgetnbr(line, &i);
}

int	get_cam_carac(t_pars *opt, t_cam *cpt, int *i)
{
  int	x;
  char	*line;

  (*i) += 2;
  while (opt->file[*i] && my_strcmp(opt->file[*i], "}") != 0)
    {
      line = opt->file[*i];
      x = 0;
      while (line[x] == ' ')
	++x;
      if (my_strncmp(&line[x], "Center = ", 9) == 0)
	get_cam_coor(cpt, &line[x + 9]);
      else if (my_strncmp(&line[x], "Angle = ", 8) == 0)
	get_cam_rot(cpt, &line[x + 8]);
      else
	return (file_error(line, *i, -1));
      ++(*i);
    }
  return (0);
}

int	fill_cam(t_pars *opt, t_cam *cpt)
{
  int	i;

  i = 0;
  while (opt->file[i])
    {
      if (my_strcmp(opt->file[i], "Cam") == 0 &&
	  get_cam_carac(opt, cpt, &i) == -1)
	return (-1);
      ++i;
    }
  return (0);
}
