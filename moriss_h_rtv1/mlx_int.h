/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#ifndef MLX_INT_H
# define MLX_INT_H

# include	<stdlib.h>
# include	<unistd.h>
# include	<fcntl.h>
# include	<sys/mman.h>
# include	<X11/Xlib.h>
# include	<X11/Xutil.h>
# include	<sys/ipc.h>
# include	<sys/shm.h>
# include	<X11/extensions/XShm.h>

# define	MLX_MAX_EVENT LASTEvent

typedef struct	s_event_list
{
  int		mask;
  int		(*hook)();
  void		*param;
}		t_event_list;

typedef struct		s_win_list
{
  Window		window;
  GC			gc;
  struct s_win_list	*next;
  int			(*mouse_hook)();
  int			(*key_hook)();
  int			(*expose_hook)();
  void			*mouse_param;
  void			*key_param;
  void			*expose_param;
  t_event_list		hooks[MLX_MAX_EVENT];
}			t_win_list;

int	mlx_keypressed_hook(t_win_list *win, int (*funct)(), void *param);
int	pressed_key(int key, void *param);
int	realesed_key(int key, void *param);

#endif
