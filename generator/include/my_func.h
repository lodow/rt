/*
** my_func.h for my_func.h in /home/remi/Projet/gen_map_rt
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed May 29 08:50:28 2013 remi
** Last update Tue Jun  4 13:12:37 2013 remi robert
*/

#ifndef MY_FUNC_H_
# define MY_FUNC_H_

# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define X		1500
# define Y		900
# define SPHERE		0
# define PLAN		1
# define CONE		2
# define CYLINDER	3
# define CIRCLE		4
# define SQUARE		5
# define TRIANGLE	6
# define PARABOLOIDE	7
# define HYERBOLOIDE	8
# define MOEBIUS	9
# define TANGLE		10
# define LIGHT		11
# define NOTHING	-1

typedef struct		s_object
{
  char			type;
  int			color;
  int			angle;
  int			z;
  int			x;
  int			y;
  struct s_object	*next;
}			t_object;

typedef struct		s_window
{
  void			*p;
  void			*id;
  int			x;
  int			y;
}			t_window;

typedef struct		s_image
{
  int			bbp;
  int			endian;
  int			size_line;
  char			*tab;
  void			*img;
}			t_image;

typedef struct		s_texture
{
  int			x;
  int			y;
  t_image		*img;
}			t_texture;

typedef struct		saisi
{
  int			x;
  int			y;
  char			buff[12];
  int			indice;
  int			check;
  int			type;
}			t_saisi;

typedef struct		s_param
{
  t_object		cam;
  t_saisi		saisi;
  char			click_menu;
  t_texture		panel_control;
  t_texture		textbox;
  t_texture		*tab_texture_menu;
  char			on_click;
  t_object		*phead;
  t_image		image;
  t_window		window;
}			t_param;

int	gere_expose(t_param *param);
void	print_menu(t_param *param);
void	list_object(t_object *phead);
void	my_putstr(const char *str, int fd, int len);
int	gere_mouse(int button, int x, int y, t_param *param);
void	draw_ui(t_param *param);
void    init_img(t_param *param);
int	my_pixel_put_to_image(int x, int y,
			      t_param *param, int color);
int	init_window(t_param *param);
void	main_loop(t_param *param);
int	gere_keyboard(int keycode, t_param *param);
void	fct_exit(t_param *param);
int	add_object(t_object **phead, char type);
char	get_type_object(int nb);
char	*get_name_object(int nb);
int	init_texture(t_param *param);
char	*get_texture_menu(int nb);
char	*convert_number_char(int number, char *tab);
int	my_strlen(char *str);
void	draw_conf(t_param *param);
char	*get_name_file_object(int nb);
void	write_file(t_param *param);
int	str_cmp(char *str, char *str2);
void	detect_box(t_param *param, int x, int y);
int	my_getnbr(char *str);

#endif
