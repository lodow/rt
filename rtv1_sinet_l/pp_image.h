/*
** pp_image.h for pp_image in /home/sinet_l//igraph
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Nov 14 20:45:42 2012 luc sinet
** Last update Thu Mar 14 23:13:19 2013 luc sinet
*/

#ifndef PP_H_
# define PP_H_

# define WINX 1280
# define WINY 768
# define MAX(x1 , x2) (x1 > x2) ? x1 : x2
# define MIN(x1 , x2) (x1 > x2) ? x2 : x1

typedef struct	s_par
{
  void		*win_ptr;
  void		*mlx_ptr;
  void		*img_ptr;
  char		*data;
  int		bpp;
  int		sizeline;
  int		endian;
}		t_par;

int	my_pixel_put_to_image(int x, int y, t_par *par, unsigned int color);

#endif
