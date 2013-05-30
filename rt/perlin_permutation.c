/*
** perlin_permutation.c for permutation in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu May 30 17:25:12 2013 luc sinet
** Last update Thu May 30 17:30:47 2013 luc sinet
*/

double	fade(double curve)
{
  return (curve * curve * curve * (curve * (curve * 6 - 15) + 10));
}

double	lerp(double curve, double a, double b)
{
  return (a + curve * (b - a));
}
