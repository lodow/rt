/*
** my_strlen.c for my_strlen in /home/remi/Projet/gen_map_rt
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri May 31 16:48:55 2013 remi robert
** Last update Fri May 31 16:59:21 2013 remi robert
*/

#include "my_func.h"

int	my_strlen(char *str)
{
  int	indice;

  indice = -1;
  if (str == NULL)
    return (0);
  while (str[++indice] != '\0');
  return (indice);
}
