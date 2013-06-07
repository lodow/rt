/*
** validate_saisi.c for validate_saisi in /home/remi/Projet/rt/generator
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri Jun  7 10:48:59 2013 remi robert
** Last update Fri Jun  7 11:16:07 2013 remi robert
*/

#include "my_func.h"

void	gere_second_validatation(t_param *param, int x, int y)
{
  if (x >= 160 && x <= 400 && y >= 600 && y <= 650)
    {
      param->saisi.check = 0;
      param->saisi.indice = 0;
      param->saisi.buff[0] = '\0';
      gere_cancel(param);
    }
  if (x >= 400 && x <= 600 && y >= 600 && y <= 650)
    {
      gere_keyboard(65293, param);
      param->click_menu = 0;
      gere_expose(param);
    }
}

void	validate_saisi(t_param *param, int x, int y)
{
  int	tmp_type;

  if (x >= 450 && x <= 600 && y >= 60 && y <= 520)
    {
      tmp_type = get_new_type(param, x, y);
      if (tmp_type == param->saisi.type)
	return ;
      gere_keyboard(65293, param);
      detect_box(param, x, y);
      gere_mouse(0, x, y, param);
      return ;
    }
  gere_second_validatation(param, x, y);
}
