/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "include.h"

void	get_scene_objs(char *filename, t_scene *scene)
{
  t_obj	*tmp;

  scene->objs = NULL;
  tmp = malloc(1 * sizeof(t_obj));
  tmp->type = SPHERE;
  tmp->r = 19;
  init_color(255, 0, 0, &(tmp->color));
  init_vect(0, -60, 0, &(tmp->pos));
  scene->objs = (t_obj**)add_ptr_t_tab((void**)scene->objs, (void*)tmp);
  tmp = malloc(1 * sizeof(t_obj));
  tmp->type = PLAN;
  init_vect(0.5, 0, -0.52, &(tmp->normale));
  tmp->r = 0.1;
  init_color(0, 0, 255, &(tmp->color));
  scene->objs = (t_obj**)add_ptr_t_tab((void**)scene->objs, (void*)tmp);
  tmp = malloc(1 * sizeof(t_obj));
  tmp->r = 5;
  tmp->type = CYLINDRE;
  init_vect(6, -75, 0, &(tmp->pos));
  init_color(0, 255, 0, &(tmp->color));
  scene->objs = (t_obj**)add_ptr_t_tab((void**)scene->objs, (void*)tmp);
  tmp = malloc(1 * sizeof(t_obj));
  tmp->r = 75;
  tmp->type = CONE;
  init_vect(6, 50, -50, &(tmp->pos));
  init_color(128, 128, 0, &(tmp->color));
  scene->objs = (t_obj**)add_ptr_t_tab((void**)scene->objs, (void*)tmp);
}
