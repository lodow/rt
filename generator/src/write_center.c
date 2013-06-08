/*
** write_center.c for write_centerr in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu Jun  6 21:29:50 2013 remi robert
** Last update Sat Jun  8 18:05:09 2013 remi
*/

#include "my_func.h"

void	write_center_object(char *str, t_object *pcurrent, int fd)
{
  char	buff[10];
  int	i;

  my_putstr(str, fd, -1);
  convert_number_char(pcurrent->x, buff, 0);
  i = -1;
  while (buff[++i] != '\0' && buff[i + 1] != '\0' &&  buff[i] == '0');
  my_putstr(&buff[i], fd, -1);
  my_putstr(",", fd, -1);
  convert_number_char(pcurrent->y, buff, 0);
  i = -1;
  while (buff[++i] != '\0' && buff[i + 1] != '\0' && buff[i] == '0');
  my_putstr(&buff[i], fd, -1);
  my_putstr(",", fd, -1);
  convert_number_char(pcurrent->z, buff, 0);
  i = -1;
  while (&buff[++i] != '\0' && buff[i + 1] != '\0' && buff[i] == '0');
  my_putstr(&buff[i], fd, -1);
}
