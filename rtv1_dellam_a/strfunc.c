/*
** strfunc.c for strfunc in /home/welanor/Projet/Igraph/RT_V1
** 
** Made by Adrien dellamaggiora
** Login   <dellam_a@epitech.eu>
** 
** Started on  Fri Feb  8 15:54:35 2013 Adrien dellamaggiora
** Last update Tue Mar 12 18:58:10 2013 Adrien
*/

#include "include.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}

char	*sub_tab(char *str)
{
  char	*res;
  int	i;
  int	j;

  if ((res = malloc(my_strlen(str) + 1)) == NULL)
    exit(0);
  i = 0;
  j = 0;
  while (str[i] != 0)
    {
      if (str[i] != '\t')
	res[j++] = str[i];
      else
	res[j++] = ' ';
      i++;
    }
  res[j] = 0;
  free(str);
  return (res);
}

char	*sub_space(char *str)
{
  int	i;
  int	j;
  char	*res;

  if ((res = malloc(my_strlen(str) + 2)) == NULL)
    exit(0);
  str = sub_tab(str);
  i = 0;
  j = 0;
  while (str[i] == ' ' && str[i] != 0)
    i++;
  while (str[i] != 0)
    {
      if (str[i] == ' ' && str[i + 1] != ' ')
	res[j++] = str[i];
      else if (str[i] != ' ')
	res[j++] = str[i];
      i++;
    }
  res[j] = 0;
  free(str);
  return (res);
}

void	my_putstr(char *str)
{
  if (str != NULL)
    write(1, str, my_strlen(str));
}

int	my_strncmp(char *s1, char *s2, int nb)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0 && i < nb)
    i++;
  if (i == nb)
    return (1);
  return (0);
}
