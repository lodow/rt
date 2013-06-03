/*
** gere_keyboard.c for gere_keyboard in /home/remi/Projet/gen_map_rt
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed May 29 09:35:28 2013 remi
** Last update Mon Jun  3 13:45:45 2013 remi robert
*/

#include "my_func.h"

char	get_number_with_key(int keycode)
{
  if (keycode == 65429)
    return ('7');
  if (keycode == 65431)
    return ('8');
  if (keycode == 65434)
    return ('9');
  if (keycode == 65430)
    return ('4');
  if (keycode == 65437)
    return ('5');
  if (keycode == 65432)
    return ('6');
  if (keycode == 65436)
    return ('1');
  if (keycode == 65433)
    return ('2');
  if (keycode == 65435)
    return ('3');
  if (keycode == 65438)
    return ('0');
  return ('\0');
}

void	gere_saisi_buff(t_param *param, int keycode)
{
  char	aff[2];

  if (keycode >= 65429 && keycode <= 65438)
    {
      printf("OKOK => %d\n", param->saisi.indice);
      if (param->saisi.indice >= 11)
	return ;
      aff[1] = '\0';
      aff[0] = get_number_with_key(keycode);
      param->saisi.buff[param->saisi.indice] = aff[0];
      param->saisi.indice += 1;
      param->saisi.buff[param->saisi.indice] = '\0';
      mlx_string_put(param->window.p, param->window.id, 460 +
		     (param->saisi.indice * 10), 80,
		     0x0, aff);
   }
}

int	gere_keyboard(int keycode, t_param *param)
{
  if ((keycode == 65293 || keycode == 65421) && param->saisi.check == 1)
    {
      printf("saisi accepted : %s\n", param->saisi.buff);
      param->saisi.check = 0;
      param->saisi.indice = 0;
      param->saisi.buff[0] = '\0';
    }
  gere_saisi_buff(param, keycode);
  if (keycode == 65307)
    fct_exit(param);
  return (0);
}
