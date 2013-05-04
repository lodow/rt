/*
** strcmp.c for strcmp in /home/sinet_l//minishell1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri Feb 15 12:36:24 2013 luc sinet
** Last update Sat May  4 13:25:59 2013 luc sinet
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/str.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while ((s1[i] || s2[i]) && i < n)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  return (0);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] || s2[i])
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  return (0);
}

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  if (tab == NULL)
    return ;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}

void	my_putchar(char c, int fd)
{
  if (write(fd, &c, 1) == -1)
    if (write(2, "Write error\n", 12) == -1)
      return ;
}
