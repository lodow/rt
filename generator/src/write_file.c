/*
** write_file.c for write_file in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jun  3 14:25:35 2013 remi robert
** Last update Wed Jun  5 11:37:00 2013 remi robert
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

void	write_struct(char *str, t_object *pcourant, int fd)
{
  if (str_cmp(str, "Option") == 1 || str_cmp(str, "Cam") == 1)
    {
      if (str[0] == 'O')
	my_putstr("Option\n{\n   AA = 3;\n}\n\n", fd, -1);
      if (str[0] == 'C')
	my_putstr("Cam\n{\n   Center = -400,0,200;\n   Angle = 0,0,0;\n}\n\n",
		  fd, -1);
      return ;
    }
  my_putstr(str, fd, -1);
  my_putstr("\n{\n", fd, -1);
  write_center_object("   Center = ", pcourant, fd);
  my_putstr("\n   Color = ", fd, -1);
  my_putstr(pcourant->color, fd, -1);
  my_putstr("\n   Angle = ", fd, -1);
  my_putstr(pcourant->angle, fd, -1);
  my_putstr("\n   Size = ", fd, -1);
  my_putstr(pcourant->size, fd, -1);
  my_putstr("\n}\n\n", fd, -1);
}

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
