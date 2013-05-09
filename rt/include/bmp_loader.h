/*
** bmp_loader.h for bmp_loader in /home/adrien/bmp_loader
**
** Made by Adrien
** Login   <adrien@Adrien>
**
** Started on  Wed May  1 14:21:15 2013 Adrien
** Last update Thu May  9 10:43:25 2013 Adrien Della Maggiora
*/

#ifndef BMP_LOADER_H_
# define BMP_LOADER_H_

#pragma pack(1)

typedef	struct	s_info_bmp
{
  char		magic_nb[2];
  int		size;
  int		reserve;
  int		offset;
  int		size_info;
  int		widht;
  int		height;
  char		un[2];
  char		deep_color[2];
  int		compression;
  int		size_image;
  int		widht_image;
  int		height_image;
  int		color;
  int		nb_color;
}		t_info_bmp;

typedef	struct	s_bmp
{
  char		*texture;
  int		height;
  int		widht;
}		t_bmp;

t_bmp	*bmp_loader(char *path);

#endif /* !BMP_LOADER_H_ */
