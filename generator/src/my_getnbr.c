/*
** my_getnbr.c for my_get_nbr in /home/remi/lem-in/lib
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Tue Jun  4 13:08:22 2013 remi
** Last update Tue Jun  4 13:09:24 2013 remi robert
*/

#include "my_func.h"

int	my_getnbr(char *str)
{
  int	nbr;
  int	i;
  int	j;
  int	pow;

  pow = 1;
  i = 0;
  nbr = 0;
  while ((str[i] == '-') || (str[i] == '+'))
    {
      if (str[i] == '+')
	  i = i + 1;
      pow = -pow;
      i = i + 1;
    }
  while (str[i] >= '0' && str[i] <= '9')
    {
      j = nbr;
      nbr = (nbr * 10) + (str[i] - '0');
      i = i + 1;
      if (((j > nbr) && (pow > 0)) || ((pow < 0) && (j > nbr - 1)))
	return (0);
    }
  return (nbr * pow);
}
