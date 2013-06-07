/*
** get_name_file_object.c for get_file in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jun  3 14:35:50 2013 remi robert
** Last update Fri Jun  7 20:13:18 2013 remi
*/

#include "my_func.h"

char	*get_name_file_object(int nb)
{
  char	*tab[12];

  tab[0] = "Sphere";
  tab[1] = "Plan";
  tab[2] = "Cone";
  tab[3] = "Cylindre";
  tab[4] = "Circle";
  tab[5] = "Square";
  tab[6] = "Triangle";
  tab[7] = "Paraboloid";
  tab[8] = "Hyperboloid";
  tab[9] = "Tore";
  tab[10] = "Tangle";
  tab[11] = "Light";
  if (nb >= 0 && nb < 12)
    return (tab[nb]);
  return ("#####");
}
