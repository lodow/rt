/*
** return_char.c for return_char in /home/remi/Projet/minitalk/client
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Mon Mar 18 09:28:48 2013 remi
** Last update Sat Jun  8 18:03:11 2013 remi
*/

#include "my_func.h"

void	return_buff(char *buff)
{
  int	indice_begin;
  int	indice_end;
  char	temp_char;

  indice_begin = 0;
  indice_end = my_strlen(buff) - 1;
  while (indice_begin < my_strlen(buff) && indice_end >= 0)
    {
      temp_char = buff[indice_begin];
      buff[indice_begin] = buff[indice_end];
      buff[indice_end] = temp_char;
      indice_begin = indice_begin + 1;
      indice_end = indice_end - 1;
      if (indice_end == indice_begin ||
	  indice_begin - indice_end == 1)
	return ;
    }
}

char		*convert_number_char(int number, char *tab, int indice)
{
  if (indice >= 49 || number / 10 == 0)
    {
      tab[indice] = number + '0';
      indice = indice + 1;
      while (indice <= 5)
	{
	  tab[indice] = '0';
	  indice = indice + 1;
	}
      tab[indice] = '\0';
      return_buff(tab);
      indice = 0;
      return (tab);
    }
  tab[indice] = number % 10 + '0';
  tab[indice + 1] = '\0';
  indice = indice + 1;
  tab = convert_number_char(number / 10, tab, indice);
  return (tab);
}
