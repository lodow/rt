/*
** mem.c for mem in /home/izissise/work/mem
**
** Made by Hugues
** Login   <izissise@morissh>
**
** Started on  Sun May  5 16:42:55 2013 Hugues
** Last update Wed May 15 16:44:17 2013 luc sinet
*/

#include <unistd.h>
#include "main.h"

void	my_putbyte(const void *ptr, int fd, int strlen)
{
  int	len;
  char	*str;

  len = 0;
  str = (char*)ptr;
  if (str != NULL)
    {
      if (strlen == -1)
        {
          while (str[len] != '\0')
            len++;
          strlen = len;
        }
      while ((len = write(fd, str, strlen)) != strlen)
        {
          if (len == -1)
            {
              my_perror("Write");
              return ;
            }
          str = &(str[len]);
          strlen -= len;
        }

    }
}

void	my_memset(void *elem, int val, int size)
{
  int	i;
  char	*ptr;

  ptr = elem;
  i = 0;
  while (i < size)
    ptr[i++] = val;
}

void	my_mem_cpy(void *dest, void *src, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      ((char*)dest)[i] = ((char*)src)[i];
      i++;
    }
}

void	*adjust_mem_size(void *mem, int size, int nsize, int dfree)
{
  void	*res;

  if ((res = malloc(nsize)) == NULL)
    return (NULL);
  if (nsize >= size)
    my_mem_cpy(res, mem, size);
  else
    my_mem_cpy(res, mem, nsize);
  if (dfree)
    free(mem);
  return (res);
}
