/*
** write_struct.c for write_struct in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Jun  5 13:32:41 2013 remi robert
** Last update Sat Jun  8 17:52:03 2013 remi
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

void	second_write_struct_option(t_object *pcurrent, int fd)
{
  if (pcurrent->reflexion[0] != '\0')
    {
      my_putstr("\n   Reflexion = ", fd, -1);
      my_putstr(pcurrent->reflexion, fd, -1);
    }
  if (pcurrent->normal[0] != '\0')
    {
      my_putstr("\n   Normal = ", fd, -1);
      my_putstr(pcurrent->normal, fd, -1);
    }
  if (pcurrent->checker[0] != '\0')
    {
      my_putstr("\n   Checker = ", fd, -1);
      my_putstr(pcurrent->checker, fd, -1);
    }
  if (pcurrent->n[0] != '\0')
    {
      my_putstr("\n   N = ", fd, -1);
      my_putstr(pcurrent->n, fd, -1);
    }
}

void	write_struct_option(t_object *pcurrent, int fd)
{
  if (pcurrent->bridghtness[0] != '\0')
    {
      my_putstr("\n   Bridghtness = ", fd, -1);
      my_putstr(pcurrent->bridghtness, fd, -1);
    }
  if (pcurrent->maping[0] != '\0')
    {
      my_putstr("\n   Bump mapping = ", fd, -1);
      my_putstr(pcurrent->maping, fd, -1);
    }
  if (pcurrent->perlin[0] != '\0')
    {
      my_putstr("\n   Perlin = ", fd, -1);
      my_putstr(pcurrent->perlin, fd, -1);
    }
  second_write_struct_option(pcurrent, fd);
}

void	write_other_object(char *str, t_object *pcurrent, int fd)
{
  my_putstr(str, fd, -1);
  my_putstr("\n{\n", fd, -1);
  write_center_object("   Center = ", pcurrent, fd);
  my_putstr("\n   Color = ", fd, -1);
  my_putstr(pcurrent->color, fd, -1);
  my_putstr("\n   Angle = ", fd, -1);
  my_putstr(pcurrent->angle, fd, -1);
  my_putstr("\n   Size = ", fd, -1);
  my_putstr(pcurrent->size, fd, -1);
  if (pcurrent->alpha[0] != '\0')
    {
      my_putstr("\n   Alpha = ", fd, -1);
      my_putstr(pcurrent->alpha, fd, -1);
    }
  write_struct_option(pcurrent, fd);
  my_putstr("\n}\n\n", fd, -1);
}

void	write_struct(char *str, t_object *pcurrent, int fd)
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
  if (str_cmp(str, "Light") == 1)
    {
      write_light(str, pcurrent, fd);
      return ;
    }
  write_other_object(str, pcurrent, fd);
 }
