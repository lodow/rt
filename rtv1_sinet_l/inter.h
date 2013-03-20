/*
** inter.h for render in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Feb 26 05:58:41 2013 luc sinet
** Last update Tue Feb 26 06:00:41 2013 luc sinet
*/

#ifndef REND_H_
# define REND_H_

double	sphere(t_cam *cpt, t_vec *vpt, t_elem *ept);
double	cone(t_cam *cpt, t_vec *vpt, t_elem *ept);
double	plan(t_cam *cpt, t_vec *vpt, t_elem *ept);
double	cylinder(t_cam *cpt, t_vec *vpt, t_elem *ept);

#endif
