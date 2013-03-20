/*
** checkform.c for checkform in /home/welanor/Projet/Igraph/RT_V1
** 
** Made by Adrien dellamaggiora
** Login   <dellam_a@epitech.eu>
** 
** Started on  Fri Feb  8 16:35:59 2013 Adrien dellamaggiora
** Last update Fri Mar 15 18:49:40 2013 Adrien
*/

#include "include.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0)
    i++;
  if (s1[i] == s2[i])
    return (1);
  return (0);
}

char	**initobj()
{
  char	**tab;

  if ((tab = malloc(6 * sizeof(char *))) == NULL)
    exit(0);
  tab[0] = "Sphere";
  tab[1] = "Plan";
  tab[2] = "Cylindre";
  tab[3] = "Cone";
  tab[4] = "Paraboloide";
  tab[5] = "Hyperboloide";
  return (tab);
}

int	checkform(char *str, t_obj *obj)
{
  char	**object;
  int	i;

  i = 0;
  object = initobj();
  while (i < 6 && my_strcmp(str, object[i]) != 1)
    ++i;
  free(object);
  if (i == 6)
    return (-1);
  obj->type = i + 1;
  return (1);
}
