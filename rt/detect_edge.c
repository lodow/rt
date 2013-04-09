/*
** detect_edge.c for detect_edge in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Apr  8 17:01:54 2013 luc sinet
** Last update Wed Apr 10 01:43:42 2013 luc sinet
*/

#include "main.h"
#include "supersampling.h"
#include "pp_image.h"

void	check_x_value(int **img, int **timg)
{
  if (img[0][0] != img[1][0])
    {
      timg[0][0] = -1;
      timg[1][0] = -1;
    }
}

void	check_y_value(int **img, int **timg)
{
  if (img[0][0] != img[WINX][0])
    {
      timg[0][0] = -1;
      timg[WINX][0] = -1;
    }
}

void	compare_img_val(int *pos, int **img, int **timg, int opt)
{
  if (opt == 0)
    check_x_value(&img[pos[1] * WINX + pos[0]], &timg[pos[1] * WINX + pos[0]]);
  else
    check_y_value(&img[pos[1] * WINX + pos[0]], &timg[pos[1] * WINX + pos[0]]);
}

void	fill_img_param(int x, int y, t_rt *rpt, t_par *ppt)
{
  ppt->img_obj[y * WINX + x][0] = rpt->obj_num;
  ppt->timg_obj[y * WINX + x][0] = rpt->obj_num;
}

void	detect_edge(t_rt *rpt, t_par *ppt)
{
  int	**img;
  int	**timg;
  int	pos[2];

  (void)*rpt;
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
