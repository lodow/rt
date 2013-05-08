/*
** mem.c for mem in /home/izissise/work/mem
** 
** Made by Hugues
** Login   <izissise@morissh>
** 
** Started on  Sun May  5 16:42:55 2013 Hugues
** Last update Tue May  7 14:49:54 2013 Hugues
*/

#include <stdlib.h>

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
