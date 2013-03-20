/*
** rtv1.h for rtv1 in /home/debas_e//Desktop/projet/rt-v1
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Mon Feb 25 17:51:05 2013 etienne debas
** Last update Sun Mar 17 19:56:49 2013 etienne debas
*/

#ifndef RT_V1_
# define RT_V1_

#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <X11/X.h>
#include <mlx.h>

# define WINX 1920
# define WINY 1080
# define SPHERE 0
# define PLAN 1
# define CONE 2
# define CYLINDRE 3
# define LIGHTX 0
# define LIGHTY 0
# define LIGHTZ 200
# define XCAM -500
# define YCAM 0
# define ZCAM 100
# define ESCAPE 65307

typedef struct	s_param_win
{
  void		*img_ptr;
  void		*win_ptr;
  void		*mlx_ptr;
  char		*data;
  int		bpp;
  int		sizeline;
  int		endian;
}		t_param_win;

typedef struct	s_cam
{
  double	xcam;
  double	ycam;
  double	zcam;
}		t_cam;

typedef struct	s_vector
{
  double	x1;
  double	y1;
  double	z1;
  double	vx;
  double	vy;
  double	vz;
}		t_vector;

typedef struct	s_rot
{
  double	rx;
  double	ry;
  double	rz;
}		t_rot;

typedef struct	s_object
{
  t_rot		*rot;
  char		type;
  double	x;
  double	y;
  double	z;
  double	rayon;
  double	k;
  int		color;
  double	brightness;
}		t_object;

typedef	struct	s_scene
{
  t_param_win	*win;
  t_object	*obj;
  t_cam		*cam;
}		t_scene;

void		my_perror(char *);
t_param_win	*make_win();
int		my_pixel_put_to_image(int, int, t_param_win *, int);
t_cam		*init_cam();
t_object	*make_obj(int);
void		ray_tracing(t_scene *);
void		make_param(t_vector *, t_cam *, int, int);
double		make_k_sphere(t_vector *, t_cam *, t_object);
double		make_k_plan(t_vector *, t_cam *, t_object);
double		make_k_cone(t_vector *, t_cam *, t_object);
double		make_k_cylindre(t_vector *, t_cam *, t_object);
double		make_k(double, double, double, double);
void		draw_px(t_scene *, t_vector *, int, int);
void		fill_k_obj(t_vector *, t_cam *, t_object *);
t_object	get_nearest_obj(t_object *);
int		gere_expose(t_param_win *);
void		rotate_z(double *, double *, int);
void		rotate_x(double *, double *, int);
void		rotate_y(double *, double *, int);
int		determinate_color(t_scene *, t_vector *, t_object);
t_object	*get_obj(char *);
int		make_color(int , float);
t_cam		modif_cam(t_cam *, t_object);
t_cam		get_normal(t_object obj, t_cam cam_tmp, t_vector vector_tmp);
t_cam		get_normal_sphere(t_cam *cam, t_object obj, t_vector *vector);
t_cam		get_normal_plan(t_cam *cam, t_object obj, t_vector *vector);
t_cam		get_normal_cylindre(t_cam *cam, t_object obj, t_vector *vector);
t_cam		get_normal_cone(t_cam *cam, t_object obj, t_vector *vector);
t_vector	get_vector_light(t_cam *cam, t_object obj, t_vector *vector);
double		get_cos(t_cam normal, t_vector light);
t_cam		get_impact(t_cam *cam, t_object obj, t_vector *vector);
int		get_ombre(t_vector *, t_cam *, t_scene *, t_object);
t_vector	rotate_vector(t_vector *vector, t_object);
t_cam		rotate_cam(t_cam *cam, t_object obj);
int		grkey(int, t_scene *);

#endif
