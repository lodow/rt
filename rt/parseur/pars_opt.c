/*
** pars_opt.c for pars_opt in /home/sinet_l//rt/rt/parseur
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue May 21 17:23:06 2013 luc sinet
** Last update Tue May 21 18:02:55 2013 luc sinet
*/

#include "main.h"
#include "pars.h"

void	get_opt_filter(t_opt *opt, char *line, int l)
{
  char	*types[2];
  int	i;
  int	x;

  i = 0;
  x = 0;
  types[0] = "Sepia";
  types[1] = "Grey";
  skip_space(line, &x);
  while (i < 2 && my_strncmp(types[i], &line[x], my_strlen(types[i])) != 0)
    ++i;
  if (i == 2)
    {
      my_putstr("line ", 2);
      my_put_nbr(l, 2);
      my_putstr(" ", 2);
      my_putstr(&line[x], 2);
      my_putstr(" is an invalid filter\n", 2);
    }
  else
    opt->filter = i + 1;
}

void	get_opt_fog(t_opt *opt, char *line, int l)
{
  int	i;

  (void)l;
  i = 0;
  if (my_strncmp(line, "0x", 2) == 0)
    i += 2;
  opt->fog[0] = my_getnbr_base(&line[i], "0123456789ABCDEF");
  while (line[i] != 0 && (line[i] != ','))
    ++i;
  skip_adds(line, &i);
  opt->fog[1] = my_fgetnbr(&line[i]);
}

void		get_gamma_coef(t_opt *opt, char *line, int l)
{
  double	gamma_coef;

  if ((gamma_coef = my_fgetnbr(line)) < 0 || gamma_coef > 10)
    {
      my_putstr("Warning: line ", 2);
      my_put_nbr(l, 2);
      my_putstr(" the gamma coeficient must be between 0 and 10\n", 2);
    }
  opt->gamma = LIMIT(gamma_coef, 0, 10);
}

void		get_aa_coef(t_opt *opt, char *line, int l)
{
  double	aa_coef;

  if ((aa_coef = my_fgetnbr(line)) < 1)
    {
      my_putstr("Warning: line ", 2);
      my_put_nbr(l, 2);
      my_putstr(" the aa coeficient must be superior to 0\n", 2);
    }
  opt->aa = LIMIT(aa_coef, 0, 8192);
}
