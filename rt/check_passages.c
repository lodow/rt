/*
** check_passages.c for check_passages in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon May  6 10:09:26 2013 luc sinet
** Last update Thu Jun  6 01:26:48 2013 luc sinet
*/

#include "main.h"

void	tab_set(int *tab, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      tab[i] = -1;
      ++i;
    }
}

int	find_in_tab(int *tab, int nb, int *i)
{
  while (*i < 256 && tab[*i] != nb && tab[*i] != -1)
    ++(*i);
  if (tab[*i] == nb)
    return (1);
  else if (*i == 256)
    return (-1);
  return (0);
}

int	remove_from_tab(int *tab, int i)
{
  while (i + 1 < 256 && tab[i + 1] != -1)
    {
      tab[i] = tab[i + 1];
      ++i;
    }
  tab[i] = -1;
  return (0);
}

int	add_to_tab(int *tab, int nb)
{
  int	i;
  int	ret;

  i = 0;
  if ((ret = find_in_tab(tab, nb, &i)) == 0)
    {
      tab[i] = nb;
      return (1);
    }
  else if (ret == 1)
    return (remove_from_tab(tab, i));
  else
    return (-1);
}
