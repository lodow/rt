/*
** inter.h for render in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Feb 26 05:58:41 2013 luc sinet
** Last update Mon Mar 25 19:37:10 2013 luc sinet
*/

#ifndef REND_H_
# define REND_H_

double	sphere(double *cam, double *vec, t_obj *ept);
double	cone(double *cam, double *vec, t_obj *ept);
double	plan(double *cam, double *vec, t_obj *ept);
double	cylinder(double *cam, double *vec, t_obj *ept);

#endif
