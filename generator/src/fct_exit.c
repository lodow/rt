/*
** fct_exit.c for fct_exit in /home/remi/Projet/gen_map_rt
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed May 29 09:52:23 2013 remi
** Last update Wed Jun  5 10:31:06 2013 remi robert
*/

#include "my_func.h"

void	fct_exit(t_param *param)
{
  list_object(param->phead);
  write_file(param);
  free_object(param);
  exit(1);
}
