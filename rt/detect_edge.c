/*
** detect_edge.c for detect_edge in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Apr  8 17:01:54 2013 luc sinet
** Last update Mon Apr  8 21:30:37 2013 luc sinet
*/

#include "main.h"
#include "supersampling.h"
#include "pp_image.h"

void	check_x_value(int x, int *img, int *timg)
{
  if (img[x] != img[x + 1])
    {
      timg[x] = -1;
      timg[x + 1] = -1;
    }
}

void	check_y_value(int *pos, int **img, int **timg)
{
  if (img[pos[1]][pos[0]] != img[pos[1] + 1][pos[0]])
    {
      timg[pos[1]][pos[0]] = -1;
      timg[pos[1] + 1][pos[0]] = -1;
    }
}

void	compare_img_val(int *pos, int **img, int **timg, int opt)
{
  if (opt == 0)
    check_x_value(pos[0], img[pos[1]], timg[pos[1]]);
  else
    check_y_value(pos, img, timg);
}

void	detect_edge(t_rt *rpt, t_samp *spt, t_par *ppt)
{
  int	**img;
  int	**timg;
  int	pos[2];

  img = ppt->img_obj;
  timg = ppt->timg_obj;
  pos[1] = 0;
  print_i(ppt);
  while (pos[1] < WINY - 1)
    {
      pos[0] = 0;
      while (pos[0] < WINX - 1)
	{
	  compare_img_val(pos, img, timg, 0);
	  compare_img_val(pos, img, timg, 1);
	  ++pos[0];
	}
      ++pos[1];
    }
}
