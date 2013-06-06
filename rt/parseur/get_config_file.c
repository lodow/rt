/*
** get_config_file.c for get_config_file in /home/sinet_l//rt/rt/parseur
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri May  3 16:18:05 2013 luc sinet
** Last update Thu May  9 10:28:08 2013 Adrien Della Maggiora
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"
#include "pars.h"
#include "get_next_line.h"

void	free_old_tab(char **tab, int size)
{
  int	i;

  i = 0;
  while (i < size)
    free(tab[i++]);
  free(tab);
}

char	**remalloc(char **tab, int size)
{
  char	**ntab;
  int	i;

  i = 0;
  if ((ntab = malloc(sizeof(char *) * (size + 256))) == NULL)
    return (NULL);
  while (i < size)
    {
      if ((ntab[i] = my_strdup(tab[i])) == NULL)
	return (NULL);
      ++i;
    }
  free_old_tab(tab, size);
  return (ntab);
}

int	get_file(t_pars *ppt, int fd)
{
  char	*line;
  int	i;

  i = 0;
  if ((ppt->file = malloc(sizeof(char *) * 256)) == NULL)
    return (merror("malloc_error", -1));
  while ((line = get_next_line(fd)))
    {
      if ((ppt->file[i] = my_strdup(line)) == NULL)
	return (merror("Malloc error\n", -1));
      ++i;
      if (i % 255 == 0)
	if ((ppt->file = remalloc(ppt->file, i)) == NULL)
	  return (merror("Malloc error\n", -1));
      free(line);
    }
  ppt->file[i] = '\0';
  return (0);
}

int	get_config_file(t_pars *ppt, char *conf_name)
{
  int	fd;

  if ((fd = check_perror("Open Scene", open(conf_name, O_RDONLY)) == -1))
    return (-1);
  if (get_file(ppt, fd) == -1)
    {
      check_perror("Close", close(fd));
      return (-1);
    }
  check_perror("Close", close(fd));
  return (0);
}
