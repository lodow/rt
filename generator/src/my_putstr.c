/*
** my_putstr.c for my_putstr in /home/remi/Projet/gen_map_rt
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed May 29 13:40:58 2013 remi
** Last update Wed May 29 13:42:21 2013 remi
*/

#include "my_func.h"

void	my_putstr(char *str)
{
  int	indice;

  indice = -1;
  while (str[++indice] != '\0');
  if (write(1, str, indice) == -1)
    write(2, "Error write, on fd 1\n", 22);
}
