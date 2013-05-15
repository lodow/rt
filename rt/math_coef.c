/*
** math_coef.c for math_coef in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon May 13 18:04:09 2013 luc sinet
** Last update Mon May 13 20:53:24 2013 etienne debas
*/

double		get_pow(double nb)
{
  double	res;

  res = 1;
  while (nb >= 10)
    {
      nb /= 10;
      res *= 10;
    }
  return (res);
}
