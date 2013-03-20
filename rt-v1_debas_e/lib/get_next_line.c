/*
** get_next_line.c for get_next_line in /home/debas_e//projet/get_next_line
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Mon Dec  3 19:08:48 2012 etienne debas
** Last update Sat Mar 16 20:50:09 2013 etienne debas
*/

#include <unistd.h>
#include <stdlib.h>
# define READ 100

char		*xmalloc(int size)
{
  char		*str;

  if ((str = malloc(size)) == NULL)
    exit(EXIT_FAILURE);
  return (str);
}

char		*my_realloc(char *str, int len)
{
  char		*new_line;
  int		i;

  i = 0;
  if ((new_line = malloc(len + READ)) == NULL)
    exit(EXIT_FAILURE);
  while (i < len)
    {
      new_line[i] = str[i];
      i++;
    }
  new_line[i] = 0;
  free(str);
  return (new_line);
}

char		*get_next_line(int fd)
{
  int		i;
  char		*line;
  int		ret;
  char		buff[1];

  i = 0;
  ret = 1;
  line = xmalloc((READ + 2) * sizeof(char));
  buff[0] = -1;
  while (buff[0] != '\n' && ret != 0)
    {
      if ((i % READ) == 0 && i != 0)
	line = my_realloc(line, i);
      ret = read(fd, &buff, 1);
      line[i] = buff[0];
      if (line[i] == '\n')
	line[i] = 0;
      i++;
    }
  if (ret == 0)
    return (NULL);
  return (line);
}
