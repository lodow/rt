/*
** pars_size.c for pars_size in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu May 16 13:20:28 2013 luc sinet
** Last update Mon Jun  3 17:49:55 2013 luc sinet
*/

#include "main.h"
#include "pars.h"

void	pars_size(char *line, t_obj *ept, t_text *text)
{
  int	i;

  i = 0;
  (void)text;
  ept->size[0] = my_fgetnbr(line);
  skip_fnumber(line, &i);
  skip_adds(line, &i);
  ept->size[1] = my_fgetnbr(&line[i]);
}
