/*
** fct_exit.c for fct_exit in /home/remi/Projet/gen_map_rt
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed May 29 09:52:23 2013 remi
** Last update Wed May 29 13:59:11 2013 remi
*/

#include "my_func.h"

void	fct_exit(t_param *param)
{
  list_object(param->phead);
    //free and close.
  exit(1);
}
