/*
** add_object.c for add_object in /home/remi/Projet/gen_map_rt
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed May 29 13:36:07 2013 remi
** Last update Mon Jun  3 14:15:48 2013 remi robert
*/

#include "my_func.h"

void	list_object(t_object *phead)
{
  t_object	*pcurrent;

  if (phead == NULL)
    return ;
  pcurrent = phead;
  while (pcurrent != NULL)
    {
      printf("Object : \n");
      printf("type : %d x : %d y : %d\n", pcurrent->type, pcurrent->x, pcurrent->y);
      pcurrent = pcurrent->next;
    }
}

void		init_elem_in_the_object(t_object **pobject)
{
  (*pobject)->x = 0;
  (*pobject)->y = 0;
}

int		add_object(t_object **phead, char type)
{
  t_object	*pcurrent;
  t_object	*elem;

  if (*phead == NULL)
    {
      if ((*phead = malloc(sizeof(t_object))) == NULL)
	return (0);
      init_elem_in_the_object(phead);
      (*phead)->type = type;
      (*phead)->next = NULL;
      return (1);
    }
  if ((elem = malloc(sizeof(t_object))) == NULL)
    return (0);
  pcurrent = *phead;
  while (pcurrent->next != NULL)
    pcurrent = pcurrent->next;
  pcurrent->next = elem;
  init_elem_in_the_object(&elem);
  elem->type = type;
  elem->next = NULL;
  return (1);
}
