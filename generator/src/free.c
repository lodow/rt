/*
** free.c for free in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Jun  5 10:25:39 2013 remi robert
** Last update Fri Jun  7 13:20:24 2013 remi robert
*/

#include "my_func.h"

void		free_object(t_param *param)
{
  t_object	*pcourant;
  t_object	*temp;

  if (param == NULL || param->phead == NULL)
    return ;
  pcourant = param->phead;
  while (pcourant)
    {
      temp = pcourant;
      pcourant = pcourant->next;
      if (temp != NULL)
	free(temp);
    }
}
