/*
** pars_other_indice.c for pars_other_indice in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon May 20 01:22:31 2013 luc sinet
** Last update Tue May 21 18:22:59 2013 luc sinet
*/

#include "main.h"
#include "pars.h"

void	pars_checker(char *line, t_obj *ept, t_text *text)
{
  (void)text;
  ept->checker = LIMIT(my_getnbr(line), 0 , 1000);
}
