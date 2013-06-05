/*
** write_file.c for write_file in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jun  3 14:25:35 2013 remi robert
** Last update Wed Jun  5 13:32:56 2013 remi robert
*/

#include "my_func.h"

void		write_file(t_param *param)
{
  t_object	*pcourant;
  int		fd;

  if (param->phead == NULL ||
      (fd = open("test.cfg", O_RDWR | O_CREAT | O_TRUNC)) == -1)
    return ;
  pcourant = param->phead;
  write_struct("Cam", pcourant, fd);
  write_struct("Option", pcourant, fd);
  while (pcourant != NULL)
    {
      write_struct(get_name_file_object(pcourant->type), pcourant, fd);
      pcourant = pcourant->next;
    }
  close(fd);
}
