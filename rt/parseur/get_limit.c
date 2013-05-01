/*
** get_limit.c for get_limit in /home/sinet_l//rt/rt/parseur
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sat Apr 13 16:07:03 2013 luc sinet
** Last update Mon Apr 29 18:49:35 2013 luc sinet
*/

#include "../include/main.h"
#include "../include/pars.h"
#include "../include/str.h"
#include "../include/nb.h"

void	skip_fnumber(char *line, int *i)
{
  while ((line[*i] >= '0' && line[*i] <= '9') || line[*i] == '.' ||
	 line[*i] == '-' || line[*i] == '+')
    ++(*i);
  if (line[*i] == ',')
    ++(*i);
}

int	fill_limit_value(char *line, int *i, double *limit, int type)
{
  limit[0] = type;
  ++(*i);
  if (my_strncmp(":(", &line[*i], 2) != 0)
    {
      my_putstr("Bad format: ", 2);
      return (merror(&line[*i], -1));
    }
  *i += 2;
  while (line[*i] && line[*i] != ')')
    {
      if (my_strncmp("p:", &line[*i], 2) == 0)
	limit[2] = my_fgetnbr(&line[*i + 2]);
      else if (my_strncmp("n:", &line[*i], 2) == 0)
	limit[1] = -1.0 * my_fgetnbr(&line[*i + 2]);
      else
	{
	  my_putstr(&line[*i], 2);
	  return (merror(" is an invalid option\n", -1));
	}
      *i += 2;
      skip_fnumber(line, i);
    }
  return ((!line[*i]) ? merror("Missing ')'\n", -1) : 0);
}

void	fill_limits(char *line, double *limit)
{
  int	i;

  i = 0;
  while (line[i])
    {
      if (line[i] == 'x' || line[i] == 'y' || line[i] == 'z')
	{
	  if (fill_limit_value(line, &i, &limit[3 * (line[i] - 'x')],
			       line[i] - 'x' + 1) == -1)
	    return ;
	  ++i;
	}
      else
	{
	  write(2, &line[i], 1);
	  my_putstr(" is invalid must be (x,y,z)\n", 2);
	  return ;
	}
      skip_adds(line, &i);
    }
}
