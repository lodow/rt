/*
** convert_base.c for convert in /home/sinet_l//bistro
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun Nov 11 17:23:02 2012 luc sinet
** Last update Fri Mar 15 01:54:33 2013 luc sinet
*/

#include "str.h"

int	my_power_rec(int nb, int power)
{
  if (power == 0)
    return (1);
  else if (power > 0)
    return (nb * my_power_rec(nb, power - 1));
  else
    return (0);
}

int	my_getnbr_base(char *calc, char *base)
{
  int	pic;
  int	lenb;
  int	lenc;
  int	pib;
  int	res;

  pic = 0;
  res = 0;
  lenb = my_strlen(base);
  lenc = my_strlen(calc) - 1;
  while (calc[pic])
    {
      if (res * 10 / 10 != res)
	return (0);
      pib = 0;
      while (base[pib] && calc[lenc - pic] != base[pib])
	++pib;
      res += pib * my_power_rec(lenb, pic);
      ++pic;
    }
  return (res);
}
