/*
** error.c for rtv1 in /home/debas_e//Desktop/projet/rt-v1
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Mon Feb 25 18:10:32 2013 etienne debas
** Last update Tue Mar 12 19:07:55 2013 etienne debas
*/

# include "../rtv1.h"

void		my_perror(char *str)
{
  my_putstr(str);
  exit (0);
}
