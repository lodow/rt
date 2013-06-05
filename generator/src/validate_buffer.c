/*
** validate_buffer.c for validate_buffer in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Jun  5 08:33:35 2013 remi robert
** Last update Wed Jun  5 08:37:15 2013 remi robert
*/

#include "my_func.h"

void	validate_buffer(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0');
  if (i > 0 && i < 18 && str[i - 1] != ';')
    {
      str[i] = ';';
      str[i + 1] = '\0';
    }
}
