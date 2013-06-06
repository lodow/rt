/*
** get_texture.c for get_texture in /home/remi/Projet/gen_map_rt
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Fri May 31 09:50:05 2013 remi
** Last update Thu Jun  6 11:24:58 2013 remi robert
*/

#include "my_func.h"

char	*get_texture_form(int nb)
{
  char	*tab[10];

  tab[0] = "texture/forme/sphere.xpm";
  tab[1] = "texture/forme/cone.xpm";
  tab[2] = "texture/forme/cylindre.xpm";
  tab[3] = "texture/forme/cercle.xpm";
  tab[4] = "texture/forme/carre.xpm";
  tab[5] = "texture/forme/triangle.xpm";
  tab[6] = "texture/forme/paraboloid.xpm";
  tab[7] = "texture/forme/hyperboloid.xpm";
  tab[8] = "texture/forme/tangle.xpm";
  tab[9] = "texture/forme/light.xpm";
  if (nb >= 0 && nb < 10)
    return (tab[nb]);
  return ("");
}

char	*get_texture_menu_selection(int nb)
{
  char	*tab[24];

  tab[0] = "texture/selection_1.xpm";
  tab[1] = "texture/selection_2.xpm";
  tab[2] = "texture/selection_3.xpm";
  tab[3] = "texture/selection_4.xpm";
  tab[4] = "texture/selection_5.xpm";
  tab[5] = "texture/selection_6.xpm";
  tab[6] = "texture/selection_7.xpm";
  tab[7] = "texture/selection_8.xpm";
  tab[8] = "texture/selection_9.xpm";
  tab[9] = "texture/selection_10.xpm";
  tab[10] = "texture/selection_11.xpm";
  tab[11] = "texture/selection_12.xpm";
  if (nb >= 0 && nb < 12)
    return (tab[nb]);
  return ("");
}

char	*get_texture_menu(int nb)
{
  char	*tab[24];

  tab[0] = "texture/1.xpm";
  tab[1] = "texture/2.xpm";
  tab[2] = "texture/3.xpm";
  tab[3] = "texture/4.xpm";
  tab[4] = "texture/5.xpm";
  tab[5] = "texture/6.xpm";
  tab[6] = "texture/7.xpm";
  tab[7] = "texture/8.xpm";
  tab[8] = "texture/9.xpm";
  tab[9] = "texture/10.xpm";
  tab[10] = "texture/11.xpm";
  tab[11] = "texture/12.xpm";
  if (nb >= 0 && nb < 12)
    return (tab[nb]);
  return (get_texture_menu_selection(nb - 12));
}
