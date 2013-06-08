/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat Jun  8 15:56:18 2013 maxime lavandier
*/

#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

void	my_perror(char *str)
{
  char	*error;
  int	ret;

  ret = 0;
  error = strerror(errno);
  if (str != NULL)
    {
      ret = write(2, str, my_strlen(str));
      ret = write(2, ": ", 2);
    }
  if (error != NULL)
    ret = write(2, error, my_strlen(error));
  if (ret != -1)
    ret = write(2, "\n", 1);
}

int	check_perror(char *str, int err)
{
  if (err == -1)
    my_perror(str);
  return (err);
}
