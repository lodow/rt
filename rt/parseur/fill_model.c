/*
** fill_model.c for fill_model in /home/sinet_l//rt/rt/parseur
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu May  9 13:47:30 2013 luc sinet
** Last update Thu May  9 16:48:01 2013 luc sinet
*/

#include "main.h"
#include "pars.h"
#include "model.h"

void	skip_space(char *line, int *i)
{
  while (line[*i] == ' ')
    ++(*i);
}

char	*get_model_name(char **file, int i)
{
  int	x;
  char	hit;
  char	*file_name;

  hit = 0;
  while (hit == 0)
    {
      x = 0;
      skip_space(file[i], &x);
      if (my_strcmp("}", &file[i][x]) == 0 ||
	  my_strncmp("Name = ", &file[i][x], 7) == 0)
	hit = 1;
      if (hit == 0)
	++i;
    }
  if (file[i][0] == '}')
    return (NULL);
  else if ((file_name = my_strdup(&file[i][7 + x])) == NULL)
    return (NULL);
  return (file_name);
}

int		fill_model_struct(t_pars *opt, t_obj *tab, int *i)
{
  t_obj		model;
  t_model	*obj;
  char		*file_name;

  ++(*i);
  if ((file_name = get_model_name(opt->file, *i)) == NULL)
    return (merror("Missing model's name\n", -1));
  init_single_elem(&model);
  if (get_args(&model, opt->file, i) == -1)
    return (-1);
  if ((obj = get_file_obj_model(file_name)) == NULL)
    return (merror("Failed to get the model's informations\n", -1));
  free(file_name);
  raw_model_t_obj(&tab, obj, &model);
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
