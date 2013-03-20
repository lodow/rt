/*
** pars.h for pars in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Mar 13 15:55:16 2013 luc sinet
** Last update Sun Mar 17 00:28:22 2013 luc sinet
*/

#ifndef PARS_H_
# define PARS_H_

typedef struct	s_elem t_elem;

typedef struct	s_obj
{
  char		*line;
  int		accol;
  int		fd;
  int		rv;
  int		nb_line;
  int		nb_shape;
  int		nb_light;
}		t_obj;

int	other_opt(char *line, t_elem *ept);
void	fill_angle(t_elem *ept, char *line);
void	fill_center(t_elem *ept, char *line);

#endif
