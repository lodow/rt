/*
** bmp_output.c for bmp_output in /home/adrien/output_bmp
**
** Made by Adrien Della Maggiora
** Login   <adrien@mint>
**
** Started on  Wed May 22 16:27:01 2013 Adrien Della Maggiora
** Last update Tue Jun  4 14:29:50 2013 luc sinet
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "main.h"
#include "pp_image.h"
#include "bmp_loader.h"

void	init_bmp(t_info_bmp *image)
{
  image->magic_nb[0] = 0x42;
  image->magic_nb[1] = 0x4D;
  image->size = ((WINX * 3) + ((WINX * 3) % 4)) * WINY + 54;
  image->reserve = 0;
  image->offset = 54;
  image->size_info = 40;
  image->widht = WINX;
  image->height = WINY;
  image->un[0] = 1;
  image->un[1] = 0;
  image->deep_color[0] = 0x18;
  image->deep_color[1] = 0;
  image->compression = 0;
  image->size_image = ((WINX + WINX % 4) * 3) * WINY;
  image->widht_image = 2833;
  image->height_image = 2833;
  image->color = 0;
  image->nb_color = 0;
}

void	fill_with_zero(int fd, int rest)
{
  int	i;

  i = 0;
  while (i < rest)
    {
      my_putchar(0x0, fd);
      ++i;
    }
}

void	fill_bmp(char *img, int fd, t_info_bmp *info, int octet)
{
  int		x;
  int		y;

  write(fd, (void *)info, sizeof(t_info_bmp));
  y = WINY - 1;
  while (y >= 0)
    {
      x = 0;
      while (x < (WINX * octet))
	{
	  if ((octet == 4 && x % 4 != 3) || octet == 3)
	    {
	      my_putchar(img[y * (octet * WINX) + (x)], fd);
	      my_putchar(img[y * (octet * WINX) + (x + 1)], fd);
	      my_putchar(img[y * (octet * WINX) + (x + 2)], fd);
	      x += 3;
	    }
	  ++x;
	}
      fill_with_zero(fd, (WINX * 3) % 4);
      --y;
    }
}

void	nb_to_str(char *str, int nb, int size)
{
  int	i;

  i = 0;
  while (size > 0)
    {
      ++i;
      size /= 10;
    }
  size = i;
  nb *= 10;
  while (nb >= 10 && i > 0)
    {
      nb /= 10;
      str[--i] = nb % 10 + '0';
    }
  str[size] = '\0';
}

int		output_bmp(t_par *ppt)
{
  t_info_bmp	image;
  int		fd;
  int		i;
  char		name[17];
  char		num[5];

  i = 0;
  if (ppt->bpp != 32 && ppt->bpp != 24)
    return (merror("Color not coded on 32 or 24 bits\n", -1));
  init_bmp(&image);
  while (i == 0 || (i < 1000 && access(name, F_OK) == 0))
    {
      my_strcpy(name, "./display");
      nb_to_str(num, i, i);
      my_strcat(name, num);
      my_strcat(name, ".bmp");
      ++i;
    }
  if (i == 1000)
    return (merror("Too much picture\n", -1));
  if ((fd = open(&name[2], O_WRONLY | O_CREAT | O_TRUNC, 0664)) == -1)
    return (merror("Can't creat the file\n", -1));
  fill_bmp(ppt->data, fd, &image, ppt->bpp / 8);
  close(fd);
  return (0);
}
