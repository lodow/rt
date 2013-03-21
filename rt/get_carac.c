/*
** get_carac.c for carac in /home/sinet_l//rtv1-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sat Mar 16 23:19:04 2013 luc sinet
** Last update Wed Mar 20 21:40:35 2013 luc sinet
*/

#include "main.h"
#include "pars.h"
#include "nb.h"

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
      ept->angle[x] = RANG(ang);
      if (line[pl])
	pl++;
      if (!line[pl])
	return ;
      x++;
    }
}

int	other_opt(char *line, t_obj *ept)
{
  if (my_strncmp("Size = ", line, 7) == 0)
    ept->rayon = my_getnbr(&line[7]);
  else if (my_strncmp("Color = ", line, 8) == 0 &&
	   my_strlen(line) > 10)
    ept->color = my_getnbr_base(&line[10], "0123456789ABCDEF");
  else if (my_strncmp("Brightness = ", line, 13) == 0)
    ept->bright = my_fgetnbr(&line[13]);
  else
    return (-1);
  return (0);
}
