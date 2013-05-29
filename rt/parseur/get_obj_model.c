/*
** get_obj_model.c for get_obj_model in rt/
**
** Made by moriss_h
** Login   <moriss_h@epitech.net>
**
** Started on  Sun May  5 14:22:04 2013 Hugues
** Last update Thu May 16 15:27:39 2013 luc sinet
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "str.h"
#include "nb.h"
#include "main.h"
#include "model.h"
#include "pars.h"

void		fill_model_tab(double **tab, int *size, char *line)
{
  int		i;
  double	*tmp;
  int		tsize;

  i = 0;
  tsize = *size * 3;
  tmp = *tab;
  if ((tmp = adjust_mem_size((void*)tmp, tsize * sizeof(double),
                             (tsize + 3) * sizeof(double), 1)) == NULL)
    return ;
  *tab = tmp;
  tmp[tsize + 0] = my_fgetnbr(&line[i]);
  skip_fnumber(line, &i);
  skip_space(line, &i);
  tmp[tsize + 1] = my_fgetnbr(&line[i]);
  skip_fnumber(line, &i);
  skip_space(line, &i);
  tmp[tsize + 2] = my_fgetnbr(&line[i]);
  *size += 1;
}

void		parse_model_indice_line(char *line, int *vert,
                                int *uvs, int *norm)
{
  int		*indice[3];
  int		i;
  int		j;
  int		nb;

  indice[0] = vert;
  indice[1] = uvs;
  indice[2] = norm;
  i = 0;
  j = 0;
  while (i < 9)
    {
      nb = my_getnbr(&line[j]);
      skip_fnumber(line, &j);
      if (line[j] != '\0')
        j++;
      indice[i % 3][i / 3] = nb;
      i++;
    }
}

void		model_indice_stuff(t_model *obj, char *line)
{
  int		tabvert[3];
  int		tabuvs[3];
  int		tabnorm[3];
  int		tmpsizetab[2];

  parse_model_indice_line(line, tabvert, tabuvs, tabnorm);
  model_sizeup_fin_tab(obj);
  tmpsizetab[0] = obj->raw_size_vertice;
  tmpsizetab[1] = obj->fin_size_vertice;
  fill_model_tabs(tabvert, tmpsizetab, obj->fin_vertice, obj->raw_vertice);
  obj->fin_size_vertice = tmpsizetab[1];
  tmpsizetab[0] = obj->raw_size_uvs;
  tmpsizetab[1] = obj->fin_size_uvs;
  fill_model_tabs(tabuvs, tmpsizetab, obj->fin_uvs, obj->raw_uvs);
  obj->fin_size_uvs = tmpsizetab[1];
  tmpsizetab[0] = obj->raw_size_normal;
  tmpsizetab[1] = obj->fin_size_normal;
  fill_model_tabs(tabnorm, tmpsizetab, obj->fin_normal, obj->raw_normal);
  obj->fin_size_normal = tmpsizetab[1];
}

void		parse_model(t_model *obj, const int fd)
{
  char		*line;

  while ((line = get_next_line(fd)) != NULL)
    {
      if (!my_strncmp(line, "v ", 2))
        fill_model_tab(&(obj->raw_vertice),
                       &(obj->raw_size_vertice), &line[2]);
      if (!my_strncmp(line, "vt ", 3))
        fill_model_tab(&(obj->raw_uvs), &(obj->raw_size_uvs), &line[3]);
      if (!my_strncmp(line, "vn ", 3))
        fill_model_tab(&(obj->raw_normal), &(obj->raw_size_normal), &line[3]);
      if (!my_strncmp(line, "f ", 2))
        model_indice_stuff(obj, &line[2]);
      free(line);
    }
}

t_model		*get_file_obj_model(const char *filename)
{
  t_model	*obj;
  int		fd;

  if ((fd = open(filename, O_RDONLY)) == -1)
    return (NULL);
  if ((obj = malloc(1 * sizeof(t_model))) == NULL)
    return (NULL);
  init_model_struct(obj);
  parse_model(obj, fd);
  close(fd);
  free(obj->raw_vertice);
  free(obj->raw_normal);
  free(obj->raw_uvs);
  if ((obj->fin_vertice == NULL) || (obj->fin_size_vertice <= 0))
    {
      free(obj);
      return (NULL);
    }
  return (obj);
}
