/*
** fill_texture.c for fill_texture in /home/adrien/Projet/rt/rt/parseur
** 
** Made by Adrien Della Maggiora
** Login   <adrien@mint>
** 
** Started on  Thu May  9 10:16:03 2013 Adrien Della Maggiora
** Last update Thu May  9 10:39:07 2013 Adrien Della Maggiora
*/

#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "pars.h"

int	fill_texture(t_pars *opt, t_rt *rpt)
{
  int	i;
  int	y;

  while (opt->file[i] && strcmp(opt->file[i], "Texture") != 0)
    ++i;
  if (opt->file[i] == NULL)
    return (0);
  if (opt->file[i] && strcmp(opt->file[i], "{") == 0)
    fill_text();
}
