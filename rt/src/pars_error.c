/*
** error.c for error in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Feb 25 11:02:44 2013 luc sinet
** Last update Thu May  9 10:27:30 2013 Adrien Della Maggiora
*/

#include "main.h"
#include "pars.h"
#include "str.h"

int	merror(char *error, int val)
{
  my_putstr(error, 2);
  return (val);
}

void	*merrorptr(char *error, void *val)
{
  my_putstr(error, 2);
  return (val);
}

int	file_error(char *line, int lnb, int ret)
{
  int	i;

  i = 0;
  skip_adds(line, &i);
  my_putstr("line ", 2);
  my_put_nbr(lnb + 1, 2);
  my_putstr(": \"", 2);
  my_putstr(&line[i], 2);
  my_putstr("\" is invalid\n", 2);
  return (ret);
}
