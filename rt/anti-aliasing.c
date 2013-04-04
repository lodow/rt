/*
** anti-aliasing.c for anti aliasing in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Apr  2 19:51:46 2013 luc sinet
** Last update Wed Apr  3 15:05:13 2013 luc sinet
*/

#include "mlx.h"
#include "pp_image.h"
#include "aliasing.h"

void		get_p_color(unsigned char *col, t_par *ppt, int x, int y)
{
  unsigned int	pos;

  pos = y * ppt->sizeline + x * (ppt->bpp / 8);
  col[2] = ppt->data[pos];
  col[1] = ppt->data[pos + 1];
  col[0] = ppt->data[pos + 2];
}

int	comp_diff(unsigned char *icomp, unsigned char *tcomp)
{
  int	diff;
  int	i;

  i = 0;
  diff = 0;
  while (i < 3)
    {
      diff += (icomp[i] + tcomp[i]) / (2.0 * 2.55);
      ++i;
    }
  return (diff / 3);
}

void	apply_aliasing(int diff, unsigned char *icomp, unsigned char *fcomp)
{
  int	i;

  i = 0;
  if (diff >= COLOR_RATIO)
    {
      while (i < 3)
	{
	  icomp[i] = AVERAGE(fcomp[i], icomp[i]);
	  ++i;
	}
    }
}

unsigned int	mix_colors(t_par *ppt, t_ali *pal)
{
  get_p_color(pal->icomp, ppt, pal->x, pal->y);
  get_p_color(pal->fcomp, ppt, pal->x, pal->y);
  get_p_color(pal->tcomp, ppt, pal->x - 1, pal->y - 1);
  apply_aliasing(comp_diff(pal->fcomp, pal->tcomp), pal->fcomp, pal->tcomp);
  get_p_color(pal->tcomp, ppt, pal->x - 1, pal->y + 1);
  apply_aliasing(comp_diff(pal->fcomp, pal->tcomp), pal->fcomp, pal->tcomp);
  get_p_color(pal->tcomp, ppt, pal->x + 1, pal->y - 1);
  apply_aliasing(comp_diff(pal->fcomp, pal->tcomp), pal->fcomp, pal->tcomp);
  get_p_color(pal->tcomp, ppt, pal->x + 1, pal->y + 1);
  apply_aliasing(comp_diff(pal->fcomp, pal->tcomp), pal->fcomp, pal->tcomp);
  return (recomp_color(pal->fcomp));
}

void	anti_aliasing(t_par *ppt)
{
  t_ali	pal;

  pal.y = 1;
  pal.ratio = 0;
  while (pal.ratio < AA)
    {
      while (pal.y < WINY - 1)
	{
	  pal.x = 1;
	  while (pal.x < WINX - 1)
	    {
	      my_pixel_put_to_image(pal.x, pal.y, ppt, mix_colors(ppt, &pal));
	      ++(pal.x);
	    }
	  ++(pal.y);
	}
      ++(pal.ratio);
    }
}
