/*
** main.c for rtv1 in /home/debas_e//Desktop/projet/rt-v1/test
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Mon Mar 11 21:32:15 2013 etienne debas
** Last update Sun Mar 17 03:48:12 2013 etienne debas
*/

# include "../rtv1.h"
# include "../lib.h"
# include "../config.h"

t_object	*get_obj(char *config_file)
{
  int		fd;
  int		nb_obj;
  t_object	*obj;
  int		i;
  t_rot		*rot;

  i = 0;
  if ((fd = open(config_file, O_RDONLY)) == -1)
    return (NULL);
  if ((nb_obj = count_obj(fd)) == 0)
    return (NULL);
  if ((obj = malloc((nb_obj + 1) * sizeof(t_object))) == NULL)
    return (NULL);
  obj[nb_obj].type = -1;
  while (i < nb_obj)
    if ((obj[i++].rot = malloc(sizeof(*rot))) == NULL)
      return (0);
  init_obj(obj, nb_obj);
  close(fd);
  fd = open(config_file, O_RDONLY);
  parse_and_fill(fd, obj);
  return (obj);
}

void		init_obj(t_object *obj, int nb_obj)
{
  int		i;

  i = 0;
  while (i < nb_obj)
    {
      obj[i].x = 0;
      obj[i].y = 0;
      obj[i].z = 0;
      obj[i].rot->rx = 0;
      obj[i].rot->ry = 0;
      obj[i].rot->rz = 0;
      obj[i].rayon = 0;
      obj[i].color = 0;
      obj[i].brightness = (float)0.0;
      i++;
    }
  obj[nb_obj].type = -1;
}

int		get_type(char *line)
{
  char		*type[4];
  int		i;

  i = 0;
  type[0] = "SPHERE";
  type[1] = "PLAN";
  type[2] = "CONE";
  type[3] = "CYLINDRE";
  while (i < 4)
    {
      if (my_strncmp(line, type[i], my_strlen(type[i])) == 1)
	return (i);
      i++;
    }
  return (-1);
}

int		count_obj(int fd)
{
  char		*line;
  char		*type[4];
  int		nb_obj;
  int		i;

  nb_obj = 0;
  type[0] = "SPHERE";
  type[1] = "CONE";
  type[2] = "PLAN";
  type[3] = "CYLINDRE";
  while (line = get_next_line(fd))
    {
      i = 0;
      while (i < 4)
	{
	  if (my_strncmp(line, type[i], my_strlen(type[i])) == 1)
	    nb_obj++;
	  i++;
	}
      free(line);
    }
  return (nb_obj);
}
