/*
** utils_color.c for rt in /tmp/rt/rt
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Sat May 18 20:12:40 2013 etienne debas
** Last update Sat Jun  8 18:13:04 2013 etienne debas
*/

void	save_color_obj(unsigned char *color,
		       unsigned char *save)
{
  save[0] = color[0];
  save[1] = color[1];
  save[2] = color[2];
}

void	reinit_color(unsigned char *color,
		     unsigned char *save)
{
  color[0] = save[0];
  color[1] = save[1];
  color[2] = save[2];
}
