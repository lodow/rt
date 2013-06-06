/*
** draw_ui.c for draw_ui in /home/remi/Projet/gen_map_rt
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed May 29 09:59:11 2013 remi
** Last update Thu Jun  6 21:34:09 2013 remi robert
*/

#include "my_func.h"

void	print_menu(t_param *param)
{
  int	indice_y;
  int	nb;

  indice_y = 0;
  nb = 0;
  while (indice_y <= param->window.y)
    {
      mlx_string_put(param->window.p, param->window.id, 5,
		     indice_y + (param->window.y / 12) / 2,
		     0xFFFFFFFF, get_name_object(nb));
      ++nb;
      indice_y += param->window.y / 12;
    }
}

void	draw_ui_border_menu(t_param *param)
{
  int	indice_y;
  int	indice;

  indice_y = 0;
  indice = -1;
  while (++indice < 12 && indice_y <= param->window.y)
    {
      if (indice == param->on_click)
	mlx_put_image_to_window(param->window.p, param->window.id,
				param->tab_texture_menu[indice + 12].img,
				0, indice_y);
      else
	mlx_put_image_to_window(param->window.p, param->window.id,
				param->tab_texture_menu[indice].img,
				0, indice_y);
      indice_y += param->window.y / 12;
    }
}

void	draw_ui_bothom_border(t_param *param)
{
  int	indice;

  indice = -1;
  while (++indice < param->window.x)
    {
      my_pixel_put_to_image(indice, param->window.y - 30, param, 0xFFFFFFFF);
      my_pixel_put_to_image(indice, param->window.y - 31, param, 0xFFFFFFFF);
    }
}

void	draw_ui_border(t_param *param)
{
  int	indice_y;

  indice_y = -1;
  while (++indice_y <= param->window.y)
    {
      my_pixel_put_to_image(150, indice_y, param, 0xFFFFFFFF);
      my_pixel_put_to_image(151, indice_y, param, 0xFFFFFFFF);
    }
}

void		draw_ui(t_param *param)
{
  char		buff[512];
  t_object	*pcourant;
  int		indice;

  draw_form(param);
  draw_ui_border(param);
  draw_ui_border_menu(param);
  draw_ui_bothom_border(param);
  if (param->phead == NULL)
    return ;
  indice = 0;
  pcourant = param->phead;
  while (pcourant != NULL)
    {
      indice += 1;
      pcourant = pcourant->next;
    }
  buff[0] = '\0';
  mlx_string_put(param->window.p, param->window.id, 155, 890,
		 0xFFFFFFFF, "nb elem = ");
  mlx_string_put(param->window.p, param->window.id, 220, 890,
		 0xFF00, (convert_number_char(indice, buff)));
  mlx_string_put(param->window.p, param->window.id, 1250, 890,
		 0xFF0000, "Press Escape for validate your generation");
}
