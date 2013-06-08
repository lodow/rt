/*
** function.h for function in /home/sinet_l//minishell
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Dec 13 13:57:35 2012 luc sinet
** Last update Sat Jun  8 17:56:22 2013 adrien dellamaggiora
*/

#ifndef NB_H_
# define NB_H_

int	my_sgetnbr(char *s1, int *i);
int	my_getnbr(char *s1);
void	my_put_nbr(int nb, int fd);
double	my_fgetnbr(char *s1);
int	get_tab_size(char **tab);
int	my_getnbr_base(char *s1, char *base);

#endif /* !NB_H_ */
