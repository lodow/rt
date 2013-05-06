/*
** error.c for error in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Feb 25 11:02:44 2013 luc sinet
** Last update Sat May  4 20:35:25 2013 luc sinet
*/

#include "../include/main.h"
#include "../include/pars.h"
#include "../include/str.h"

int	merror(char *error, int val)
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
