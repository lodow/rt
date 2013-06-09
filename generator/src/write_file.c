/*
** write_file.c for write_file in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jun  3 14:25:35 2013 remi robert
** Last update Sun Jun  9 12:59:47 2013 remi robert
*/

#include "my_func.h"

int	open_file(char *str)
{
  if (str != NULL)
    return (open(str, O_RDWR | O_CREAT | O_TRUNC, 0666));
  return (open("test.cfg", O_RDWR | O_CREAT | O_TRUNC, 0666));
}

void		write_file(t_param *param)
{
  t_object	*pcurrent;
  int		fd;

  if (param->phead == NULL ||
      (fd = open_file(param->name_file)) == -1)
    return ;
  pcurrent = param->phead;
  write_struct("Cam", pcurrent, fd);
  write_struct("Option", pcurrent, fd);
  while (pcurrent != NULL)
    {
      write_struct(get_name_file_object(pcurrent->type),
		   pcurrent, fd);
      pcurrent = pcurrent->next;
    }
  close(fd);
}
