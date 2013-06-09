/*
** draw_form.c for draw_form.c in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu Jun  6 11:31:18 2013 remi robert
** Last update Sun Jun  9 11:04:58 2013 remi robert
*/

#include "my_func.h"

int	get_indice_texture_form(char type)
{
  if (type < 0 || type > 11 || type == PLAN)
    return (-1);
  if (type == SPHERE)
    return (SPHERE);
  if (type > SPHERE && type <= HYPERBOLOIDE)
    return (type - 1);
  if (type == MOEBIUS)
    return (8);
  if (type == LIGHT)
    return (10);
  if (type == TANGLE)
    return (9);
  return (type);
}

void	urgency_texture(t_object *pcurrent, t_param *param)
{
  if (pcurrent == NULL)
    return ;
  my_pixel_put_to_image(pcurrent->x + 151, pcurrent->y, param, 0xFFFFFFFF);
  my_pixel_put_to_image(pcurrent->x + 1 + 151, pcurrent->y, param, 0xFFFFFFFF);
  my_pixel_put_to_image(pcurrent->x - 1 + 151, pcurrent->y, param, 0xFFFFFFFF);
  my_pixel_put_to_image(pcurrent->x + 151, pcurrent->y + 1, param, 0xFFFFFFFF);
  my_pixel_put_to_image(pcurrent->x + 151, pcurrent->y - 1, param, 0xFFFFFFFF);
}

void	print_texture_form(t_param *param, t_object *pcurrent, int indice)
{
  mlx_put_image_to_window(param->window.p, param->window.id,
			  param->tab_texture_form[indice].img,
			  (pcurrent->x -
			   (param->tab_texture_form[indice].x / 2)) + 151,
			  pcurrent->y -
			  (param->tab_texture_form[indice].y / 2));
}

void		draw_form(t_param *param)
{
  t_object	*pcurrent;
  int		indice;

  if (param->phead == NULL)
    return ;
  pcurrent = param->phead;
  while (pcurrent != NULL)
    {
      if ((indice = get_indice_texture_form(pcurrent->type)) != -1 &&
	  pcurrent->x != -1 && pcurrent->y != -1)
	print_texture_form(param, pcurrent, indice);
      else
	urgency_texture(pcurrent, param);
      pcurrent = pcurrent->next;
    }
}
