/*
** strcpy.c for strcpy in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Jun  5 08:23:42 2013 remi robert
** Last update Wed Jun  5 08:25:59 2013 remi robert
*/

#include "my_func.h"

void	my_strcpy(char *str, int size, char *str_rempl)
{
  int	i;

  i = -1;
  while (str_rempl[++i] != '\0' && i < size)
    str[i] = str_rempl[i];
  str[i] = '\0';
}
