/*
** actu_textbox.c for actu_texbox in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri Jun  7 08:53:03 2013 remi robert
** Last update Fri Jun  7 08:55:51 2013 remi robert
*/

#include "my_func.h"

void	actu_texbox(t_param *param, int y)
{
  int	indice;
  int	i;

  i = 0;
  indice = 60;
  while (indice <= 500)
    {
      if (indice == y)
	mlx_put_image_to_window(param->window.p, param->window.id,
				param->textbox.img, 450, y);
      indice += 40;
      i += 1;
    }
}
