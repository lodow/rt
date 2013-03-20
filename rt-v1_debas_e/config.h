/*
** config.h for rtv1 in /home/debas_e//Desktop/projet/rt-v1/test
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Tue Mar 12 17:14:34 2013 etienne debas
** Last update Tue Mar 12 17:19:31 2013 etienne debas
*/

#ifndef CONFIG_H_
# define CONFIG_H_

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

void		fill_rotate(t_object *, char **);
void		fill_pos(t_object *, char **);
void		cut_and_fill(char *, t_object *);
char		*fill(t_object *, int, int);
int		parse_and_fill(int, t_object *);
void		init_obj(t_object *, int);
int		get_type(char *);
int		count_obj(int);

#endif
