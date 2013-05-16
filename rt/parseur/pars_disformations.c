/*
** pars_disformations.c for pars_disformations in /home/sinet_l//rt/rt/parseur
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu May 16 11:18:32 2013 luc sinet
** Last update Thu May 16 13:21:28 2013 luc sinet
*/

#include "main.h"
#include "pars.h"

void	pars_limits(char *line, t_obj *ept, t_text *text)
{
  (void)text;
  fill_limits(&line[8], ept->limit);
}

void	pars_perturbations(char *line, t_obj *ept, t_text *text)
{
  (void)text;
  fill_pert(&line[13], ept->pert);
}

void	pars_normal1(char *line, t_obj *ept, t_text *text)
{
  (void)text;
  fill_vec(ept->v1, &line[5]);
}

void	pars_normal2(char *line, t_obj *ept, t_text *text)
{
  (void)text;
  fill_vec(ept->v2, &line[5]);
}

void	pars_normal(char *line, t_obj *ept, t_text *text)
{
  (void)text;
  fill_vec(ept->normal, &line[9]);
}
