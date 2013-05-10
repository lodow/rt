/*
** obj_carac.c for obj_carac in /home/sinet_l//rt/rt/parseur
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sat May  4 20:10:26 2013 luc sinet
** Last update Fri May 10 14:59:52 2013 Adrien Della Maggiora
*/

#include "main.h"
#include "pars.h"

int	indice(char *line, t_obj *ept, t_text *text)
{
  (void)text;
  if (my_strncmp("Alpha = ", line, 8) == 0)
    ept->indice[0] = LIMIT(my_fgetnbr(&line[8]), 0, 1);
  else if (my_strncmp("N = ", line, 4) == 0)
    ept->indice[1] = my_fgetnbr(&line[4]);
  else if (my_strncmp("Reflexion = ", line, 12) == 0)
    ept->indice[2] = LIMIT(my_fgetnbr(&line[12]), 0, 1);
  else if (my_strncmp("cst = ", line, 6) == 0)
    ept->indice[3] = my_fgetnbr(&line[6]);
  else
    return (-1);
  return (0);
}

int	deformation(char *line, t_obj *ept, t_text *text)
{
  (void)text;
  if (my_strncmp("Limit = ", line, 8) == 0)
    fill_limits(&line[8], ept->limit);
  else if (my_strncmp("Ondulation = ", line, 13) == 0)
    fill_pert(&line[13], ept->pert);
  else
    return (-1);
  return (0);
}

int	shape_carac(char *line, t_obj *ept, t_text *text)
{
  if (my_strncmp("Size = ", line, 7) == 0)
    ept->rayon = my_getnbr(&line[7]);
  else if (my_strncmp("Color = ", line, 8) == 0 &&
	   my_strlen(line) > 10)
    get_color(&line[10], ept->color);
  else if (my_strncmp("Brightness = ", line, 13) == 0)
    ept->bright = LIMIT(my_fgetnbr(&line[13]), 0, 1);
  else if (my_strncmp("V1 = ", line, 5) == 0)
    fill_vec(ept->v1, &line[5]);
  else if (my_strncmp("V2 = ", line, 5) == 0)
    fill_vec(ept->v2, &line[5]);
  else if (my_strncmp("Texture = ", line, 10) == 0)
    link_text(ept, &line[10], text);
  else
    return (-1);
  return (0);
}
