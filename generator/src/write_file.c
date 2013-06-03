/*
** write_file.c for write_file in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jun  3 14:25:35 2013 remi robert
** Last update Mon Jun  3 15:15:58 2013 remi robert
*/

#include "my_func.h"

void	write_struct(t_object *pcourant, int fd)
{
  char	*s;

  s = get_name_file_object(pcourant->type);
  if (write(fd, s, my_strlen(s)) == -1 ||
      write(fd, "\n", 1) == -1)
    return ;
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
