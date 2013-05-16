/*
** pars_size.c for pars_size in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu May 16 13:20:28 2013 luc sinet
** Last update Thu May 16 13:25:14 2013 luc sinet
*/

#include "main.h"
#include "pars.h"

void	pars_size(char *line, t_obj *ept, t_text *text)
{
  (void)text;
  ept->size = my_fgetnbr(&line[7]);
}
