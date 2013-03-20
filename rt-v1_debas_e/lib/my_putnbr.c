/*
** my_l_putnbr.c for my_l_putnbr in /home/debas_e//projet/printf
** 
** Made by etienne debas
** Login   <debas_e@epitech.net>
** 
** Started on  Thu Nov 15 17:39:03 2012 etienne debas
** Last update Thu Nov 15 23:31:03 2012 etienne debas
*/

int	my_putnbr(int nb)
{
  if (nb == -2147483648)
    {
      my_putstr("-2147483648");
      return (0);
    }
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb >= 10)
    {
      my_putnbr(nb / 10);
    }
  my_putchar((nb%10) + 48);
}
