/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "include.h"

void		init_camera(t_cam *cam, int sizex, int sizey)
{
  init_vect(0.0, 0.0, 0.0, &(cam->dir));
  init_vect(-1000, 0, 1.0, &(cam->pos));
}

t_rt_img	*init_rt(t_rt_img *img, int sizex, int sizey)
{
  img->sizex = sizex;
  img->sizey = sizey;
  img->end = 0;
  img->cur_pix.pix.x = 0;
  img->cur_pix.pix.x = 0;
  img->nbpixtillrefresh = NBPIX_F_REFRESH;
  init_camera(&(img->scene.cam), sizex, sizey);
  img->scene.objs = NULL;
  return (img);
}

int		loop(t_init_x *win)
{
  t_rt_img	*img;
  int		i;

  i = 0;
  img = (t_rt_img*)(win->data);
  if (img->end == 0)
    while (i++ < img->nbpixtillrefresh)
      calc_img_pixx(img, win);
  expose(win);
  if (win->key[ESC])
    {
      destroy_all(win);
      exit(0);
    }
  return (0);
}

int		main(int argc, char **argv, char **envp)
{
  t_init_x	win;
  t_rt_img	img;
  int		sizex;
  int		sizey;

  sizex = 1800;
  sizey = 900;
  if (init_windows(&win, sizex, sizey, init_rt(&img, sizex, sizey)) == -1)
    return (-1);
  get_scene_objs(argv[1], &(img.scene));
  mlx_expose_hook(win.windows, &expose, &win);
  mlx_key_hook(win.windows, &realesed_key, &(win.key));
  mlx_keypressed_hook(win.windows, &pressed_key, &(win.key));
  mlx_loop_hook(win.init, &loop, &win);
  mlx_loop(win.init);
  destroy_all(&win);
  return (0);
}
