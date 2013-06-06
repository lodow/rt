/*
** bmp_loader.c for bmp_loader in /home/adrien/bmp_loader
**
** Made by Adrien
** Login   <adrien@Adrien>
**
** Started on  Wed May  1 13:50:59 2013 Adrien
** Last update Fri May 31 11:25:32 2013 adrien dellamaggiora
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "bmp_loader.h"
#include "main.h"
#include "str.h"

int	check_header(t_info_bmp *info, int fd)
{
  int	ret;
  char	buffer[sizeof(t_info_bmp)];
  int	size;

  size = 0;
  while ((ret = read(fd, &buffer[size], sizeof(t_info_bmp) - size)) != -1
         && size + ret < (int)sizeof(t_info_bmp))
    size += ret;
  if (size + ret < (int)sizeof(t_info_bmp))
    return (merror("BMP Loader: Bad size of the Header in bmp file\n", -1));
  my_mem_cpy((void *)info, (void *)buffer, sizeof(t_info_bmp));
  if (info->deep_color[0] != 0x18 && info->deep_color[1] != 0)
    return (merror("BMP Loader: Bad Number of bit per Color\n", -1));
  if (info->magic_nb[0] != 'B' && info->magic_nb[1] != 'M')
    return (merror("BMP Loader: Bad Magic Number\n", -1));
  return (0);
}

int	check_bmp(t_info_bmp *info, char **img, int fd, t_bmp *image)
{
  int	ret;
  int	size;

  size = 0;
  if ((*img = malloc((info->widht + info->widht % 4) *
                     (info->deep_color[0] / 8) * info->height)) == NULL
      || (image->texture = malloc(info->widht * (info->deep_color[0] / 8)
                                  * info->height)) == NULL)
    return (merror("BMP Loader: Malloc Failed\n", -1));
  if (info->offset - (int)sizeof(t_info_bmp) < info->height)
    {
      while ((ret = read(fd, *img, info->offset - (int)sizeof(t_info_bmp) - size)) != -1
             && size + ret < info->offset - (int)sizeof(t_info_bmp))
        size += ret;
      if (size < info->offset - (int)sizeof(t_info_bmp))
        return (merror("BMP Loader: Read Error\n", -1));
    }
  size = 0;
  while ((ret = read(fd, *img, (info->widht + info->widht % 4)
                     * (info->deep_color[0] / 8) * info->height)) != -1 &&
         size < ((info->widht + info->widht % 4) * (info->deep_color[0] / 8)))
    size += ret;
  if ((size < ((info->widht + info->widht % 4) * (info->deep_color[0] / 8)) *
       info->height))
    return (merror("BMP Loader: Read Error\n", -1));
  return (0);
}

void	fill_img(t_info_bmp *info, t_bmp *image, char *img)
{
  int	i;
  int	j;
  int	widht;

  j = info->height - 1;
  widht = info->widht * (info->deep_color[0] / 8);
  while (j >= 0)
    {
      i = 0;
      while (i + 2 < widht)
        {
          image->texture[((info->height - 1) - j) * widht + i + 2] =
            img[widht * j + i + 0];
          image->texture[((info->height - 1) - j) * widht + i + 1] =
            img[widht * j + i + 1];
          image->texture[((info->height - 1) - j) * widht + i + 0] =
            img[widht * j + i + 2];
          i += 3;
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
  int		fd;

  if ((fd = open(path, O_RDONLY)) == -1)
    {
      my_putstr("BMP Loader: Open: ", 2);
      my_putstr(path, 2);
      my_putstr(" Failed\n", 2);
      return (NULL);
    }
  if ((image = malloc(sizeof(t_bmp))) == NULL)
    return (NULL);
  if (check_header(&info, fd) == -1
      || check_bmp(&info, &img, fd, image) == -1)
    return (NULL);
  fill_img(&info, image, img);
  free(img);
  return (image);
}
