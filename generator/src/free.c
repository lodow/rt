/*
** free.c for free in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Jun  5 10:25:39 2013 remi robert
** Last update Sat Jun  8 17:57:26 2013 remi
*/

#include "my_func.h"

void		free_object(t_param *param)
{
  t_object	*pcurrent;
  t_object	*temp;

  if (param == NULL || param->phead == NULL)
    return ;
  pcurrent = param->phead;
  while (pcurrent)
    {
      temp = pcurrent;
      pcurrent = pcurrent->next;
      if (temp != NULL)
	free(temp);
    }
}
