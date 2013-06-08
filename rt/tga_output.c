/*
** tga_output.c for tga_output in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Jun  4 21:21:22 2013 luc sinet
** Last update Sat Jun  8 18:13:05 2013 etienne debas
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "main.h"
#include "pp_image.h"

void	create_header(t_par *ppt, char *header)
{
  my_memset(header, 0, 18);
  header[2] = 2;
  header[12] = ppt->imgwidth & 0x00FF;
  header[13] = (ppt->imgwidth & 0xFF00) / 256;
  header[14] = ppt->imgheight & 0x00FF;
  header[15] = (ppt->imgheight & 0xFF00) / 256;
  header[16] = 24;
}

void	fill_tga(t_par *ppt, int fd)
{
  int	x;
  int	y;
  int	width;
  int	octet;
  char	*img;

  img = ppt->data;
  octet = ppt->bpp / 8;
  width = ppt->imgwidth;
  y = ppt->imgheight - 1;
  while (y >= 0)
    {
      x = 0;
      while (x < (width * octet))
        {
          if ((octet == 4 && x % 4 != 3) || octet == 3)
            {
	      my_putbyte((&(img[(y * octet * width) + x])), fd, 3);
              x += 3;
            }
          ++x;
        }
      --y;
    }
}

char	*get_file_name(char *name, char *ext)
{
  int	i;
  char 	num[5];

  i = 0;
  while (i == 0 || (i < 1000 && access(name, F_OK)) == 0)
    {
      my_strcpy(name, "./display");
      nb_to_str(num, i, i);
      my_strcat(name, num);
      my_strcat(name, ext);
      ++i;
    }
  if (i == 1000)
    {
      my_putstr("Too much image\n", 2);
      return (NULL);
    }
  return (name);
}

int	output_tga(t_par *ppt)
{
  char	header[18];
  char	name[17];
  int	fd;

  if (ppt->bpp != 32 && ppt->bpp != 24)
    return (merror("Color should be coded on 32 or 24 bits\n", -1));
  if (get_file_name(name, ".tga") == NULL)
    return (-1);
  if ((fd = check_perror("Open TGA",
                         open(&name[2], O_WRONLY | O_CREAT | O_TRUNC, 0664)))
      == -1)
    return (-1);
  create_header(ppt, header);
  my_putbyte(header, fd, 18);
  fill_tga(ppt, fd);
  my_putbyte("\0\0\0\0\0\0\0\0TRUEVISION-XFILE.\0", fd, 26);
  check_perror("Close", close(fd));
  return (0);
}
