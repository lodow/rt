/*
** pars.c for pars in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Mar 11 18:33:58 2013 luc sinet
** Last update Thu May  9 15:28:32 2013 luc sinet
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"
#include "pars.h"
#include "get_next_line.h"

int	check_shape(char *line, int *accol, int nb_line)
{
  int	i;
  char	*shape[16];

  i = 0;
  init_shapes(shape);
  while (i < 16 && my_strcmp(shape[i], line) != 0)
    i++;
  *accol += T_ACCOL(i);
  if (*accol > 1 || *accol < 0 || (i < 14 && *accol != 0))
    {
      my_putstr("line ", 2);
      my_put_nbr(nb_line, 2);
      return (merror(", file is incorectly formatted\n", -1));
    }
  return (i < 10 ? 1 : (i == 11) ? 2 : (i == 12) ? 3 : (i == 13) ? 4 : 0);
}

int	get_size(t_pars *opt)
{
  int	i;

  i = 0;
  while (opt->file[i])
    {
      if ((opt->rv = check_shape(opt->file[i], &opt->accol, i)) == -1)
	return (-2);
      if (opt->rv == 1)
	++opt->nb_shape;
      else if (opt->rv == 2)
	++opt->nb_light;
      else if (opt->rv == 3)
	++opt->nb_cam;
      else if (opt->rv == 4)
	++opt->nb_opt;
      ++i;
    }
  return ((opt->nb_shape == 0 || opt->accol != 0) ? -1 : opt->nb_shape + 1);
}

int	check_size(t_obj *tab)
{
  int	i;
  int	obj;

  obj = 0;
  while (tab[obj].type != -1)
    {
      i = 0;
      while (i < 3)
	{
	  if (tab[obj].angle[i] == IVAL || tab[obj].pos[i] == IVAL)
	    return (merror("Not enough informations specified\n"
			   "Missing position or angle information\n", -1));
	  ++i;
	}
      if (tab[obj].type == 2 && tab[obj].angle[3] == IVAL)
	return (merror("Missing angle info for the Cone\n", -1));
      if (tab[obj].type != 1 && tab[obj].type == IVAL)
	return (merror("Missing size's information\n", -1));
      obj++;
    }
  return (0);
}

int		check_blocks(t_pars *opt)
{
  if (opt->nb_shape == 0)
    return (merror("Enter at least one shape\n", -1));
  if (opt->nb_cam != 1)
    return (merror("You must have (only / at least) one camera\n", -1));
  if (opt->nb_opt != 1)
    return (merror("You must have one option bloc\n", -1));
  return (0);
}

int		pars(t_rt *rpt, char *fname, t_cam *cpt)
{
  t_pars	opt;

  init_nb_obj(&opt);
  init_cam(cpt);
  if (get_config_file(&opt, fname) < 0)
    return (-1);
  if (get_size(&opt) < 0)
    return (-2);
  check_blocks(&opt);
  if ((rpt->obj = malloc(sizeof(t_obj) * (opt.nb_shape + 1))) == NULL ||
      (rpt->light = malloc(sizeof(t_lig) * (opt.nb_light + 1))) == NULL)
    return (merror("Malloc failed\n", -1));
  init_elem(rpt->obj, &opt);
  init_light(rpt->light, &opt);
  if ((fill_tab(&opt, rpt->obj) == -1) ||
      fill_light(&opt, rpt->light) == -1 ||
      fill_cam(&opt, cpt) == -1 ||
      fill_opt(&opt, rpt) == -1)
    return (-1);
  fill_model(&opt, rpt->obj);
  return (check_size(rpt->obj));
}
