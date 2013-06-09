/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "main.h"
#include "pars.h"

int	check_for_opt(char *str, char **opt)
{
  int	i;
  int	fopt;

  fopt = -1;
  i = 0;
  while (opt[i] != NULL)
    {
      if (!my_strncmp(str, opt[i], my_strlen(opt[i])))
        fopt = i;
      i++;
    }
  return (fopt);
}

void	parse_win_size(char *str, t_rt *rpt)
{
  int	i;
  char	*height;
  int	nheight;
  int	nwidht;

  i = 0;
  height = "0";
  if (str == NULL)
    return ;
  while ((str[i] != 'x') && (str[i] != '\0'))
    i++;
  if (str[i] != '\0')
    height = &(str[i + 1]);
  str[i] = '\0';
  nwidht = my_getnbr(str);
  nheight = my_getnbr(height);
  if ((nwidht > 1) && (nheight > 1) && (nwidht < 4096) && (nheight < 4096))
    {
      rpt->ppt->imgwidth = nwidht;
      rpt->ppt->imgheight = nheight;
    }
  else
    my_putstr("Windows size wrong\\too large, using default values\n", 2);
}

int	parse_argv(char **av, t_rt *rpt, char **filename)
{
  int	i;
  char	*opt[2];
  int	aopt;

  opt[0] = "-s";
  opt[1] = NULL;
  i = 0;
  (*filename) = NULL;
  rpt->ppt->imgwidth = 1650;
  rpt->ppt->imgheight = 1050;
  while (av[i] != NULL)
    {
      if ((aopt = check_for_opt(av[i], opt)) != -1)
        {
          parse_win_size(av[i + 1], rpt);
          if (av[i + 1] != NULL)
            i++;
        }
      else
        (*filename) = av[i];
      i++;
    }
  return (0);
}
