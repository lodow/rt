/*
** aliasing.c for aliasing in /home/sinet_l//rtv1-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri Mar 15 18:22:17 2013 luc sinet
** Last update Sun Mar 17 11:23:18 2013 luc sinet
*/

#include "main.h"
#include "aliasing.h"
#include "mlx.h"

void	get_color(t_par *ppt, t_col *cpt, int x, int y)
{
  unsigned int	pos;

  pos = y * ppt->sizeline + x * (ppt->bpp / 8);
  cpt->b = ppt->data[pos];
  cpt->g = ppt->data[pos + 1];
  cpt->r = ppt->data[pos + 2];
}

unsigned char	comp_diff(unsigned char	cp, t_col *col, int type)
{
  int		i;
  int		diff;
  int		new_color;
  int		new_comp;
  unsigned char	comp_color[4];

  i = 0;
  new_color = cp;
  comp_color[0] = COLOR_COMP(type, col[0].b, col[0].g, col[0].r);
  comp_color[1] = COLOR_COMP(type, col[1].b, col[1].g, col[1].r);
  comp_color[2] = COLOR_COMP(type, col[2].b, col[2].g, col[2].r);
  comp_color[3] = COLOR_COMP(type, col[3].b, col[3].g, col[3].r);
  while (i < 4)
    {
      diff = cp - comp_color[i];
      diff = ABS(diff);
      new_comp = CHECK_DIFF(cp, comp_color[i], diff);
      new_color += new_comp;
      i++;
    }
  return (new_color / 5);
}

int		mix_color(t_calc *cpt, t_col *cor, t_par *ppt)
{
  unsigned int	pos;
  unsigned char	c_pixel[3];
  unsigned int	new_color;

  pos = cpt->y * ppt->sizeline + cpt->x * (ppt->bpp / 8);
  c_pixel[0] = ppt->data[pos];
  c_pixel[1] = ppt->data[pos + 1];
  c_pixel[2] = ppt->data[pos + 2];
  c_pixel[0] = comp_diff(c_pixel[0], cor, 0);
  c_pixel[1] = comp_diff(c_pixel[1], cor, 1);
  c_pixel[2] = comp_diff(c_pixel[2],  cor, 2);
  new_color = c_pixel[2] << 8;
  new_color = (new_color | c_pixel[1]) << 8;
  new_color = (new_color | c_pixel[0]);
  return (new_color);
}

int		calc_new_color(t_col *cor, t_par *ppt, t_calc *cpt)
{
  unsigned int	color;

  get_color(ppt, &cor[0], cpt->x - 1, cpt->y);
  get_color(ppt, &cor[1], cpt->x + 1, cpt->y);
  get_color(ppt, &cor[2], cpt->x, cpt->y - 1);
  get_color(ppt, &cor[3], cpt->x, cpt->y + 1);
  color = mix_color(cpt, cor, ppt);
  return (color);
}

void		aliasing(t_par *ppt)
{
  t_col		cor[4];
  t_calc	cpt;

  cpt.y = 1;
  while (cpt.y < WINY - 1)
    {
      cpt.x = 1;
      while (cpt.x < WINX - 1)
	{
	  my_pixel_put_to_image(cpt.x, cpt.y, ppt,
				calc_new_color(cor, ppt, &cpt));
	  ++cpt.x;
	}
      ++cpt.y;
    }
}
