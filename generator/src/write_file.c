/*
** write_file.c for write_file in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jun  3 14:25:35 2013 remi robert
** Last update Tue Jun  4 10:30:30 2013 remi robert
*/

#include "my_func.h"

void	write_center_object(t_object *pcourant, int fd)
{
  char	buff[10];
  int	i;

  my_putstr("   Center = ", fd, -1);
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

void	write_struct(t_object *pcourant, int fd)
{
  char	*s;

  s = get_name_file_object(pcourant->type);
  my_putstr(s, fd, -1);
  my_putstr("\n{\n", fd, -1);
  write_center_object(pcourant, fd);
  my_putstr("\n}\n\n", fd, -1);
}

void		write_file(t_param *param)
{
  t_object	*pcourant;
  int		fd;

  if (param->phead == NULL ||
      (fd = open("test.file", O_RDWR | O_CREAT | O_TRUNC)) == -1)
    return ;
  pcourant = param->phead;
  while (pcourant != NULL)
    {
      write_struct(pcourant, fd);
      pcourant = pcourant->next;
    }
}
