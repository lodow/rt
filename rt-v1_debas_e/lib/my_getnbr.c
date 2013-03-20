/*
** my_getnbr.c for my_getnbr in /home/debas_e//projet/push_swap
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Wed Jan  2 17:59:04 2013 etienne debas
** Last update Sun Mar 17 02:59:09 2013 etienne debas
*/

int		my_getnbr(char *str)
{
  int		result;
  int		puiss;

  result = 0;
  puiss = 1;
  while (((*str) == '-') || (*str == '+'))
    {
      if (*str == '-')
	puiss = puiss * -1;
      str = str + 1;
    }
  while ((*str >= '0') && (*str <= '9'))
    {
      result = (result * 10) + ((*str) - '0');
      str = str + 1;
    }
  return (result * puiss);
}
