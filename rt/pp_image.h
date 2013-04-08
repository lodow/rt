/*
** pp_image.h for pp_image in /home/sinet_l//igraph
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Nov 14 20:45:42 2012 luc sinet
** Last update Mon Apr  8 19:18:50 2013 luc sinet
*/

#ifndef PP_H_
# define PP_H_

# define WINX 1650
# define WINY 1024

typedef struct	s_par
{
  void		*win_ptr;
  void		*mlx_ptr;
  void		*img_ptr;
  char		*data;
  int		**img_obj;
  int		**timg_obj;
  int		bpp;
  int		sizeline;
  int		endian;
}		t_par;

int	my_pixel_put_to_image(int x, int y, t_par *par, unsigned int color);

#endif
