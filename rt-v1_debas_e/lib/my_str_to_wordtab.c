/*
** my_str_to_wordtab.c for str2wordtab in /home/debas_e//projet/minishell1
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Mon Dec 17 17:06:29 2012 etienne debas
** Last update Sun Mar 17 15:59:58 2013 etienne debas
*/

# include "../lib.h"

void		supress_space(char *str, char **tab, char sepa)
{
  int		i;
  int		j;
  int		cur_word;

  cur_word = 0;
  i = 0;
  j = 0;
  while ((str[i] == sepa) && str[i++])
    j++;
  while (str[i])
    {
      if (str[i] == sepa)
	{
	  tab[cur_word++] = get_word(j, i, str);
	  j = i + 1;
	  i++;
	  while (str[i++] == sepa)
	    j++;
	}
      else
	i++;
    }
  tab[cur_word++] = get_word(j, i, str);
}

int		epur_and_check(char *str)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i])
    if (str[i] != ' ' && str[i] != '\t')
      str[j++] = str[i++];
    else
      {
	str[j++] = ' ';
	while (str[i] == ' ' || str[i] == '\t')
	  i++;
      }
  str[j] = 0;
  if (str[0] == 0)
    return (0);
  if (str[j - 1] == ' ')
    str[j - 1] = '\0';
  return (1);
}

void		epur_tab(char **tab)
{
  int		i;
  int		j;

  i = 0;
  while (tab[i])
    {
      if (epur_and_check(tab[i]) == 0)
	{
	  j = i;
	  free(tab[i]);
	  while (tab[j])
	    tab[j] = tab[++j];
	}
      else
	i++;
    }
}

char		**my_str_to_word_tab(char *str, char sepa)
{
  char		**tab_str;
  int		nb_word;

  if (my_strcmp(str, "\n") == 1)
    str[0] = 0;
  if (str != NULL && my_strlen(str) != 0)
    {
      if (str[my_strlen(str) - 1] == '\n')
	str[my_strlen(str) - 1] = 0;
      nb_word = count_word(str, sepa);
      if ((tab_str = malloc((nb_word + 1) * sizeof(char *))) == NULL)
	my_perror(PBALLOC);
      supress_space(str, tab_str, sepa);
      tab_str[nb_word] = NULL;
      epur_tab(tab_str);
      return (tab_str);
    }
  return (NULL);
}
