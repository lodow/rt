/*
** init_opt.c for rt in /home/dellam_a/Projet/rt/rt/parseur
**
** Made by Adrien Della Maggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Fri Apr 12 15:50:58 2013 Adrien Della Maggiora
** Last update Sat May  4 11:58:20 2013 luc sinet
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/main.h"
#include "../include/get_next_line.h"
#include "../include/pars.h"

void	init_opt(t_opt *opt)
{
  opt->aa = 1;
  opt->fog[0] = 0x000000;
  opt->fog[1] = -1;
}

void	get_opt_fog(t_opt *opt, char *line)
{
  int	i;

  i = 0;
  if (my_strncmp(line, "0x", 2) == 0)
    i += 2;
  opt->fog[0] = my_getnbr_base(&line[i], "0123456789ABCDEF");
  while (line[i] != 0 && (line[i] != ','))
    ++i;
  skip_adds(line, &i);
  opt->fog[1] = my_fgetnbr(&line[i]);
}

int	get_opt_carac(t_pars *ppt, t_opt *opt, int *x)
{
  int	i;
  char	*line;

  (*x) += 2;
  while (my_strcmp(ppt->file[*x], "}") != 0)
    {
      line = ppt->file[*x];
      i = 0;
      while (line[i] == ' ')
        ++i;
      if (my_strncmp(&line[i], "AA = ", 5) == 0)
	opt->aa = my_getnbr(&line[i + 5]);
      else if (my_strncmp(&line[i], "FOG = ", 6) == 0
	       && my_strlen(&line[i]) > 11)
	get_opt_fog(opt, &line[i + 6]);
      else
	return (file_error(line, *x, -1));
      ++(*x);
    }
  return (0);
}

int	fill_opt(t_pars *opt, t_rt *rpt)
{
  int	i;

  i = 0;
  init_opt(rpt->opt);
  while (opt->file[i])
    {
      if (my_strcmp(opt->file[i], "Option") == 0 &&
	  get_opt_carac(opt, rpt->opt, &i) == -1)
	return (-1);
      ++i;
    }
  return (0);
}
