/*
** gere_keyboard.c for gere_keyboard in /home/remi/Projet/gen_map_rt
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed May 29 09:35:28 2013 remi
** Last update Wed May 29 09:54:35 2013 remi
*/

#include "my_func.h"

int	gere_keyboard(int keycode, t_param *param)
{
  if (keycode == 65307)
    fct_exit(param);
  return (0);
}
