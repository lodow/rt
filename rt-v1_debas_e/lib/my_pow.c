/*
** my_pow.c for rtv1 in /home/debas_e//Desktop/projet/rt-v1/lib
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Tue Mar 12 21:21:30 2013 etienne debas
** Last update Tue Mar 12 21:21:44 2013 etienne debas
*/

# include "../lib.h"

int		my_pow(int nb, int pow)
{
  int		cur_pow;
  int		nb_save;

  nb_save = nb;
  cur_pow = 1;
  if (pow == 0)
    return (1);
  while (cur_pow < pow)
    {
      nb *= nb_save;
      cur_pow++;
    }
  return (nb);
}
