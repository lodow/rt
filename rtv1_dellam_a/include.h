/*
** include.h for include.h in /home/dellam_a//MinilibX/ex
**
** Made by adrien dellamaggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Thu Oct 25 13:13:20 2012 adrien dellamaggiora
** Last update Fri Mar 15 18:50:05 2013 Adrien
*/

#ifndef INCLUDE_H_
# define INCLUDE_H_

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line.h"
/*
** Taille de la fenetre
*/
# define SIZE_X 800.0
# define SIZE_Y 600.0
# define ESCAPE 65307
# define D 100.0
/*
** Macro
*/
# define ABS(Value) ((Value < 0) ? (0 - (Value)) : (Value))
# define SQUARE(Value) (Value * Value)
# define MAX(x, y) (x > y) ? x : y
# define MIN(x, y) (x > y) ? y : x
# define MODA(x) (x >= 360) ? (x - 360) : ((x < 0) ? (x + 360) : x)
# define COS(x) cos(x * M_PI / 180)
# define SIN(x) sin(x * M_PI / 180)
# define TAN(x) tan(x * M_PI / 180)

typedef struct	s_windows
{
  void		*in;
  void		*win;
  void		*img;
  char		*data;
  int		bpp;
  int		sizeline;
  int		endian;
  int		size_x;
  int		size_y;
}		t_windows;

typedef struct	s_coord
{
  float		x;
  float		y;
  float		z;
}		t_coord;

typedef	struct	s_obj
{
  int		type;
  t_coord	pos;
  t_coord	vec;
  t_coord	rot;
  float		r;
  float		x;
  int		color;
}		t_obj;

typedef struct	s_rt
{
  t_windows	*init;
  t_coord	droite;
  t_coord	rot;
  t_obj		*obj;
  int		objlengh;
  t_coord	*light;
  int		lightlengh;
  t_coord	eye;
}		t_rt;

/*
** calcscene.c
*/

void		calclpixel(t_coord *pixel, int x, int y);
float		findk(t_rt *rt, t_obj *obj);
void		inter(t_rt *rt, t_coord *pos);
void		calcscene(t_rt *rt);

/*
** checkform.c
*/

int		my_strcmp(char *s1, char *s2);
char		**initobj();
int		checkform(char *str, t_obj *obj);

/*
** eq_droite.c
*/

float		min(float a, float b);
void		eq_droite(t_rt *rt, t_coord *pixel);
t_coord		pos_reality(t_rt *rt, t_obj *obj, t_coord *vec);

/*
** form.c
*/

float		sphere(t_rt *rt, t_obj *obj);
float		plan(t_rt *rt, t_obj *obj);
float		cylindre(t_rt *rt, t_obj *obj);
float		cone(t_rt *rt, t_obj *obj);

/*
** image.c
*/

void		mlx_my_pixel_put(t_windows *init, t_coord pos, int color);
t_windows	*mlx_image(t_windows *init);
t_windows	*reset_image(t_windows *init);

/*
** light.c
*/

void		calcpt(t_coord *pos, float k, t_rt *rt);
int		transcolor(int c, float cosa);
t_coord		getnormal(t_obj *obj, t_coord *pos);
int		light(t_rt *rt, t_obj *obj, float k);

/*
** matrice.c
*/

void		rotate_x(float angle, t_coord *pos);
void		rotate_y(float angle, t_coord *pos);
void		rotate_z(float angle, t_coord *pos);

/*
** normal.c
*/

t_coord		norsphere(t_coord pos, t_coord *pt, t_obj *obj);
t_coord		norplan(t_coord pos, t_coord *pt, t_obj *obj);
t_coord		norcylindre(t_coord pos, t_coord *pt, t_obj *obj);
t_coord		norcone(t_coord pos, t_coord *pt, t_obj *obj);

/*
** parseur.c
*/

void		cpy_struct(t_obj *tmp, t_obj *obj);
t_obj		*my_obj_realloc(t_obj *obj, t_obj *tmp, int i);
int		fillstruct(t_obj *obj, char *str);
int		parsefile(int fd, t_obj *obj);
int		parseur(char *file, t_rt *rt);

/*
** shadow.c
*/

int		calc_color(t_rt *rt, t_obj *obj, float k);
int		calc_shadow(t_rt *rt, t_coord *pos, t_coord *vec);

/*
** strfunc.c
*/

int		my_strlen(char *str);
char		*sub_tab(char *str);
char		*sub_space(char *str);
void		my_putstr(char *str);
int		my_strncmp(char *s1, char *s2, int nb);

/*
** parseobj.c
*/

void		getpos(t_obj *obj, char *str);
void		getrot(t_obj *obj, char *str);
void		getangle(t_obj *obj, char *str);
void		getrayon(t_obj *obj, char *str);
void		getcolor(t_obj *obj, char *str);

void		initobj_struct(t_obj **obj);

/*
** getlight.c
*/

int		get_coord_light(t_coord *pos, char *str);
void		addlight(t_rt *rt, t_coord *pos, int j);
int		getlight(t_rt *rt, int fd, int j);

/*
** parse.c
*/

void		initobj_struct(t_obj **obj);
int		my_getnbr_base(char *nbr);
int		check(t_rt *rt, int fd);

/*
** my_get_nbr.c
*/

int		my_get_nbr(char *str);

/*
** exotique.c
*/

float		paraboloide(t_rt *rt, t_obj *obj);
t_coord		norparaboloide(t_coord pos, t_coord *pt, t_obj *obj);
float		hyperboloide(t_rt *rt, t_obj *obj);
t_coord		norhyperboloide(t_coord pos, t_coord *pt, t_obj *obj);

#endif
