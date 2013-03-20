/*
** parseobj.c for parseobj in /home/adrien/Projet/Igraph/RT_V1/Test
** 
** Made by Adrien
** Login   <adrien@adrien>
** 
** Started on  Tue Mar 12 10:04:13 2013 Adrien
** Last update Wed Mar 13 14:32:38 2013 Adrien
*/

#include "include.h"

void	getpos(t_obj *obj, char *str)
{
  int	i;

  i = 0;
  while (str[i] != ' ' && str[i] != 0)
    ++i;
  if (str[i] == 0)
    return ;
  ++i;
  obj->pos.x = my_get_nbr(&str[i]);
  while (str[i] != ' ' && str[i] != 0)
    ++i;
  if (str[i] == 0)
    return ;
  ++i;
  obj->pos.y = my_get_nbr(&str[i]);
  while (str[i] != ' ' && str[i] != 0)
    ++i;
  if (str[i] == 0)
    return ;
  ++i;
  obj->pos.z = my_get_nbr(&str[i]);
}

void	getrot(t_obj *obj, char *str)
{
  int	i;

  i = 0;
  while (str[i] != ' ' && str[i] != 0)
    ++i;
  if (str[i] == 0)
    return ;
  ++i;
  obj->rot.x = my_get_nbr(&str[i]);
  while (str[i] != ' ' && str[i] != 0)
    ++i;
  if (str[i] == 0)
    return ;
  ++i;
  obj->rot.y = my_get_nbr(&str[i]);
  while (str[i] != ' ' && str[i] != 0)
    ++i;
  if (str[i] == 0)
    return ;
  ++i;
  obj->rot.z = my_get_nbr(&str[i]);
}

void	getangle(t_obj *obj, char *str)
{
  int	i;

  i = 0;
  while (str[i] != ' ' && str[i] != 0)
    ++i;
  if (str[i] == 0)
    return ;
  ++i;
  obj->x = my_get_nbr(&str[i]);
}

void	getrayon(t_obj *obj, char *str)
{
  int	i;

  i = 0;
  while (str[i] != ' ' && str[i] != 0)
    ++i;
  if (str[i] == 0)
    return ;
  ++i;
  obj->r = my_get_nbr(&str[i]);
}

void	getcolor(t_obj *obj, char *str)
{
  int	i;

  i = 0;
  while (str[i] != ' ' && str[i] != 0)
    ++i;
  if (str[i] == 0)
    return ;
  ++i;
  obj->color = my_getnbr_base(&str[i]);
}
