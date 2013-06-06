/*
** main.c for main in /home/remi/Projet/gen_map_rt
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed May 29 08:49:52 2013 remi
** Last update Thu Jun  6 20:35:18 2013 remi robert
*/

#include "my_func.h"

int		main(int argc, char **argv, char **envp)
{
  t_param	param;

  (void)argc;
  (void)argv;
  (void)envp;
  param.name_file = NULL;
  if (argc != 1)
    param.name_file = argv[1];
  if (init_window(&param) == 0)
    return (0);
  main_loop(&param);
  return (1);
}
