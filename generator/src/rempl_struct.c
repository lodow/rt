/*
** rempl_rempl_struct.c for rempl_struct in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Jun  5 19:12:04 2013 remi robert
** Last update Wed Jun  5 19:15:20 2013 remi robert
*/

#include "my_func.h"

void	rempl_rempl_struct(t_param *param, t_object *pcourant)
{
  if (param->saisi.type == 1)
    pcourant->z = my_getnbr(param->saisi.buff);
  if (param->saisi.type == 2)
    my_strcpy(pcourant->color, 20, param->saisi.buff);
  if (param->saisi.type > 2)
    validate_buffer(param->saisi.buff);
  if (param->saisi.type == 3)
    my_strcpy(pcourant->angle, 20, param->saisi.buff);
  if (param->saisi.type == 4)
    my_strcpy(pcourant->size, 20, param->saisi.buff);
  if (param->saisi.type == 5)
    my_strcpy(pcourant->alpha, 20, param->saisi.buff);
  if (param->saisi.type == 6)
    my_strcpy(pcourant->bridghtness, 20, param->saisi.buff);
  if (param->saisi.type == 7)
    my_strcpy(pcourant->maping, 20, param->saisi.buff);
  if (param->saisi.type == 8)
    my_strcpy(pcourant->perlin, 20, param->saisi.buff);
  if (param->saisi.type == 9)
    my_strcpy(pcourant->reflexion, 20, param->saisi.buff);

}
