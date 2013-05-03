/*
** pars.c for pars in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Mar 11 18:33:58 2013 luc sinet
** Last update Fri May  3 16:42:01 2013 luc sinet
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/main.h"
#include "../include/pars.h"
#include "../include/get_next_line.h"

int	check_shape(char *line, int *accol, int nb_line)
{
  int	i;
  char	*shape[10];

  i = 0;
  init_shapes(shape);
  while (i < 10 && my_strcmp(shape[i], line) != 0)
    i++;
  *accol += T_ACCOL(i);
  if (*accol > 1 || *accol < 0 || (i < 8 && *accol != 0))
    {
      my_putstr("line ", 2);
      my_put_nbr(nb_line, 2);
      return (merror(", file is incorectly formatted\n", -1));
    }
  return (i < 5 ? 1 : (i == 5) ? 2 : (i == 6) ? 3 : (i == 7) ? 4 : 0);
}

int	get_size(char *name, t_pars *opt)
{
  if ((opt->fd = open(name, O_RDONLY)) == -1)
    return (merror("Could open the file\n", -2));
  while ((opt->line = get_next_line(opt->fd)))
    {
      opt->nb_line++;
      if ((opt->rv = check_shape(opt->line, &opt->accol, opt->nb_line)) == -1)
	return (-2);
      if (opt->rv == 1)
	++opt->nb_shape;
      else if (opt->rv == 2)
	++opt->nb_light;
      else if (opt->rv == 3)
	++opt->nb_cam;
      else if (opt->rv == 4)
	++opt->nb_opt;
      free(opt->line);
    }
  close(opt->fd);
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
	    return (merror("Not enough informations specified\n", -1));
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

int		pars(t_rt *rpt, char *fname, t_cam *cpt)
{
  t_pars	opt;
  int		size;

  init_nb_obj(&opt);
  init_cam(cpt);
  get_config_file(&opt, fname);
  int	i;
  for (i=0;opt.file[i];i++)
    printf("%s\n", opt.file[i]);
  if ((size = get_size(fname, &opt)) < 0)
    return (size == -2 ? -2 : merror("Enter at least one shape\n", -1));
  if (opt.nb_cam != 1)
    return (merror("You must have (only / at least) one camera\n", -1));
  if (opt.nb_opt != 1)
    return (merror("You must have one option bloc\n", -1));
  opt.nb_shape += 1;
  opt.nb_light += 1;
  if ((rpt->obj = malloc(sizeof(t_obj) * opt.nb_shape)) == NULL ||
      (rpt->light = malloc(sizeof(t_lig) * opt.nb_light)) == NULL)
    return (merror("Malloc failed\n", -1));
  init_elem(rpt->obj, &opt);
  init_light(rpt->light, &opt);
  if ((fill_tab(&opt, rpt->obj, fname) == -1) ||
      fill_light(&opt, rpt->light, fname) == -1 ||
      fill_cam(cpt, fname) == -1 ||
      fill_opt(rpt, fname) == -1)
    return (-1);
  return (check_size(rpt->obj));
  return (-1);
}
