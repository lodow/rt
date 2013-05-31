/*
** main.c for main in /home/remi/Projet/gen_map_rt
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed May 29 08:49:52 2013 remi
** Last update Wed May 29 09:42:04 2013 remi
*/

#include "my_func.h"

int		main(int argc, char **argv)
{
  t_param	param;

  (void)argc;
  (void)argv;
  if (init_window(&param) == 0)
    return (0);
  main_loop(&param);
  return (1);
}
