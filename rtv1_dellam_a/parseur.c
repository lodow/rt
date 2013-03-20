/*
** parseur.c for parseur in /home/dellam_a/Projet/Igraph/RT_V1
** 
** Made by Adrien dellamaggiora
** Login   <dellam_a@epitech.eu>
** 
** Started on  Tue Feb  5 15:44:14 2013 Adrien dellamaggiora
** Last update Fri Mar 15 18:26:48 2013 Adrien
*/

#include "include.h"

void	cpy_struct(t_obj *tmp, t_obj *obj)
{
  obj->type = tmp->type;
  obj->pos.x = tmp->pos.x;
  obj->pos.y = tmp->pos.y;
  obj->pos.z = tmp->pos.z;
  obj->vec.x = tmp->vec.x;
  obj->vec.y = tmp->vec.y;
  obj->vec.z = tmp->vec.z;
  obj->rot.x = tmp->rot.x;
  obj->rot.y = tmp->rot.y;
  obj->rot.z = tmp->rot.z;
  obj->r = tmp->r;
  obj->x = tmp->x;
  obj->color = tmp->color;
}

t_obj	*my_obj_realloc(t_obj *obj, t_obj *tmp, int i)
{
  t_obj	*res;

  if ((res = malloc(sizeof(t_obj) * (i + 1))) == NULL)
    exit(0);
  cpy_struct(tmp, &res[i]);
  --i;
  while (i >= 0)
    {
      cpy_struct(&obj[i], &res[i]);
      --i;
    }
  free(obj);
  return (res);
}

int	fillstruct(t_obj *obj, char *str)
{
  if (my_strncmp(str, "Pos", 3) == 1)
    getpos(obj, str);
  else if (my_strncmp(str, "Rot", 3) == 1)
    getrot(obj, str);
  else if (my_strncmp(str, "Rayon", 5) == 1)
    getrayon(obj, str);
  else if (my_strncmp(str, "Angle", 5) == 1)
    getangle(obj, str);
  else if (my_strncmp(str, "Color", 5) == 1)
    getcolor(obj, str);
  return (0);
}

int	parsefile(int fd, t_obj *obj)
{
  char	*str;

  str = get_next_line(fd);
  initobj_struct(&obj);
  if (str[0] != '{')
    return (-1);
  while (str != NULL && str[0] != '}')
    {
      free(str);
      str = get_next_line(fd);
      str = sub_space(str);
      fillstruct(obj, str);
    }
  if (str == NULL)
    return (-1);
  free(str);
  return (0);
}

int	parseur(char *file, t_rt *rt)
{
  char	*str;
  t_obj	tmp;
  int	i;
  int	j;
  int	fd;

  if ((fd =open(file, O_RDONLY)) == -1)
    {
      my_putstr("Can't open the file.\n");
      exit(1);
    }
  rt->obj = NULL;
  rt->light = NULL;
  rt->lightlengh = 0;
  if (check(rt, fd) == -1)
    return (-1);
  close(fd);
  return (0);
}
