/*
** fill_model.c for fill_model in /home/sinet_l//rt/rt/parseur
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu May  9 13:47:30 2013 luc sinet
** Last update Thu May  9 15:30:31 2013 luc sinet
*/

#include "../include/main.h"
#include "../include/pars.h"

int	get_model_name(char **file, char *file_name, int i)
{
  int	x;

  while (my_strcmp("}", file[i]) != 0 &&
	 my_strncmp("Name = ", file[i], 7) != 0)
    ++i;
  if (file[i][0] == '}')
    return (-1);
  else
    {
      x = 0;
      skip_adds(&file[i][7], &x);
      file_name = &file[i][7 + x];
    }
  return (0);
}

int	fill_model_struct(t_pars *opt, t_obj *tab, int *i)
{
  t_obj	modelc;
  t_obj	model;
  char	*file_name;

  ++(*i);
  if (get_model_name(opt->file, file_name, *i) == -1)
    return (merror("Missing model's name\n", -1));
  printf("%s\n", file_name);
  if (get_args(&modelc, opt->file, &i) == -1)
    return (-1);
  return (0);
}

int	fill_model(t_pars *opt, t_obj *tab)
{
  int	i;

  i = 0;
  while (opt->file[i])
    {
      if (my_strcmp("Model", opt->file[i]) == 0)
	if (fill_model_struct(opt, tab, &i) == -1)
	  return (-1);
      ++i;
    }
  return (0);
}
