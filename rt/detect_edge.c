/*
** detect_edge.c for detect_edge in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Apr  8 17:01:54 2013 luc sinet
** Last update Sat Jun  1 14:57:31 2013 luc sinet
*/

#include "main.h"
#include "supersampling.h"
#include "pp_image.h"

void	check_x_value(double **img, int *timg, UNUSED t_par *ppt)
{
  int	diff;

  diff = get_color_diff(img[0][1], img[1][1]);
  if (img[0][0] != img[1][0] || diff > 20)
    {
      timg[0] = -1;
      timg[1] = -1;
    }
}

void	check_y_value(double **img, int *timg, t_par *ppt)
{
  int	diff;

  diff = get_color_diff(img[0][1], img[ppt->imgwidth][1]);
  if (img[0][0] != img[ppt->imgwidth][0] || diff > 20)
    {
      timg[0] = -1;
      timg[ppt->imgwidth] = -1;
    }
}

void		fill_img_param(double *dpos, unsigned int color,
                       UNUSED t_rt *rpt, t_par *ppt)
{
  int		pos[2];

  pos[0] = dpos[0];
  pos[1] = dpos[1];
  ppt->img_obj[pos[1] * ppt->imgwidth + pos[0]][0] = rpt->obj_num;
  ppt->timg_obj[pos[1] * ppt->imgwidth + pos[0]] = rpt->obj_num;
  ppt->img_obj[pos[1] * ppt->imgwidth + pos[0]][1] = color;
}

void		detect_edge(UNUSED t_rt *rpt, t_par *ppt)
{
  double	**img;
  int		*timg;
  int		pos[2];

  img = ppt->img_obj;
  timg = ppt->timg_obj;
  pos[1] = 0;
  print_i(ppt);
  while (pos[1] < ppt->imgheight - 1)
    {
      pos[0] = 0;
      while (pos[0] < ppt->imgwidth - 1)
        {
          check_x_value(&img[pos[1] * ppt->imgwidth + pos[0]],
                        &timg[pos[1] * ppt->imgwidth + pos[0]], ppt);
          check_y_value(&img[pos[1] * ppt->imgwidth + pos[0]],
                        &timg[pos[1] * ppt->imgwidth + pos[0]], ppt);
          ++pos[0];
        }
      ++pos[1];
    }
}
