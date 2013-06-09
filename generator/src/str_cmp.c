/*
** str_cmp.c for str_cmp in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Jun  4 10:57:53 2013 remi robert
** Last update Tue Jun  4 11:01:39 2013 remi robert
*/

#include "my_func.h"

int	str_cmp(char *str1, char *str2)
{
  int	i;

  i = -1;
  if (str1 == NULL || str2 == NULL)
    return (0);
  while (str1[++i] != '\0' && str2[i] != '\0')
    if (str1[i] != str2[i])
      return (0);
  if (str1[i] == '\0' && str2[i] == '\0')
    return (1);
  return (0);
}
