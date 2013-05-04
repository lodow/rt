/*
** error.c for error in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Feb 25 11:02:44 2013 luc sinet
** Last update Sat May  4 11:20:13 2013 luc sinet
*/

#include "../include/main.h"
#include "../include/str.h"

int	merror(char *error, int val)
{
  my_putstr(error, 2);
  return (val);
}

int	file_error(char *line, int lnb, int ret)
{
  my_putstr("l ", 2);
  my_put_nbr(lnb, 2);
  my_putstr(" :", 2);
  my_putstr(line, 2);
  my_putstr("\nis invalid\n", 2);
  return (ret);
}
