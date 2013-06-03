/*
** get_object.c for get_objet in /home/remi/Projet/gen_map_rt
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Thu May 30 15:01:57 2013 remi
** Last update Mon Jun  3 14:55:20 2013 remi robert
*/

#include "my_func.h"

char	*get_name_object(int nb)
{
  char	*tab[12];

  tab[0] = "sphere";
  tab[1] = "plan";
  tab[2] = "cone";
  tab[3] = "cylindre";
  tab[4] = "circle";
  tab[5] = "square";
  tab[6] = "triangle";
  tab[7] = "paraboloid";
  tab[8] = "hyperboloid";
  tab[9] = "moebuis";
  tab[10] = "tangle";
  tab[11] = "light";
  if (nb >= 0 && nb < 12)
    return (tab[nb]);
  return ("");
}

char	get_type_object(int nb)
{
  char	tab[12];

  tab[0] = SPHERE;
  tab[1] = PLAN;
  tab[2] = CONE;
  tab[3] = CYLINDER;
  tab[4] = CIRCLE;
  tab[5] = SQUARE;
  tab[6] = TRIANGLE;
  tab[7] = PARABOLOIDE;
  tab[8] = HYERBOLOIDE;
  tab[9] = MOEBIUS;
  tab[10] = TANGLE;
  tab[11] = LIGHT;
  if (nb >= 0 && nb < 12)
    return (tab[nb]);
  return (NOTHING);
}
