/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "main.h"

void	loading_bar(int where, int max, int clear)
{
  float	perc;
  int	nb;
  int	i;

  i = 0;
  perc = (float)(where) / (float)(max + 1);
  nb = perc * 100;
  while (i < nb)
    {
      my_putchar('|', 1);
      i++;
    }
  my_put_nbr(nb, 1);
  my_putchar('\r', 1);
  if (clear)
    {
      my_putchar('\r', 1);
      my_putchar(27, 1);
      my_putchar('[', 1);
      my_putchar('2', 1);
      my_putchar('K', 1);
    }
}
