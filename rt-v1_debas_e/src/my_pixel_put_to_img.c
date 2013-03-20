/*
** mlx_pixel_put_to_img.c for wolf3d in /home/debas_e//projet/wolf3d
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Fri Jan  4 13:24:24 2013 etienne debas
** Last update Sun Mar 17 16:30:07 2013 etienne debas
*/

#include "../rtv1.h"

int             my_pixel_put_to_image(int x, int y,
				      t_param_win *param, int color)
{
  int           col;
  int           bpp;
  char          *data;
  int           pos_x;
  int           endian;
  int           sizeline;

  data = mlx_get_data_addr(param->img_ptr, &bpp, &sizeline, &endian);
  pos_x = (sizeline * y) + x * (bpp / 8);
  col = mlx_get_color_value(param->mlx_ptr, color);
  if ((x < 0) || (y < 0) || (x > WINX) || (y > WINY) || (pos_x < 0))
    return (0);
  data[pos_x] = col & 255;
  data[pos_x + 1] = col >> 8 & 255;
  data[pos_x + 2] = col >> 16 & 255;
  return (0);
}
