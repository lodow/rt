/*
** pars_perlin.c for pars_perlin in /home/sinet_l//rt/rt/parseur
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sat May 18 20:10:33 2013 luc sinet
** Last update Sat Jun  8 18:18:35 2013 luc sinet
*/

#include "main.h"
#include "pars.h"

void	pars_perlin_frequency(char *line, double *frequency)
{
  int	i;

  i = 0;
  skip_adds(line, &i);
  skip_space(line, &i);
  if (line[i] != '\0')
    {
      *frequency = LIMIT(my_fgetnbr(&line[i]), 0 , 100);
      *frequency /= 3000;
    }
}

void	pars_perlin(char *line, t_obj *ept, UNUSED t_text *text)
{
  char	*type[7];
  int	i;
  int	x;

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
    {
      ept->ipt->perlin[0] = x;
      pars_perlin_frequency(&line[my_strlen(type[x])], &ept->ipt->perlin[1]);
    }
}

void	pars_bump(char *line, t_obj *ept, UNUSED t_text *text)
{
  ept->ipt->bump = LIMIT(my_fgetnbr(line), 0 , 100);
  ept->ipt->bump /= 80;
}
