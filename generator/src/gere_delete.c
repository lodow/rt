/*
** gere_delete.c for gere_delete in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun Jun  9 10:42:10 2013 remi robert
** Last update Sun Jun  9 10:43:24 2013 remi robert
*/

#include "my_func.h"

void	aff_text_box(t_param *param)
{
  int	indice;
  char	aff[2];

  indice = -1;
  aff[1] = '\0';
  while (param->saisi.buff[++indice] != '\0')
    {
      aff[0] = param->saisi.buff[indice];
      mlx_string_put(param->window.p, param->window.id, param->saisi.x +
		     ((indice + 1) * 10), param->saisi.y,
		     0x0, aff);
    }
}

void	gere_delete(t_param *param)
{
  if (param->saisi.indice > 0)
    {
      param->saisi.indice -= 1;
      param->saisi.buff[param->saisi.indice] = '\0';
      erease_textbox(param, 450, param->saisi.y - 20);
      aff_text_box(param);
      mlx_put_image_to_window(param->window.p, param->window.id,
			      param->write.img, 429, param->saisi.y - 20);
    }
}
