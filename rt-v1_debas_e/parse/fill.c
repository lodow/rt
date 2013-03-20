/*
** fill.c for rtv1 in /home/debas_e//Desktop/projet/rt-v1/parse
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Tue Mar 12 17:33:33 2013 etienne debas
** Last update Sun Mar 17 16:53:55 2013 etienne debas
*/

# include "../rtv1.h"
# include "../lib.h"
# include "../config.h"

void		fill_rotate(t_object *obj, char **tab)
{
  if (my_strcmp(tab[0], "rotate_x") == 1)
    obj->rot->rx = my_getnbr(tab[1]);
  else if (my_strcmp(tab[0], "rotate_y") == 1)
    obj->rot->ry = my_getnbr(tab[1]);
  else if (my_strcmp(tab[0], "rotate_z") == 1)
    obj->rot->rz = my_getnbr(tab[1]);
}

void		fill_pos(t_object *obj, char **tab)
{
  if (my_strcmp(tab[0], "pos_x") == 1)
    obj->x = my_getnbr(tab[1]);
  else if (my_strcmp(tab[0], "pos_y") == 1)
    obj->y = my_getnbr(tab[1]);
  else if (my_strcmp(tab[0], "pos_z") == 1)
    obj->z = my_getnbr(tab[1]);
}

void		cut_and_fill(char *line, t_object *obj)
{
  char		**tab;
  int		i;

  i = 0;
  tab = my_str_to_word_tab(line, '=');
  if (tab == NULL)
    return;
  while (tab[i])
    i++;
  if (i != 2)
    return;
  if (my_strncmp(tab[0], "rotate_", 6) == 1)
    fill_rotate(obj, tab);
  else if (my_strncmp(tab[0], "pos_", 3) == 1)
    fill_pos(obj, tab);
  else if (my_strcmp(tab[0], "angle") == 1 ||
	   my_strcmp(tab[0], "rayon") == 1)
    obj->rayon = my_getnbr(tab[1]);
  else if (my_strcmp(tab[0], "brightness") == 1)
    obj->brightness = my_getnbr_float(tab[1]);
  else if (my_strcmp(tab[0], "color") == 1)
    if (my_strncmp(tab[1], "0x", 1) == 1)
      obj->color = my_getnbr_base(tab[1] + 2, "0123456789ABCDEF");
}

char		*fill(t_object *obj, int type, int fd)
{
  char		*line;

  obj->type = type;
  while (line = get_next_line(fd))
    {
      if (get_type(line) != -1)
	return (line);
      else
	cut_and_fill(line, obj);
      free(line);
    }
  return (NULL);
}

int		parse_and_fill(int fd, t_object *obj)
{
  int		type;
  char		*line;
  int		cur_obj;

  cur_obj = 0;
  while (line = get_next_line(fd))
    {
      while ((type = get_type(line)) != -1)
      	{
      	  line = fill(&obj[cur_obj], type, fd);
      	  if (line == NULL)
	    return ;
	  cur_obj++;
      	}
      free(line);
    }
}
