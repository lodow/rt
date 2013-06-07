/*
** gere_mouse.c for gere_mouse in /home/remi/Projet/gen_map_rt
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed May 29 13:29:07 2013 remi
** Last update Fri Jun  7 11:15:19 2013 remi robert
*/

#include "my_func.h"

char	check_the_object_click(t_param *param, int x, int y)
{
  int	indice_y;
  int	nb;

  indice_y = 0;
  nb = 0;
  while (indice_y <= param->window.y)
    {
      if (y >= indice_y && y <= (indice_y + (param->window.y / 12))
	  && x <= 150)
	return (get_type_object(nb));
      ++nb;
      indice_y += param->window.y / 12;
    }
  return (NOTHING);
}

void	add_elem_on_click(t_param *param, int x, int y)
{
  char	type;

  if (param->on_click != NOTHING ||
      (type = check_the_object_click(param, x, y)) == NOTHING)
    return ;
  if ((add_object(&param->phead, type)) == 0)
    return ;
  param->on_click = type;
  param->click_menu = 1;
  draw_ui(param);
  mlx_put_image_to_window(param->window.p, param->window.id,
			  param->panel_control.img,
			  165, 10);
  draw_conf(param);
}

void	gere_menu_param(t_param *param, int x, int y)
{
  if (param->saisi.check == 1)
    {
      validate_saisi(param, x, y);
      return ;
    }
  if (x >= 450 && x <= 600 && y >= 60 && y <= 520)
    {
      detect_box(param, x, y);
      return ;
    }
  if (x >= 160 && x <= 400 && y >= 600 && y <= 650)
    gere_cancel(param);
  if (x >= 400 && x <= 600 && y >= 600 && y <= 650)
    {
      param->click_menu = 0;
      gere_expose(param);
    }
  if (x > 605 || y > 650)
    my_putstr("please, submit the configuration\n", 1, -1);
}

void		pos_elem(t_param *param, int x, int y)
{
  t_object	*pcurrent;

  if (param->phead == NULL ||
      param->on_click == NOTHING)
    return ;
  if (param->click_menu == 1)
    {
      gere_menu_param(param, x, y);
      return ;
    }
  pcurrent = param->phead;
  while (pcurrent->next != NULL)
    pcurrent = pcurrent->next;
  pcurrent->x = x - 151;
  pcurrent->y = y;
  param->on_click = NOTHING;
  mlx_put_image_to_window(param->window.p, param->window.id,
			  param->image.img, 0, 0);
  draw_ui(param);
}

int	gere_mouse(int button, int x, int y, t_param *param)
{
  (void)button;
  if (x < 154 || y >= param->window.y - 31)
    {
      add_elem_on_click(param, x, y);
      return (0);
    }
  pos_elem(param, x, y);
  return (0);
}
