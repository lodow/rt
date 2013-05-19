/*
** pars_perlin.c for pars_perlin in /home/sinet_l//rt/rt/parseur
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sat May 18 20:10:33 2013 luc sinet
** Last update Sun May 19 19:57:13 2013 luc sinet
*/

#include "main.h"
#include "pars.h"

void	pars_perlin(char *line, t_obj *ept, t_text *text)
{
  char	*type[7];
  int	i;
  int	x;

  (void)text;
  i = 0;
  x = 0;
  type[0] = "Marble";
  type[1] = "Zebra";
  type[2] = "Cloud";
  type[3] = "Wood";
  type[4] = "Mercury";
  type[5] = "Disco";
  type[6] = "Fire";
  skip_space(line, &i);
  while (x < 7 && my_strncmp(&line[i], type[x], my_strlen(type[x])) != 0)
    ++x;
  if (x == 7)
    my_putstr("Invalid perlin's type option, setted to Marble type\n", 2);
  else
    ept->perlin = x;
}
