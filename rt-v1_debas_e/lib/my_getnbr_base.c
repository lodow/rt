/*
** my_getnbr_base.c for rtv1 in /home/debas_e//Desktop/projet/rt-v1/lib
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Tue Mar 12 19:48:23 2013 etienne debas
** Last update Tue Mar 12 21:25:04 2013 etienne debas
*/

# include "../lib.h"

int		my_getnbr_base(char *nbr, char *base)
{
  int		pos;
  int		len;
  int		nb_decimal;
  int		pos_base;

  pos = 0;
  len = my_strlen(base);
  nb_decimal = 0;
  while (nbr[pos])
    {
      pos_base = 0;
      while (base[pos_base] != nbr[my_strlen(nbr) - 1 - pos])
	pos_base++;
      nb_decimal += pos_base * (my_pow(len, pos));
      pos++;
    }
  return (nb_decimal);
}
