/*
** detect_edge.c for detect_edge in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Apr  8 17:01:54 2013 luc sinet
** Last update Thu May  9 10:32:36 2013 Adrien Della Maggiora
*/

#include "main.h"
#include "supersampling.h"
#include "pp_image.h"

void	check_x_value(double **img, int *timg)
{
  int	diff;

  diff = get_color_diff(img[0][1], img[WINX][1]);
  if (img[0][0] != img[1][0] || diff > 20)
    {
      timg[0] = -1;
      timg[1] = -1;
    }
}

void	check_y_value(double **img, int *timg)
{
  int	diff;

  diff = get_color_diff(img[0][1], img[WINX][1]);
  if (img[0][0] != img[WINX][0] || diff > 20)
    {
      timg[0] = -1;
      timg[WINX] = -1;
    }
}

void	compare_img_val(int *pos, double **img, int *timg, int opt)
{
  if (opt == 0)
    check_x_value(&img[pos[1] * WINX + pos[0]], &timg[pos[1] * WINX + pos[0]]);
  else
    check_y_value(&img[pos[1] * WINX + pos[0]], &timg[pos[1] * WINX + pos[0]]);
}

void		fill_img_param(int *pos, unsigned int color,
			       t_rt *rpt, t_par *ppt)
{
  ppt->img_obj[pos[1] * WINX + pos[0]][0] = rpt->obj_num;
  ppt->timg_obj[pos[1] * WINX + pos[0]] = rpt->obj_num;
  ppt->img_obj[pos[1] * WINX + pos[0]][1] = color;
}

void		detect_edge(t_rt *rpt, t_par *ppt)
{
  double	**img;
  int		*timg;
  int		pos[2];

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
