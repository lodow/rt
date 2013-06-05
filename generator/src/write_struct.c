/*
** write_struct.c for write_struct in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Jun  5 13:32:41 2013 remi robert
** Last update Wed Jun  5 19:20:48 2013 remi robert
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

void	write_light(char *str, t_object *pcourant, int fd)
{
  my_putstr(str, fd, -1);
  my_putstr("\n{\n", fd, -1);
  write_center_object("   Center = ", pcourant, fd);
  my_putstr("\n   Color = ", fd, -1);
  my_putstr(pcourant->color, fd, -1);
  my_putstr("\n   Intensity = ", fd, -1);
  my_putstr(pcourant->angle, fd, -1);
  my_putstr("\n}\n\n", fd, -1);
}

void	write_struct_option(t_object *pcourant, int fd)
{
  if (pcourant->bridghtness[0] != '\0')
    {
      my_putstr("\n   Bridghtness = ", fd, -1);
      my_putstr(pcourant->bridghtness, fd, -1);
    }
  if (pcourant->maping[0] != '\0')
    {
      my_putstr("\n   Bump mapping = ", fd, -1);
      my_putstr(pcourant->maping, fd, -1);
    }
  if (pcourant->perlin[0] != '\0')
    {
      my_putstr("\n   Perlin = ", fd, -1);
      my_putstr(pcourant->perlin, fd, -1);
    }
  if (pcourant->reflexion[0] != '\0')
    {
      my_putstr("\n   Reflexion = ", fd, -1);
      my_putstr(pcourant->reflexion, fd, -1);
    }
}

void	write_other_object(char *str, t_object *pcourant, int fd)
{
  my_putstr(str, fd, -1);
  my_putstr("\n{\n", fd, -1);
  write_center_object("   Center = ", pcourant, fd);
  my_putstr("\n   Color = ", fd, -1);
  my_putstr(pcourant->color, fd, -1);
  my_putstr("\n   Angle = ", fd, -1);
  my_putstr(pcourant->angle, fd, -1);
  my_putstr("\n   Size = ", fd, -1);
  my_putstr(pcourant->size, fd, -1);
  if (pcourant->alpha[0] != '\0')
    {
      my_putstr("\n   Alpha = ", fd, -1);
      my_putstr(pcourant->alpha, fd, -1);
    }
  write_struct_option(pcourant, fd);
  my_putstr("\n}\n\n", fd, -1);
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
  if (str_cmp(str, "Light") == 1)
    {
      write_light(str, pcourant, fd);
      return ;
    }
  write_other_object(str, pcourant, fd);
 }
