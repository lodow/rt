/*
** my_atof.c for my_atof in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun Mar 31 00:07:15 2013 luc sinet
** Last update Sat Jun  8 18:12:53 2013 luc sinet
*/

double		get_deci(char *s1)
{
  double	res;
  double	deci;
  int		pos;

  deci = 1;
  pos = 0;
  res = 1;
  while (s1[pos] >= '0' && s1[pos] <= '9')
    {
      if (res * 10 / 10 != res)
	return (0);
      res = res * 10 + (s1[pos++] - 48);
      deci *= 10;
    }
  return ((res - deci) / deci);
}

double		my_fgetnbr(char *s1)
{
  int		i;
  double	nb;
  double       	sign;

  nb = 0;
  i = 0;
  sign = 1;
  while (s1[i] == ' ' || s1[i] == '-' || s1[i] == '+')
    if (s1[i++] == '-')
      sign = -sign;
  while (s1[i] >= '0' && s1[i] <= '9')
    {
      if (((nb * 10) / 10) != nb)
	return (0);
      nb = nb * 10 + (s1[i++] - 48);
    }
  if (s1[i] == '.')
    nb += get_deci(&s1[i + 1]);
  return (nb * sign);
}
