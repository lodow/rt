/*
** my_getnbr.c for my_getnbr.c in /home/dellam_a//Jour_11/do-op
**
** Made by adrien dellamaggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Mon Oct 22 11:11:43 2012 adrien dellamaggiora
** Last update Tue Mar 12 11:07:34 2013 Adrien
*/

#include "include.h"

char	*my_strcpyn(char *dest, char *src, int nb, int begin)
{
  int	i;

  i = 0;
  while (src[begin] != '\0' && nb > 0)
    {
      dest[i] = src[begin];
      i = i + 1;
      begin = begin + 1;
      nb = nb - 1;
    }
  dest[i] = 0;
  return (dest);
}

char	*findnbr(char *str)
{
  int	i;
  int	j;
  char	*nbr;

  nbr = 0;
  j = 0;
  while (str[j] == '+' || str[j] == '-')
    j++;
  i = 0;
  while (str[j] >= '0' && str[j] <= '9')
    {
      i = i + 1;
      j = j + 1;
    }
  if (i > 0)
    {
      if ((nbr = malloc(i + 1)) == NULL)
	exit(0);
      nbr = my_strcpyn(nbr, str, i, j - i);
    }
  return (nbr);
}

int	signenbr(char *nbr)
{
  int	i;
  int	signe;

  i = 0;
  signe = 0;
  while (nbr[i] != '\0' && nbr[i] == '-')
    {
      if (nbr[i] == '-')
	signe = signe + 1;
      i = i + 1;
    }
  if (signe % 2 == 0)
    return (0);
  else
    return (1);
}

int	transformnbr(char *nbr)
{
  int   i;
  int   power;
  int   base10;

  base10 = 0;
  power = 0;
  i = my_strlen(nbr) - 1;
  while (i >= 0)
    {
      base10 = base10 + ((nbr[i] - 48) * pow(10, power));
      power = power + 1;
      i = i - 1;
    }
  return (base10);
}

int	my_get_nbr(char *nbr)
{
  int	nb;
  int	signe;

  nb = 0;
  signe = signenbr(nbr);
  nbr = findnbr(nbr);
  if (nbr != 0)
    {
      nb = transformnbr(nbr);
      if (signe == 1)
	nb = nb * -1;
    }
  free(nbr);
  return (nb);
}
