/*
** parse.c for parse in /home/adrien/Projet/Igraph/RT_V1/Test
** 
** Made by Adrien
** Login   <adrien@adrien>
** 
** Started on  Tue Mar 12 18:48:02 2013 Adrien
** Last update Sat Mar 16 22:50:54 2013 Adrien
*/

#include "include.h"

void	initobj_struct(t_obj **obj)
{
  (*obj)->pos.x = 0;
  (*obj)->pos.y = 0;
  (*obj)->pos.z = 0;
  (*obj)->vec.x = 0;
  (*obj)->vec.y = 0;
  (*obj)->vec.z = 0;
  (*obj)->rot.x = 0;
  (*obj)->rot.y = 0;
  (*obj)->rot.z = 0;
  (*obj)->r = 0;
  (*obj)->x = 0;
  (*obj)->color = 0;
}

int	my_getnbr_base(char *nbr)
{
  int	i;
  int	power;
  int	res;
  char	*base16;
  int	j;

  res = 0;
  base16 = "0123456789ABCDEF";
  power = 0;
  i = my_strlen(nbr) - 1;
  while (i >= 0)
    {
      j = 0;
      while (base16[j] != 0 && nbr[i] != base16[j])
        ++j;
      if (base16[j] == 0)
	return (0);
      res = res + (j * pow(16, power));
      ++power;
      --i;
    }
  return (res);
}

int	check(t_rt *rt, int fd)
{
  int	i;
  int	j;
  t_obj	tmp;
  char	*str;

  i = 0;
  j = 0;
  while ((str = get_next_line(fd)) != NULL)
    {
      str = sub_space(str);
      if (str[0] != '#' || str[0] != 0)
	if (checkform(str, &tmp) == 1)
	  {
	    if (parsefile(fd, &tmp) == -1)
	      return (-1);
	    rt->obj = my_obj_realloc(rt->obj, &tmp, i);
	    ++i;
	  }
	else if (my_strcmp(str, "Light") == 1)
	  if (getlight(rt, fd, j++) == -1)
	    return (-1);
      free(str);
    }
  rt->lightlengh = j;
  rt->objlengh = i;
}
