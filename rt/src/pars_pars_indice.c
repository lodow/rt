/*
** pars_indice.c for pars_indice in /home/sinet_l//rt/rt/parseur
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu May 16 10:51:03 2013 luc sinet
** Last update Fri Jun  7 22:32:19 2013 luc sinet
*/

#include "main.h"
#include "pars.h"

void	pars_alpha(char *line, t_obj *ept, UNUSED t_text *text)
{
  ept->ipt->indice[0] = LIMIT(my_fgetnbr(line), 0, 1);
}

void	pars_refraction(char *line, t_obj *ept, UNUSED t_text *text)
{
  ept->ipt->indice[1] = my_fgetnbr(line);
}

void	pars_reflection(char *line, t_obj *ept, UNUSED t_text *text)
{
  ept->ipt->indice[2] = LIMIT(my_fgetnbr(line), 0, 0.99);
}

void	pars_cst(char *line, t_obj *ept, UNUSED t_text *text)
{
  ept->cst = my_fgetnbr(line);
}

void	pars_absorbance(char *line, t_obj *ept, UNUSED t_text *text)
{
  ept->ipt->indice[3] = LIMIT(2.0 * my_fgetnbr(line), 0, 2);
}
