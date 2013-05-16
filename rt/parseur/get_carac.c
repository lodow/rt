/*
** get_carac.c for carac in /home/sinet_l//rtv1-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sat Mar 16 23:19:04 2013 luc sinet
** Last update Thu May 16 14:39:36 2013 luc sinet
*/

#include "main.h"
#include "pars.h"
#include "str.h"
#include "nb.h"

void	fill_vec(double vec[3], char *line)
{
  int	pl;
  int	x;

  pl = 0;
  x = 0;
  if (!line[pl])
    return ;
  while (x < 3)
    {
      if (line[pl] == ',' || line[pl] == ';')
        return ;
      vec[x] = my_sgetnbr(line, &pl);
      if (line[pl])
        pl++;
      if (!line[pl])
        return ;
      x++;
    }
}

void	fill_center(t_obj *ept, char *line)
{
  int	pl;
  int	x;

  pl = 9;
  x = 0;
  if (!line[pl])
    return ;
  while (x < 3)
    {
      if (line[pl] == ',' || line[pl] == ';')
	return ;
      ept->pos[x] = my_sgetnbr(line, &pl);
      if (line[pl])
	pl++;
      if (!line[pl])
	return ;
      x++;
    }
}

void	fill_angle(t_obj *ept, char *line)
{
  int	pl;
  int	x;
  int	ang;

  pl = 8;
  if (!line[pl])
    return ;
  x = 0;
  while (x < 4)
    {
      if (line[pl] == ',' || line[pl] == ';')
	return ;
      ang = my_sgetnbr(line, &pl);
      ept->angle[x] = ang;
      if (line[pl])
	pl++;
      if (!line[pl])
	return ;
      x++;
    }
}

void	fill_carac_model(char **carac)
{
  carac[0] = "Color = ";
  carac[1] = "Brightness = ";
  carac[2] = "Texture = ";
  carac[3] = "Absorbance = ";
  carac[4] = "Limit = ";
  carac[5] = "Ondulation = ";
  carac[6] = "V1 = ";
  carac[7] = "V2 = ";
  carac[8] = "Normal = ";
  carac[9] = "Alpha = ";
  carac[10] = "N = ";
  carac[11] = "Reflection = ";
  carac[12] = "Cst = ";
  carac[13] = "Size = ";
}

int	other_opt(char *line, t_obj *ept, t_text *text)
{
  int	i;
  char	*carac[14];
  void	(*objptr[14])(char *line, t_obj *ept, t_text *text);

  i = 0;
  if (my_strncmp("Name = ", line, 7) == 0)
    return (0);
  fill_carac_model(carac);
  init_objptr(objptr);
  while (i < 14 && my_strncmp(carac[i], line, my_strlen(carac[i])) != 0)
    ++i;
  if (i < 14)
    objptr[i](line, ept, text);
  return (i == 14 ? -1 : 0);
}
