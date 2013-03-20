/*
** image.c for image.c in /home/dellam_a//Projet/Igraph/ex
**
** Made by adrien dellamaggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Tue Nov 20 18:23:59 2012 adrien dellamaggiora
** Last update Fri Mar 15 15:15:07 2013 Adrien
*/

#include "include.h"

void	mlx_my_pixel_put(t_windows *init, t_coord pos, int color)
{
  int	a;

  if (pos.x > SIZE_X || pos.y > SIZE_Y || pos.x < 0 || pos.y < 0)
     return ;
  a = ((int)pos.y * init->sizeline + ((int)pos.x * (init->bpp / 8)));
  if (init->bpp == 32 && init->endian == 0)
    {
      init->data[a] = (char) color;
      init->data[a + 1] = (char) (color >> 8);
      init->data[a + 2] = (char) (color >> 16);
    }
}

t_windows	*mlx_image(t_windows *init)
{
  init->img =mlx_new_image(init->in, SIZE_X, SIZE_Y);
  if (init->img == NULL)
    exit(0);
  init->data = mlx_get_data_addr(init->img, &(init->bpp),
				 &(init->sizeline), &(init->endian));
  if (init->data == NULL)
    exit(0);
  return (init);
}

t_windows	*reset_image(t_windows *init)
{
  int		i;

  i = 0;
  while (i < SIZE_X * SIZE_Y * (init->bpp / 8))
    init->data[i++] = 0;
  return (init);
}
