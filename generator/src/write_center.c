/*
** write_center.c for write_centerr in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu Jun  6 21:29:50 2013 remi robert
** Last update Thu Jun  6 21:30:41 2013 remi robert
*/

#include "my_func.h"

void	write_center_object(char *str, t_object *pcourant, int fd)
{
  char	buff[10];
  int	i;

  my_putstr(str, fd, -1);
  convert_number_char(pcourant->x, buff);
  i = -1;
  while (buff[++i] != '\0' && buff[i + 1] != '\0' &&  buff[i] == '0');
  my_putstr(&buff[i], fd, -1);
  my_putstr(",", fd, -1);
  convert_number_char(pcourant->y, buff);
  i = -1;
  while (buff[++i] != '\0' && buff[i + 1] != '\0' && buff[i] == '0');
  my_putstr(&buff[i], fd, -1);
  my_putstr(",", fd, -1);
  convert_number_char(pcourant->z, buff);
  i = -1;
  while (&buff[++i] != '\0' && buff[i + 1] != '\0' && buff[i] == '0');
  my_putstr(&buff[i], fd, -1);
}
