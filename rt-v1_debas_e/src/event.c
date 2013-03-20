/*
** event.c for rtv1 in /tmp/rtv1-2017-debas_e
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Sun Mar 17 22:52:32 2013 etienne debas
** Last update Sun Mar 17 22:55:43 2013 etienne debas
*/

#include "../rtv1.h"
#include "mlx.h"

int		grkey(int key, t_scene *scene)
{
  int		i;

  if (key == ESCAPE)
    {
      i = 0;
      while (scene->obj[i].type != -1)
      	{
      	  free(scene->obj[i].rot);
      	  i++;
      	}
      free(scene->obj);
      free(scene);
      exit(0);
    }
}

int		gere_expose(t_param_win *win)
{
  mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
}
