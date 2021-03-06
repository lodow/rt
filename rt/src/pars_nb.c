/*
** my_getnbr.c for my_getnbr in /home/sinet_l//ratrapage
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sat Oct 20 11:27:34 2012 luc sinet
** Last update Sat Jun  8 18:14:00 2013 luc sinet
*/

#include <stdlib.h>
#include <unistd.h>
#include "str.h"
#include "main.h"

int	my_sgetnbr(char *s1, int *i)
{
  int	nb;
  int	sign;

  nb = 0;
  sign = 1;
  while (s1[*i] == ' ' || s1[*i] == '-' || s1[*i] == '+')
    {
      if (s1[*i] == '-')
        sign = -sign;
      (*i)++;
    }
  while (s1[*i] >= '0' && s1[*i] <= '9')
    {
      if (((nb * 10) / 10) != nb)
        return (0);
      nb = nb * 10 + (s1[*i] - 48);
      (*i)++;
    }
  return (nb * sign);
}

int	my_getnbr(char *s1)
{
  int	nb;
  int	i;
  int	sign;

  nb = 0;
  i = 0;
  sign = 1;
  while (s1[i] == ' ' || s1[i] == '-' || s1[i] == '+')
    {
      if (s1[i] == '-')
        sign = -sign;
      i++;
    }
  while (s1[i] >= '0' && s1[i] <= '9')
    {
      if (((nb * 10) / 10) != nb)
        return (0);
      nb = nb * 10 + (s1[i] - 48);
      i++;
    }
  return (nb * sign);
}

void	my_put_nbr(int nb, int fd)
{
  char	res;

  if (nb == -2147483648)
    {
      my_putstr("-2147483648", fd);
      return ;
    }
  if (nb < 0)
    {
      my_putstr("-", fd);
      nb = -nb;
    }
  if (nb >= 10)
    my_put_nbr(nb / 10, fd);
  res = nb % 10 + 48;
  my_putchar(res, fd);
}
