/*
** fill_obj_color.c for fill_obj_color in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Mar 27 17:19:47 2013 luc sinet
** Last update Thu May  9 10:27:52 2013 Adrien Della Maggiora
*/

#include "nb.h"

void	get_color(char *line, unsigned char *color)
{
  int	fullcolor;

  fullcolor = my_getnbr_base(line, "0123456789ABCDEF");
  color[2] = (fullcolor & 0xFF);
  color[1] = (fullcolor >> 8) & 0xFF;
  color[0] = (fullcolor >> 16) & 0xFF;
}
