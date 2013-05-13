/*
** fill_texture.c for fill_texture in /home/adrien/Projet/rt/rt/parseur
** 
** Made by Adrien Della Maggiora
** Login   <adrien@mint>
** 
** Started on  Thu May  9 10:16:03 2013 Adrien Della Maggiora
** Last update Mon May 13 17:45:06 2013 Adrien Della Maggiora
*/

#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "pars.h"
#include "bmp_loader.h"

void	link_text(t_obj *ept, char *line, t_text *text)
{
  int	i;
  int	j;

  i = 0;
  while (line[i] && line[i] == ' ')
    ++i;
  if (!line[i])
    return ;
  j = 0;
  while (text->name && text->name[j] && my_strcmp(text->name[j], &line[i]) != 0)
    j++;
  if (!text->name)
    return ;
  ept->texture = text->text[j];
}

char	*get_textname(char *line)
{
  int	i;
  int	j;
  char	*res;

  i = 0;
  while (line[i] && line[i] == ' ')
    ++i;
  if (line[i] == '\0')
    return (NULL);
  j = i;
  while (line[i] && line[i] != ' ')
    ++i;
  if ((res = malloc(i - j + 1)) == NULL)
    return (NULL);
  i = 0;
  while (line[j] && line[j] != ' ')
    res[i++] = line[j++];
  res[i] = 0;
  return (res);
}

int	fill_text(char **file, t_rt *rpt, int i)
{
  int	j;

  j = i;
  while (file[j] && my_strcmp(file[j], "}") != 0)
    ++j;
  if (!file[j]
      || (rpt->text->name = malloc((j - i + 1) * sizeof(char *))) == NULL
      || (rpt->text->text = malloc((j - i + 1) * sizeof(char *))) == NULL)
    return (-1);
  j = 0;
  while (file[i] && my_strcmp(file[i], "}") != 0)
    {
      rpt->text->name[j] = get_textname(file[i]);
      rpt->text->text[j] = bmp_loader(rpt->text->name[j]);
      if (!rpt->text->name[j] || !rpt->text->text[j])
	return (merror("BMP Loader Failed.\n", -1));
      ++i;
      ++j;
    }
  rpt->text->name[j] = NULL;
  rpt->text->text[j] = NULL;
  return (0);
}

int	fill_texture(t_pars *opt, t_rt *rpt)
{
  int	i;

  opt->text = rpt->text;
  rpt->text->name = NULL;
  i = 0;
  while (opt->file[i] && my_strcmp(opt->file[i], "Texture") != 0)
    ++i;
  if (opt->file[i] == NULL)
    return (0);
  if (opt->file[i + 1] && my_strcmp(opt->file[i + 1], "{") == 0)
    return (fill_text(opt->file, rpt, i + 2));
  return (0);
}
