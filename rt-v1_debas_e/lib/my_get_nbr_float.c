/*
** my_get_nbr_float.c for my_get_nbr_float in /home/debas_e//Desktop/projet/rt-v1
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Sun Mar 17 02:36:41 2013 etienne debas
** Last update Sun Mar 17 03:12:38 2013 etienne debas
*/

void		cut_nbr_float(char *str, int *first, int *second)
{
  int		result;

  result = 0;
  while ((*str >= '0') && (*str <= '9') &&
	 ((*str != '.') || (*str != ',')))
    {
      *first = (*first * 10) + ((*str) - '0');
      str++;
    }
  if (*str == '\0')
    return;
  str++;
  while ((*str >= '0') && (*str <= '9'))
    {
      *second = (*second * 10) + ((*str) - '0');
      str++;
    }
}

float		cat_nbr(int first, int second)
{
  int		puiss;
  float		result;

  result = (float)first;
  puiss = 1;
  while ((second / puiss) != 0)
    puiss *= 10;
  result += ((float)second / (float)puiss);
  return (result);
}

float		my_getnbr_float(char *str)
{
  int		first;
  int		second;
  int		puiss;
  float		result;

  puiss = 0;
  first = 0;
  second = 0;
  result = 0;
  while (((*str) == '-') || (*str == '+'))
    {
      if (*str == '-')
	puiss = puiss * -1;
      str = str + 1;
    }
  cut_nbr_float(str, &first, &second);
  result = cat_nbr(first, second);
  return (result);
}
