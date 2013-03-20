/*
** init.c for rtv1 in /home/debas_e//Desktop/projet/rt-v1
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Mon Feb 25 20:34:44 2013 etienne debas
** Last update Sun Mar 17 01:09:00 2013 etienne debas
*/

# include "../rtv1.h"

t_param_win	*make_win()
{
  t_param_win	*win;

  if ((win = malloc(sizeof(*win))) == NULL)
    my_perror("Can't alloc structure win !\n");
  if ((win->mlx_ptr = mlx_init()) == NULL)
    my_perror("Can't init mlx_ptr !\n");
  if ((win->img_ptr = mlx_new_image(win->mlx_ptr, WINX, WINY))
       == NULL)
    my_perror("Can't create image !\n");
  if ((win->win_ptr = mlx_new_window(win->mlx_ptr, WINX, WINY, "RT-V1"))
       == NULL)
    my_perror("Can't create image !\n");
  return (win);
}

t_cam		*init_cam()
{
  t_cam		*cam;

  if ((cam = malloc(sizeof(*cam))) == NULL)
    my_perror("Allocation failed !\n");
  cam->xcam = XCAM;
  cam->ycam = YCAM;
  cam->zcam = ZCAM;
  return (cam);
}
