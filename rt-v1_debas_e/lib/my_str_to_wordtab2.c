/*
** my_str_to_wordtab2.c for str2wordtab in /home/debas_e//minishell1-2017-debas_e/lib
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Thu Mar  7 15:18:20 2013 etienne debas
** Last update Tue Mar 12 22:12:35 2013 etienne debas
*/

# include "../lib.h"

int		count_word(char *str, char sepa)
{
  int		i;
  int		nb_word;

  nb_word = 0;
  i = 0;
  if (str == NULL)
    return (0);
  while ((str[i] == sepa) && str[i])
    i++;
  while (str[i])
    {
      if (str[i] == sepa)
	nb_word++;
      while (str[i] == sepa)
	i++;
      i++;
    }
  if (str[my_strlen(str) - 1] == sepa)
    return (nb_word);
  return (nb_word + 1);
}

char		*get_word(int begin, int end, char *str)
{
  char		*word;
  int		i;

  i = 0;
  if ((word = malloc((end - begin + 1) * sizeof(char))) == NULL)
    exit (0);
  while (begin < end)
    word[i++] = str[begin++];
  word[i] = 0;
  return (word);
}
