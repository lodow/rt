/*
** rempl_rempl_struct.c for rempl_struct in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Jun  5 19:12:04 2013 remi robert
** Last update Sat Jun  8 17:54:39 2013 remi
*/

#include "my_func.h"

void	rempl_struct_second(t_param *param, t_object *pcurrent)
{
  if (param->saisi.type == 7)
    my_strcpy(pcurrent->maping, 20, param->saisi.buff);
  if (param->saisi.type == 8)
    my_strcpy(pcurrent->perlin, 20, param->saisi.buff);
  if (param->saisi.type == 9)
    my_strcpy(pcurrent->reflexion, 20, param->saisi.buff);
  if (param->saisi.type == 10)
    my_strcpy(pcurrent->normal, 20, param->saisi.buff);
  if (param->saisi.type == 11)
    my_strcpy(pcurrent->checker, 20, param->saisi.buff);
  if (param->saisi.type == 12)
    my_strcpy(pcurrent->n, 20, param->saisi.buff);
}

void	rempl_rempl_struct(t_param *param, t_object *pcurrent)
{
  if (param->saisi.type == 1)
    pcurrent->z = my_getnbr(param->saisi.buff);
  if (param->saisi.type == 2)
    my_strcpy(pcurrent->color, 20, param->saisi.buff);
  if (param->saisi.type > 2)
    validate_buffer(param->saisi.buff);
  if (param->saisi.type == 3)
    my_strcpy(pcurrent->angle, 20, param->saisi.buff);
  if (param->saisi.type == 4)
    my_strcpy(pcurrent->size, 20, param->saisi.buff);
  if (param->saisi.type == 5)
    my_strcpy(pcurrent->alpha, 20, param->saisi.buff);
  if (param->saisi.type == 6)
    my_strcpy(pcurrent->bridghtness, 20, param->saisi.buff);
  rempl_struct_second(param, pcurrent);
}
