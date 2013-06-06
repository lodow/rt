/*
** write_file.c for write_file in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jun  3 14:25:35 2013 remi robert
** Last update Thu Jun  6 21:32:15 2013 remi robert
*/

#include "my_func.h"

int	open_file(char *str)
{
  if (str != NULL)
    return (open(str, O_RDWR | O_CREAT | O_TRUNC));
  return (open("test.cfg", O_RDWR | O_CREAT | O_TRUNC));
}

void		write_file(t_param *param)
{
  t_object	*pcourant;
  int		fd;

  if (param->phead == NULL ||
      (fd = open_file(param->name_file)) == -1)
    return ;
  pcourant = param->phead;
  write_struct("Cam", pcourant, fd);
  write_struct("Option", pcourant, fd);
  while (pcourant != NULL)
    {
      write_struct(get_name_file_object(pcourant->type),
		   pcourant, fd);
      pcourant = pcourant->next;
    }
  close(fd);
}
