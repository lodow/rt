/*
** bmp_loader.c for bmp_loader in /home/adrien/bmp_loader
** 
** Made by Adrien
** Login   <adrien@Adrien>
** 
** Started on  Wed May  1 13:50:59 2013 Adrien
** Last update Thu May  2 17:28:29 2013 Adrien
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "bmp_loader.h"

void	my_memcpy(void *mem1, void *mem2, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      ((char *)mem2)[i] = ((char *)mem1)[i];
      i++;
    }
}

int	check_bmp(t_info_bmp *info, char **img, int fd, t_bmp *image)
{
  int	ret;

  if ((info->deep_color[0] != 0x18 && info->deep_color[1] != 0) ||
      (info->magic_nb[0] != 'B' && info->magic_nb[1] != 'M') || 
      (*img = malloc((info->widht + info->widht % 4) * (info->deep_color[0] / 8)
		     * info->deep_color[0] * info->height)) == NULL ||
      (image->texture = malloc(info->widht_image * (info->deep_color[0] / 8)
			       * info->height_image)) == NULL
      || ((ret = read(fd, *img, (info->widht + info->widht % 4) * info->deep_color[0]
		      * info->height)) == -1)
      || (ret < ((info->widht + info->widht % 4) * (info->deep_color[0] / 8))
	  * info->height))
    return (-1);
  return (0);
}

void	fill_img(t_info_bmp *info, t_bmp *image, char *img)
{
  int		i;
  int		j;
  int		widht;

  j = info->height - 1;
  widht = info->widht * (info->deep_color[0] / 8);
  while (j >= 0)
    {
      i = widht - 1;
      while (i >= 0)
	{
	  image->texture[((info->height - 1) - j) * widht + ((widht - 1) - i)]
	    = img[widht * j + i];
	  --i;
	}
      --j;
    }
  image->height = info->height;
  image->widht = widht;
}

t_bmp		*bmp_loader(char *path)
{
  t_info_bmp	info;
  t_bmp		*image;
  char		*img;
  char		buffer[55];
  int		ret;
  int		fd;

  if ((fd = open(path, O_RDONLY)) == -1 || (ret = read(fd, buffer, 54)) == -1
      || ret < 54)
    return (NULL);
  my_memcpy((void *)buffer, (void *)&info, 54);
  if ((image = malloc(sizeof(t_bmp))) == NULL ||
      (check_bmp(&info, &img, fd, image)) == -1)
    return (NULL);
  fill_img(&info, image, img);
  return (image);
}
