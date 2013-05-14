/*
** init_shadows.c for init_shadows.c in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue May 14 17:09:58 2013 luc sinet
** Last update Tue May 14 17:21:55 2013 luc sinet
*/

void	init_points(t_shadow *spt, t_lco *lpt)
{
  int	i;

  i = 0;
  spt->i = 1;
  spt->points[0][0] = 1;
  while (i < 4)
    {
      if (i < 3)
	spt->points[0][i + 1] = lpt->obj_coor[i];
      spt->points[1][i] = -1;
    }
}

void		handle_included_obj(t_shadow *spt)
{
  unsigned int	distance;
  int		i;

  distance = point_distance(&spt->points[0][1], &spt->points[1][1]);
  while (i < 4)
    {
      spt->points[0][i] = spt->points[1][i];
      spt->points[1][i] = -1;
      ++i;
    }
}

void   	init_shadows(t_shadow *spt, t_rt *rpt, double *cpos, t_lco *lpt)
{
  spt->slpt = lpt;
  spt->sdw_coef = 1.0;
  spt->vpos = rpt->vpt->vec;
  copy_tab(spt->vpos, spt->vec, 3);
  copy_tab(cpos, spt->cam, 3);
  copy_tab(lpt->obj_coor, spt->inter, 3);
  spt->obj[0] = rpt->obj_num;
  spt->hit = 0;
  init_points(spt, lpt);
}
