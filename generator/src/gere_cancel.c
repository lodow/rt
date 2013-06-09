/*
** gere_cancel.c for gere_cancel in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Jun  5 13:00:19 2013 remi robert
** Last update Sat Jun  8 18:01:17 2013 remi
*/

#include "my_func.h"

void		gere_cancel(t_param *param)
{
  t_object	*pcurrent;

  param->on_click = NOTHING;
  param->click_menu = 0;
  gere_expose(param);
  if (param->phead == NULL)
    return ;
  pcurrent = param->phead;
  while (pcurrent->next != NULL &&
	 pcurrent->next->next != NULL)
    pcurrent = pcurrent->next;
  if (pcurrent->next == NULL)
    {
      free(param->phead);
      param->phead = NULL;
      return ;
    }
  free(pcurrent->next);
  pcurrent->next = NULL;
}
