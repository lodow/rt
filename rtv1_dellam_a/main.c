/*
** main.c for main in /home/dellam_a/Projet/Igraph/RT_V1
**
** Made by Adrien dellamaggiora
** Login   <dellam_a@epitech.eu>
**
** Started on  Mon Feb  4 16:19:17 2013 Adrien dellamaggiora
** Last update Sat Mar 16 22:53:45 2013 Adrien
*/

#include "include.h"

void	initscene(t_rt *rt)
{
    rt->eye.x = 0;
    rt->eye.y = 0;
    rt->eye.z = 0;
    rt->rot.x = 0;
    rt->rot.y = 0;
    rt->rot.z = 0;
    rt->droite.x = 0;
    rt->droite.y = 0;
    rt->droite.z = 0;
}

int	gere_expose(t_rt *rt)
{
    mlx_put_image_to_window((rt->init)->in, (rt->init)->win,
                            (rt->init)->img, 0, 0);
    return (1);
}

int	gere_key(int keycode, t_rt *rt)
{
  if (keycode == ESCAPE)
    {
      free(rt->obj);
      if (rt->light != NULL)
	free(rt->light);
      exit(0);
    }
  return (1);
}

int		main(int ac, char **av)
{
    t_rt	rt;

    if (ac < 2)
      return (0);
    if ((parseur(av[1], &rt)) == -1 || rt.obj == NULL)
      {
	my_putstr("Bad Map\n");
	exit(1);
      }
    if ((rt.init = malloc(sizeof(t_windows))) == NULL)
      return (-1);
    (rt.init)->size_x = SIZE_X;
    (rt.init)->size_y = SIZE_Y;
    if (((rt.init)->in = mlx_init()) == NULL)
      return (-1);
    rt.init->win = mlx_new_window(rt.init->in, SIZE_X, SIZE_Y, "rt_v1");
    if ((rt.init)->win == NULL)
      return (-1);
    rt.init = mlx_image(rt.init);
    initscene(&rt);
    calcscene(&rt);
    mlx_expose_hook((rt.init)->win, gere_expose, &rt);
    mlx_key_hook((rt.init)->win, gere_key, &rt);
    mlx_loop((rt.init)->in);
}
