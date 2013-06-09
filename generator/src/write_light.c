/*
** write_light.c for write_light in /home/robert_r//rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun Jun  9 12:28:38 2013 remi robert
** Last update Sun Jun  9 12:29:54 2013 remi robert
*/

#include "my_func.h"

void	write_light(char *str, t_object *pcurrent, int fd)
{
  my_putstr(str, fd, -1);
  my_putstr("\n{\n", fd, -1);
  write_center_object("   Center = ", pcurrent, fd);
  my_putstr("\n   Color = ", fd, -1);
  my_putstr(pcurrent->color, fd, -1);
  my_putstr("\n   intensity = ", fd, -1);
  my_putstr(pcurrent->angle, fd, -1);
  my_putstr("\n}\n\n", fd, -1);
}
