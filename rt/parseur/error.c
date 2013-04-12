/*
** error.c for error in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Feb 25 11:02:44 2013 luc sinet
** Last update Fri Apr 12 14:52:06 2013 Adrien Della Maggiora
*/

#include "../include/main.h"
#include "../include/str.h"

int	merror(char *error, int val)
{
  my_putstr(error, 2);
  return (val);
}
