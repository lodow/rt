/*
** init_opt.c for rt in /home/dellam_a/Projet/rt/rt/parseur
**
** Made by Adrien Della Maggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Fri Apr 12 15:50:58 2013 Adrien Della Maggiora
** Last update Fri Apr 12 17:38:59 2013 Adrien Della Maggiora
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/main.h"
#include "../include/get_next_line.h"
#include "../include/pars.h"

void	init_opt(t_rt *rpt)
{
  rpt->opt->aa = 1;
  rpt->opt->fog[0] = 0x000000;
  rpt->opt->fog[1] = -1;
}

void	get_opt_fog(t_opt *opt, char *line)
{
  int	i;

  i = 0;
  opt->fog[0] = my_getnbr_base(line, "0123456789ABCDEF");
  printf("%s | %X\n", line, (int)opt->fog[0]);
  skip_adds(line, &i);
  opt->fog[1] = my_fgetnbr(&line[i]);
  printf("%s | %f\n", &line[i], opt->fog[1]);
}

int	get_opt_carac(t_opt *opt, int fd)
{
  int	i;
  char	*line;

  free((line = get_next_line(fd)));
  while (my_strcmp((line = get_next_line(fd)), "}") != 0)
    {
      i = 0;
      while (line[i] == ' ')
        ++i;
      if (my_strncmp(&line[i], "AA = ", 5) == 0)
	opt->aa = my_getnbr(line);
      else if (my_strncmp(&line[i], "FOG = ", 6) == 0)
	get_opt_fog(opt, &line[i + 6]);
      else
	{
	  my_putstr("Line ", 2);
	  my_putstr(line, 2);
          return (merror(" is invalid\n", -1));
        }
      free(line);
    }
  return (0);
}

int	fill_opt(t_rt *rpt, char *fname)
{
  int	fd;
  char	*line;

  init_opt(rpt);
  if ((fd = open(fname, O_RDONLY)) == -1)
    return (merror("Couldn't open the file", -1));
  while ((line = get_next_line(fd)))
    {
      if (my_strcmp(line, "Option") == 0 && get_opt_carac(rpt->opt, fd) == -1)
	return (-1);
      free(line);
    }
  close (fd);
  return (0);
}
