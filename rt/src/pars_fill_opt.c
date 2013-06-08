/*
** init_opt.c for rt in /home/dellam_a/Projet/rt/rt/parseur
**
** Made by Adrien Della Maggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Fri Apr 12 15:50:58 2013 Adrien Della Maggiora
** Last update Sat Jun  8 17:53:19 2013 luc sinet
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"
#include "get_next_line.h"
#include "pars.h"

int		get_opt_carac(t_pars *ppt, t_opt *opt, int *x)
{
  void		(*optptr[NB_OPT])(t_opt *opt, char *line, int l);
  int		i[2];
  char		*line;
  char		*tabopt[NB_OPT];

  (*x) += 2;
  init_opt_carac(tabopt);
  init_opt_pt(optptr);
  while (my_strcmp(ppt->file[*x], "}") != 0)
    {
      line = ppt->file[*x];
      i[0] = 0;
      while (line[i[0]] == ' ')
        ++i[0];
      i[1] = 0;
      while (i[1] < NB_OPT && my_strncmp(tabopt[i[1]], &line[i[0]],
					 my_strlen(tabopt[i[1]])) != 0)
	++i[1];
      if (i[1] < NB_OPT)
	optptr[i[1]](opt, &line[my_strlen(tabopt[i[1]]) + i[0]], *x);
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
