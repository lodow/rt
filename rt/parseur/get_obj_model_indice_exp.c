/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Thu May  9 10:28:52 2013 Adrien Della Maggiora
*/

#include "str.h"
#include "nb.h"
#include "main.h"
#include "model.h"
#include "pars.h"

void		cpy_model_xyz(double *dest, int pos, double *src, int posrc)
{
  int		j;

  j = 0;
  while (j < 3)
    {
      dest[pos + j] = src[posrc + j];
      j++;
    }
}

void		fill_model_tabs(t_model *obj, int *vert, int *uvs, int *norm)
{
  int		i;
  int		tmpind;

  i = 0;
  while (i < 3)
    {
      tmpind = vert[i] - 1;
      if ((tmpind * 3) < obj->raw_size_vertice && tmpind >= 0)
        cpy_model_xyz(obj->fin_vertice, obj->fin_size_vertice * 3,
                      obj->raw_vertice, tmpind * 3);
      i++;
    }
  obj->fin_size_vertice += 3;
  /* i = 0;
   while (i < 3)
     {
       tmpind = uvs[i] - 1;
       if ((tmpind * 3) < obj->raw_size_uvs && tmpind >= 0)
         cpy_model_xyz(obj->fin_uvs, obj->fin_size_uvs * 3,
                       obj->raw_uvs, tmpind * 3);
       i++;
     }
   obj->fin_size_uvs += 3;*/
  i = 0;
  while (i < 3)
    {
      tmpind = norm[i] - 1;
      if ((tmpind * 3) < obj->raw_size_normal && tmpind >= 0)
        cpy_model_xyz(obj->fin_normal, obj->fin_size_normal * 3,
                      obj->raw_normal, tmpind * 3);
      i++;
    }
  obj->fin_size_normal += 3;
}

void		model_sizeup_fin_tab(t_model *obj)
{
  int		tmpsize;
  double		*tmptab;

  tmpsize = obj->fin_size_vertice * 3;
  tmptab = obj->fin_vertice;
  if ((tmptab = adjust_mem_size((void*)tmptab, tmpsize * sizeof(double),
                                (tmpsize + 9) * sizeof(double), 1)) == NULL)
    return ;
  obj->fin_vertice = tmptab;
  tmpsize = obj->fin_size_uvs * 3;
  tmptab = obj->fin_uvs;
  if ((tmptab = adjust_mem_size((void*)tmptab, tmpsize * sizeof(double),
                                (tmpsize + 9) * sizeof(double), 1)) == NULL)
    return ;
  obj->fin_uvs = tmptab;
  tmpsize = obj->fin_size_normal * 3;
  tmptab = obj->fin_normal;
  if ((tmptab = adjust_mem_size((void*)tmptab, tmpsize * sizeof(double),
                                (tmpsize + 9) * sizeof(double), 1)) == NULL)
    return ;
  obj->fin_normal = tmptab;
}

void		raw_model_t_obj(t_obj **objtab, t_model *model, t_obj *baseobj)
{
  int		nb_tri;
  int		sizeobj;
  int		i;

  nb_tri = model->fin_size_vertice / 9;
  sizeobj = 0;
  while ((*objtab)[sizeobj].type != -1)
    sizeobj++;
  (*objtab) = adjust_mem_size((void*)objtab, sizeobj * sizeof(t_obj),
                              (sizeobj + nb_tri) * sizeof(t_obj), 1);
  i = 0;
  while (i < nb_tri)
    {
      (*objtab)[i + sizeobj] = *baseobj;
      calc_vec(&(model->fin_vertice[i * 9]), &((*objtab)[i + sizeobj]));
      i++;
    }
}
