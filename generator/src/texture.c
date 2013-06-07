/*
** texture.c for texture in /home/remi/Projet/gen_map_rt
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Fri May 31 09:45:06 2013 remi
** Last update Fri Jun  7 12:30:32 2013 remi robert
*/

#include "my_func.h"

int	load_texture_form(t_param *param)
{
  int	indice;

  if ((param->tab_texture_form = malloc(sizeof(t_texture) * 10)) == NULL)
    return (0);
  indice = -1;
  while (++indice < 10)
    if ((param->tab_texture_form[indice].img =
	 mlx_xpm_file_to_image(param->window.p,
			       get_texture_form(indice),
			       &(param->tab_texture_form[indice].y),
			       &(param->tab_texture_form[indice].x))) == NULL)
      {
	my_putstr("Error load texture : ", 2, -1);
	my_putstr(get_texture_form(indice), 2, -1);
	my_putstr("\n", 2, -1);
	return (0);
      }
  return (1);
}

int	load_texture(t_param *param)
{
  int	indice;

  indice = -1;
  while (++indice < 24)
    if ((param->tab_texture_menu[indice].img =
	 mlx_xpm_file_to_image(param->window.p,
			       get_texture_menu(indice),
			       &(param->tab_texture_menu[indice].y),
			       &(param->tab_texture_menu[indice].x))) == NULL)
      {
	my_putstr("Error load texture : ", 2, -1);
	my_putstr(get_texture_menu(indice), 2, -1);
	my_putstr("\n", 2, -1);
	return (0);
      }
  return (1);
}

int	load_write_and_chack(t_param *param)
{
  if ((param->check_ok.img =
       mlx_xpm_file_to_image(param->window.p,
			     "texture/check_ok.xpm",
			     &(param->check_ok.y),
			     &(param->check_ok.x))) == NULL ||
      (param->write.img =
       mlx_xpm_file_to_image(param->window.p,
			     "texture/write.xpm",
			     &(param->write.y),
			     &(param->write.x))) == NULL ||
      (param->cache.img =
       mlx_xpm_file_to_image(param->window.p,
			     "texture/cache.xpm",
			     &(param->cache.y),
			     &(param->cache.x))) == NULL)
    return (0);
  return (1);
}

int	init_texture(t_param *param)
{
  if ((param->tab_texture_menu =
       malloc(sizeof(t_texture) * 24)) == NULL ||
      load_texture(param) == 0 ||
      (param->panel_control.img =
       mlx_xpm_file_to_image(param->window.p,
			     "texture/panel_config.xpm",
			     &(param->panel_control.y),
			     &(param->panel_control.x))) == NULL ||
      (param->textbox.img =
       mlx_xpm_file_to_image(param->window.p,
			     "texture/textbox.xpm",
			     &(param->textbox.y),
			     &(param->textbox.x))) == NULL ||
      load_write_and_chack(param) == 0 ||
      load_texture_form(param) == 0)
    return (0);
  return (1);
}
