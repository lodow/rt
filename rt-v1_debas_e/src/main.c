/*
** main.c<2> for tr-v1 in /home/debas_e//Desktop/projet/rt-v1
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Mon Feb 25 17:17:28 2013 etienne debas
** Last update Sun Mar 17 22:52:39 2013 etienne debas
*/

#include "../rtv1.h"
#include "mlx.h"

int		main(int ac, char **av)
{
  t_object	*objet;
  t_scene	*scene;

  if (ac != 2)
    my_perror("Fichier de config manquant\n");
  if ((scene = malloc(sizeof(*scene))) == NULL)
    my_perror("Allocation failed !\n");
  scene->win = make_win();
  scene->cam = init_cam();
  if ((scene->obj = get_obj(av[1])) == NULL)
    my_perror("An error occured on config loading !\n");
  ray_tracing(scene);
  mlx_hook(scene->win->win_ptr, KeyPress, KeyPressMask, grkey, scene);
  mlx_expose_hook(scene->win->win_ptr, gere_expose, scene->win);
  mlx_loop(scene->win->mlx_ptr);
}

void		ray_tracing(t_scene *scene)
{
  int		x_p;
  int		y_p;
  t_vector	*vector;

  if ((vector = malloc(sizeof(*vector))) == NULL)
    my_perror("Allocation failed !\n");
  vector->x1 = 1000;
  x_p = 0;
  while (x_p < WINX)
    {
      y_p = 0;
      while (y_p < WINY)
	{
	  make_param(vector, scene->cam, x_p, y_p);
	  fill_k_obj(vector, scene->cam, scene->obj);
	  draw_px(scene, vector, x_p, y_p);
	  y_p++;
	}
      mlx_put_image_to_window(scene->win->mlx_ptr, scene->win->win_ptr,
			      scene->win->img_ptr, 0, 0);
      x_p++;
    }
  free(vector);
}

void		make_param(t_vector *vector, t_cam *cam, int x, int y)
{
  vector->y1 = ((double)WINX / 2.0) - x;
  vector->z1 = ((double)WINY / 2.0) - y;
  vector->vx = vector->x1 - cam->xcam;
  vector->vy = vector->y1 - cam->ycam;
  vector->vz = vector->z1 - cam->zcam;
}

double		make_k(double a, double b, double c, double delta)
{
  double	k1;
  double	k2;

  if ((delta >= 0) && (a != 0))
    {
      k1 = (-b - sqrt(delta)) / (2 * a);
      k2 = (-b + sqrt(delta)) / (2 * a);
      if (k1 > 0.0 && k2 > 0.0)
	if (k1 > k2)
	  return (k2);
	else
	  return (k1);
      else if (k2 > 0.0 && k1 < 0.0)
	return (k2);
      else if (k1 > 0.0 && k2 < 0.0)
	return (k1);
    }
  else if (delta < 0)
    return (-1);
}
