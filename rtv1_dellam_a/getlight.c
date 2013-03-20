/*
** getlight.c for getlight in /home/adrien/Projet/Igraph/RT_V1/Test
** 
** Made by Adrien
** Login   <adrien@adrien>
** 
** Started on  Tue Mar 12 10:35:32 2013 Adrien
** Last update Tue Mar 12 11:28:54 2013 Adrien
*/

#include "include.h"

int	get_coord_light(t_coord *pos, char *str)
{
  int	i;

  i = 0;
  while (str[i] != ' ' && str[i] != 0)
    ++i;
  if (str[i] == 0)
    return (-1);
  ++i;
  pos->x = my_get_nbr(&str[i]);
  while (str[i] != ' ' && str[i] != 0)
    ++i;
  if (str[i] == 0)
    return (-1);
  ++i;
  pos->y = my_get_nbr(&str[i]);
  while (str[i] != ' ' && str[i] != 0)
    ++i;
  if (str[i] == 0)
    return (-1);
  ++i;
  pos->z = my_get_nbr(&str[i]);
  return (0);
}

void		addlight(t_rt *rt, t_coord *pos, int j)
{
  t_coord	*res;

  if ((res = malloc(sizeof(t_coord) * (j + 1))) == NULL)
    exit(1);
  res[j].x = pos->x;
  res[j].y = pos->y;
  res[j].z = pos->z;
  --j;
  while (j > 0)
    {
      res[j].x = rt->light[j].x;
      res[j].y = rt->light[j].y;
      res[j].z = rt->light[j].z;
      --j;
    }
  if (rt->light != NULL)
    free(rt->light);
  rt->light = res;
}

int		getlight(t_rt *rt, int fd, int j)
{
  char		*str;
  t_coord	pos;

  str = get_next_line(fd);
  if (str == NULL || str[0] != '{')
    return (-1);
  free(str);
  str = get_next_line(fd);
  str = sub_space(str);
  if (str != NULL)
    if (my_strncmp(str, "Pos", 3) == 1)
      if (get_coord_light(&pos, str) == -1)
	return (-1);
  free(str);
  str = get_next_line(fd);
  if (str == NULL || str[0] != '}')
    return (-1);
  addlight(rt, &pos, j);
  return (0);
}
