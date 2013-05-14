/*
** shadows_transparency.c for shadows_transparency in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue May 14 18:05:07 2013 luc sinet
** Last update Tue May 14 18:08:22 2013 luc sinet
*/

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

void	handle_transparency(t_shadow *spt, t_rt *rpt, t_obj *obj)
{
  if ()
}
