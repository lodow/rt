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

float	call_obj_func(t_cam *cam, t_obj *obj)
{
  if (obj->type == SPHERE)
    return (sphere(cam, obj->r));
  if (obj->type == PLAN)
    return (plan(cam, &(obj->normale), obj->r));
  if (obj->type == CYLINDRE)
    return (cylindre(cam, obj->r));
  if (obj->type == CONE)
    return (cone(cam, obj->r));
  return (-1);
}

void		calc_pix_inter(t_img_compo *pix, t_scene * scene,
                       int sizex, int sizey)
{
  t_cam		cam;
  float		dist;
  int		i;
  t_obj		*obj;

  i = 0;
  scene->cam.dir.x = 6000 - scene->cam.pos.x;
  scene->cam.dir.y = ((float)sizex / 2.0) - pix->pix.x - scene->cam.pos.y;
  scene->cam.dir.z = ((float)sizey / 2.0) - pix->pix.y - scene->cam.pos.z;
  cam = scene->cam;
  while ((obj = scene->objs[i]) != NULL)
    {
      cam = scene->cam;
      add_vect(&(cam.pos), &(obj->pos), &(cam.pos));
      dist = call_obj_func(&cam, obj);
      if ((dist > 0.001) && (dist < pix->depth))
        {
          pix->depth = dist;
          pix->pix.color = obj->color;
          pix->obj = obj;
        }
      i++;
    }
}

void	init_pix_compo(t_img_compo *pix)
{
  init_color(0, 0, 0, &(pix->pix.color));
  init_vect(0, 0, 0, &(pix->normal));
  init_vect(0, 0, 0, &(pix->wposition));
  pix->depth = INFINITY;
}

void	calc_img_pixx(t_rt_img * img, t_init_x *win)
{
  init_pix_compo(&(img->cur_pix));
  calc_pix_inter(&(img->cur_pix), &(img->scene), img->sizex, img->sizey);
  put_pixel_img(win, img->cur_pix.pix.x, img->cur_pix.pix.y,
                &(img->cur_pix.pix.color));
  img->cur_pix.pix.x = (img->cur_pix.pix.x + 1) % img->sizex;
  if (img->cur_pix.pix.x == 0)
    img->cur_pix.pix.y = (img->cur_pix.pix.y + 1) % img->sizey;
  if ((img->cur_pix.pix.y == 0) && (img->cur_pix.pix.x == 0))
    img->end = 1;
}
