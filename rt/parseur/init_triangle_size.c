/*
** init_triangle_size.c for init_triangle_size in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon May 13 15:13:15 2013 luc sinet
** Last update Mon May 13 17:39:58 2013 luc sinet
*/

#include "main.h"
#include "pars.h"

void	init_triangle_size(t_obj *obj)
{
  int	i;
  int	x;

  i = 0;
  while (obj[i].type != -1)
    {
      if (obj[i].type == TRIANGLE)
	{
	  x = 0;
	  while (x < 3)
	    {
	      obj[i].v1[x] *= obj[i].size[0];
	      obj[i].v2[x] *= obj[i].size[0];
	      ++x;
	    }
	}
      ++i;
    }
}
