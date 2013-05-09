/*
** fill_model.c for fill_model in /home/sinet_l//rt/rt/parseur
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu May  9 13:47:30 2013 luc sinet
** Last update Thu May  9 14:14:36 2013 luc sinet
*/

int	fill_model_struct(t_pars *opt, t_obj *tab, int *i)
{
  t_obj	model;

  ++(*i);
  if (get_args(&model, opt->file, i) == -1)
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
	fill_model_struct(opt, tab, &i);
      ++i;
    }
}
