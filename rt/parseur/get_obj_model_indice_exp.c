/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "../include/str.h"
#include "../include/nb.h"
#include "../include/main.h"
#include "../include/model.h"
#include "../include/pars.h"

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
