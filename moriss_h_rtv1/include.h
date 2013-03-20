/*
** include.h for include in /home/moriss_h//projets/minilibx
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Thu Oct 25 12:28:07 2012 hugues morisset
** Last update Fri Jan 11 15:57:06 2013 Hugues
*/

#ifndef INCLUDE_H_
# define INCLUDE_H_

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "vector.h"
# include "get_file.h"
# include "get_next_line.h"
# include "mlx_int.h"

# define PI 3.14156
# define COS(x) cos((x))
# define SIN(x) sin(x)
# define LINE_CALC (coeff * (float)(imin + i) + offset)
# define COL_INT(x) color_to_int((x)->r, (x)->g, (x)->b)
# define COL_C (i / ((ABS(imax) - ABS(imin)) + 0.10101))
# define INTER_COL interpolate_color(&(p1->color), &(p2->color), COL_C, &(tmp))
# define DTR(x) ((x) * PI / 180)
# define MAX(x, y) (((x) > (y)) ? (x) : (y))
# define MIN(x, y) (((x) < (y)) ? (x) : (y))
# define ABS(x) (((x) < 0) ? -(x) : (x))
# define SETFLAG(x, y) ((x) |= (y))
# define UNSETFLAG(x, y) ((x) &= ~(y))
# define SWITCHFLAG(x, y) ((x) ^= (y))
# define GETFLAG(x, y) ((x) & (y))
# define FLAGPOS(x) (1 << (x))

# define NBPIX_F_REFRESH 35000
# define NB_KEYCODE 99999
# define FPS 60
# define ESC 65307
# define PLUS 65451
# define MOINS 65453
# define UP 65366
# define DOWN 65365
# define AUP 65362
# define ADOWN 65364
# define ARIGHT 65363
# define ALEFT 65361
# define KZ 122
# define KS 115
# define KD 100
# define KQ 113
# define KSPACE 32
# define KM 109
# define KL 108
# define KR 114
# define KT 116
# define KG 103
# define SPHERE 0
# define PLAN 1
# define CYLINDRE 2
# define CONE 3

typedef struct	s_color
{
  unsigned char	r;
  unsigned char	g;
  unsigned char	b;
}		t_color;

typedef struct	s_screen_point
{
  int		x;
  int		y;
  t_color	color;
}		t_screen_point;

typedef struct	s_cam
{
  t_vector3d	pos;
  t_vector3d	dir;
}		t_cam;

typedef struct	s_obj
{
  int		type;
  t_vector3d	pos;
  t_vector3d	rot;
  t_color		color;
  t_vector3d	normale;
  float		r;
}		t_obj;

typedef struct	s_scene
{
  t_cam		cam;
  t_obj		**objs;
}		t_scene;

typedef struct		s_img_compo
{
  t_screen_point	pix;
  t_vector3d		normal;
  t_vector3d		wposition;
  float			depth;
  t_obj			*obj;
}			t_img_compo;

typedef struct		s_rt_img
{
  int			sizex;
  int			sizey;
  int			end;
  int			nbpixtillrefresh;
  t_scene			scene;
  t_img_compo		cur_pix;
}			t_rt_img;

typedef struct	s_init_x
{
  void		*init;
  void		*windows;
  void		*screen;
  int		expose;
  int		win_x;
  int		win_y;
  int		nb_frame;
  void		*data;
  int		key[NB_KEYCODE];
}		t_init_x;

int		init_windows(t_init_x *init, int x, int y, void *data);
void		int_to_color(int color, unsigned char *r,
                     unsigned char *g, unsigned char *b);
int		is_in_str(char c, char *base);
int		my_strlen(char *str);
void		put_pixel_img(t_init_x *win, int x, int y, t_color *color);
t_color		*init_color(unsigned char r, unsigned char g, unsigned char b,
                      t_color *color);
void		draw_line(t_screen_point *p1, t_screen_point *p2,
                  t_init_x *win);
int		expose(t_init_x *win);
t_screen_point	*draw_lineshad(t_screen_point *p1, t_screen_point *p2,
                               int i, t_color *color);
void		swap_ptr(void **screen1, void **screen2);
t_color		*interpolate_color(t_color *color1, t_color *color2,
                             float coeff, t_color *fin_color);
void		destroy_all(t_init_x *win);
void		my_memset(void *ptr, int osize, char value);
void		calc_img_pixx(t_rt_img *img, t_init_x *win);
int	equa_deg2(float a, float b, float c, float res[2]);
float	cylindre(t_cam *cam, float r);
float	sphere(t_cam *cam, float r);
float	cone(t_cam *cam, float r);
float	plan(t_cam *cam, t_vector3d *normale, float dep);
void	**add_ptr_t_tab(void **tab, void *add);
void	get_scene_objs(char *filename, t_scene *scene);
int	is_in_str(char c, char *str);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strdup(char *str);
void	my_strncpy(char *dest, char *src, int n);
t_obj	**load_objs_fr_scene_file(const char *filename);
void	my_putstr(char *str, int fd, int strlen);
char	**my_str_to_wordtab(char *str, char sepa, int delanhi);
void	**add_ptr_t_tab(void **tab, void *add);

#endif
