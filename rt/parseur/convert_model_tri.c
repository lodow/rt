/*
** calc_vec.c for calc_vec in /home/adrien/Projet/rt/rt/parseur
**
** Made by Adrien Della Maggiora
** Login   <adrien@mint>
**
** Started on  Wed May  8 18:10:25 2013 Adrien Della Maggiora
** Last update Mon May 13 15:12:19 2013 luc sinet
*/

#include "main.h"
#include "model.h"

void	convert_model_t_obj(double *vert, double *normal,
                          UNUSED double *uvs, t_obj *obj)
{
  obj->v1[0] = (vert[0] - vert[3]);
  obj->v1[1] = (vert[1] - vert[4]);
  obj->v1[2] = (vert[2] - vert[5]);
  obj->v2[0] = (vert[6] - vert[3]);
  obj->v2[1] = (vert[7] - vert[4]);
  obj->v2[2] = (vert[8] - vert[5]);
  obj->pos[0] += vert[3];
  obj->pos[1] += vert[4];
  obj->pos[2] += vert[5];
  obj->normal[0] = normal[0];
  obj->normal[1] = normal[1];
  obj->normal[2] = normal[2];
}

void		free_obj_model(t_model *model)
{
  if (model != NULL)
    {
      free(model->fin_vertice);
      free(model->fin_normal);
      free(model->fin_uvs);
      free(model->raw_normal);
      free(model->raw_uvs);
      free(model->raw_vertice);
      free(model);
    }
}
