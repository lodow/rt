/*
** my_putstr.c for my_putstr in /home/remi/Projet/gen_map_rt
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed May 29 13:40:58 2013 remi
** Last update Tue Jun  4 10:17:11 2013 remi robert
*/

#include "my_func.h"

void	my_putstr(const char *str, int fd, int strlen)
{
  int	len;

  len = 0;
  if (str != NULL)
    {
      if (strlen == -1)
        {
          while (str[len] != '\0')
            len++;
          strlen = len;
        }
      if ((len = write(fd, str, strlen)) == -1)
        write(2, "Error write\n", 15);
    }
}
