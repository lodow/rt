/*
** interpolation.c for interpolation in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun May 19 09:59:16 2013 luc sinet
** Last update Sun May 19 20:14:18 2013 luc sinet
*/

#include "main.h"
#include "pars.h"
#include "nb.h"
#include "perlin.h"

void	fill_tab_from_str(double *tab, char *str, int size)
{
  int	i;
  int	x;

  i = 0;
  x = 0;
  while (str[i] && x < size)
    {
      tab[x++] = my_fgetnbr(&str[i]);
      skip_fnumber(str, &i);
      skip_space(str, &i);
    }
}

void	lower_interpol(unsigned char *color_obj, double pn,
                     double *sval, double *col)
{
  color_obj[2] = LIMIT(C1_B * ((pn - sval[0]) / (sval[1] - sval[0]))
                       + C2_B * ((sval[1] - pn) / (sval[1] - sval[0]))
                       , 0, 255);
  color_obj[1] = LIMIT(C1_G * ((pn - sval[0]) / (sval[1] - sval[0]))
                       + C2_G * ((sval[1] - pn) / (sval[1] - sval[0]))
                       , 0, 255);
  color_obj[0] = LIMIT(C1_R * ((pn - sval[0]) / (sval[1] - sval[0])) + C2_R
                       * ((sval[1] - pn) / (sval[1] - sval[0]))
                       , 0, 255);
}

void	middle_interpol(unsigned char *color_obj, double pn,
                      double *sval, double *col)
{
  color_obj[2] = LIMIT(C2_B * ((pn - sval[1]) / (sval[2] - sval[1]))
                       + C3_B * ((sval[2] - pn) / (sval[2] - sval[1]))
                       , 0, 255);
  color_obj[1] = LIMIT(C2_G * ((pn - sval[1]) / (sval[2] - sval[1]))
                       + C3_G * ((sval[2] - pn) / (sval[2] - sval[1]))
                       , 0, 255);
  color_obj[0] = LIMIT(C2_R * ((pn - sval[1]) / (sval[2] - sval[1]))
                       + C3_R * ((sval[2] - pn) / (sval[2] - sval[1]))
                       , 0, 255);
}

void	upper_interpol(unsigned char *color_obj, UNUSED double pn,
                     UNUSED double *sval, double *col)
{
  color_obj[2] = C1_B;
  color_obj[1] = C1_G;
  color_obj[0] = C1_R;
}

void	interpolation(unsigned char *color_obj, double pn,
                    double *sval, double *col)
{
  if (pn < 0.4)
    lower_interpol(color_obj, pn, sval, col);
  else if (pn < 0.6)
    middle_interpol(color_obj, pn, sval, col);
  else
    upper_interpol(color_obj, pn, sval, col);
}
