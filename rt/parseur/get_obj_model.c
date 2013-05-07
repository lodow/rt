/*
** get_obj_model.c for get_obj_model in rt/
** 
** Made by moriss_h
** Login   <moriss_h@epitech.net>
** 
** Started on  Sun May  5 14:22:04 2013 Hugues
** Last update Tue May  7 17:18:52 2013 Hugues
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/get_next_line.h"
#include "../include/str.h"
#include "../include/nb.h"
#include "../include/main.h"
#include "../include/model.h"
#include "../include/pars.h"

void		fill_model_tab(double ***tab, int *size, char *line)
{
  int		i;
  double	**tmp;
  int		tsize;

  i = 0;
  tsize = *size;
  tmp = *tab;
  if ((tmp = adjust_mem_size((void*)tmp, tsize * sizeof(double) * 3,
			     (tsize + 1) * sizeof(double) * 3, 1))
      == NULL)
    return ;
  *tab = tmp;
  tmp[tsize][0] = my_fgetnbr(&line[i]);
  skip_fnumber(line, &i);
  tmp[tsize][1] = my_fgetnbr(&line[i]);
  skip_fnumber(line, &i);
  tmp[tsize][2] = my_fgetnbr(&line[i]);
  *size += 1;
}

void		model_indice_stuff(t_model *obj)
{

}

void		parse_model(t_model *obj, const int fd)
{
  char		*line;

  while ((line = get_next_line(fd)) != NULL)
    {
      if (!my_strncmp(line, "v ", 2)) 
	fill_model_tab((double***)&(obj->raw_vertice), &(obj->raw_size_vertice), &line[2]);
      if (!my_strncmp(line, "vt ", 3))
	fill_model_tab((double***)&(obj->raw_uvs), &(obj->raw_size_uvs), &line[3]);
      if (!my_strncmp(line, "vn ", 3))
	fill_model_tab((double***)&(obj->raw_normal), &(obj->raw_size_normal), &line[3]);
      if (!my_strncmp(line, "f ", 2))
	model_indice_stuff(obj);
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
  obj->raw_size_vertice = 0;
  obj->raw_size_normal = 0;
  obj->raw_size_uvs = 0;
  obj->fin_size_vertice = 0;
  obj->fin_size_normal = 0;
  obj->fin_size_uvs = 0;
  parse_model(obj, fd);
  close(fd);
  return (obj);
}
