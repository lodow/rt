/*
** perlin_permutation.c for permutation in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu May 30 17:25:12 2013 luc sinet
** Last update Sat Jun  8 18:18:01 2013 etienne debas
*/

double	fade(double curve)
{
  return (curve * curve * curve * (curve * (curve * 6 - 15) + 10));
}

double	perl(double curve, double a, double b)
{
  return (a + curve * (b - a));
}
