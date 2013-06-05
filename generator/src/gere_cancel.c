/*
** gere_cancel.c for gere_cancel in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Jun  5 13:00:19 2013 remi robert
** Last update Wed Jun  5 13:08:11 2013 remi robert
*/

#include "my_func.h"

void		gere_cancel(t_param *param)
{
  t_object	*pcourant;

  param->on_click = NOTHING;
  param->click_menu = 0;
  gere_expose(param);
  if (param->phead == NULL)
    return ;
  pcourant = param->phead;
  while (pcourant->next != NULL &&
	 pcourant->next->next != NULL)
    pcourant = pcourant->next;
  if (pcourant->next == NULL)
    {
      free(param->phead);
      param->phead = NULL;
      return ;
    }
  free(pcourant->next);
  pcourant->next = NULL;
}
