/*
** pars.h for pars in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Mar 13 15:55:16 2013 luc sinet
** Last update Wed Mar 20 22:54:18 2013 luc sinet
*/

#ifndef PARS_H_
# define PARS_H_

typedef struct	s_obj	t_obj;
typedef struct	s_lig	t_lig;

typedef struct	s_pars
{
  char		*line;
  int		accol;
  int		fd;
  int		rv;
  int		nb_line;
  int		nb_shape;
  int		nb_light;
}		t_pars;

int	other_opt(char *line, t_obj *ept);
void	fill_angle(t_obj *ept, char *line);
void	fill_center(t_obj *ept, char *line);
void	init_light(t_lig *ltab, t_pars *opt);
void	init_elem(t_obj *tab, t_pars *opt);
int	fill_tab(t_pars *opt, t_obj *tab, char *name);
int	fill_light(t_pars *opt, t_lig *ltab, char *name);
int	pars(t_rt *rpt, char *fname);

#endif
