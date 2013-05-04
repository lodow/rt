/*
** get_carac.c for carac in /home/sinet_l//rtv1-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sat Mar 16 23:19:04 2013 luc sinet
** Last update Sat May  4 20:22:59 2013 luc sinet
*/

#include "../include/main.h"
#include "../include/pars.h"
#include "../include/nb.h"

void	fill_center(t_obj *ept, char *line)
{
  int	pl;
  int	x;

  pl = 9;
  x = 0;
  if (!line[pl])
    return ;
  while (x < 3)
    {
      if (line[pl] == ',' || line[pl] == ';')
	return ;
      ept->pos[x] = my_sgetnbr(line, &pl);
      if (line[pl])
	pl++;
      if (!line[pl])
	return ;
      x++;
    }
}

void	fill_angle(t_obj *ept, char *line)
{
  int	pl;
  int	x;
  int	ang;

  pl = 8;
  if (!line[pl])
    return ;
  x = 0;
  while (x < 4)
    {
      if (line[pl] == ',' || line[pl] == ';')
	return ;
      ang = my_sgetnbr(line, &pl);
      ept->angle[x] = ang;
      if (line[pl])
	pl++;
      if (!line[pl])
	return ;
      x++;
    }
}

int	other_opt(char *line, t_obj *ept)
{
  int	i;
  char	*comp;
  int	(*objptr[3])(char *line, t_obj *ept);

  i = 0;
  comp = "ANRLO SCB";
  objptr[0] = &indice;
  objptr[1] = deformation;
  objptr[2] = &shape_carac;
  while (comp[i] && comp[i] != line[0])
    ++i;
  return (!comp[i] ? -1 : objptr[i / 3](line, ept));
}
