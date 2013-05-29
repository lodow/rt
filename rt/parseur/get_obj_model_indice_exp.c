/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Thu May 16 15:27:40 2013 luc sinet
*/

#include "str.h"
#include "nb.h"
#include "main.h"
#include "model.h"
#include "pars.h"

void	fill_model_tabs(int* indice_tab, int *size,
                      double *fin_tab, double *raw_tab)
{
  int	i;
  int	j;
  int	tmpind;
  int	raw_size;
  int	fin_size;

  i = 0;
  raw_size = size[0];
  fin_size = size[1];
  while (i < 3)
    {
      tmpind = indice_tab[i] - 1;
      if ((tmpind * 3) < (raw_size * 3) && (tmpind >= 0))
        {
          j = 0;
          while (j < 3)
            {
              fin_tab[fin_size * 3 + j] = raw_tab[tmpind * 3 + j];
              j++;
            }
        }
      i++;
    }
  size[1] += 3;
}

void		model_sizeup_fin_tab(t_model * obj)
{
  int		tmpsize;
  double	*tmptab;

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

void		raw_model_t_obj(t_obj **objtab, t_model * model, t_obj * baseobj)
{
  int		nb_tri;
  int		sizeobj;
  int		i;

  nb_tri = model->fin_size_vertice / 3;
  sizeobj = 0;
  baseobj->type = 6;
  while ((*objtab)[sizeobj].type != -1)
    sizeobj++;
  if (((*objtab) = adjust_mem_size((void *)*objtab, sizeobj * sizeof(t_obj),
                                   (sizeobj + nb_tri + 1) * sizeof(t_obj), 1))
      == NULL)
    return ;
  i = 0;
  while (i < nb_tri)
    {
      (*objtab)[i + sizeobj] = *baseobj;
      calc_vec(&(model->fin_vertice[i * 3]), &(model->fin_normal[i * 3]),
               &((*objtab)[i + sizeobj]));
      i++;
    }
  (*objtab)[i + sizeobj].type = -1;
}

void		init_model_struct(t_model * model)
{
  model->raw_vertice = NULL;
  model->raw_normal = NULL;
  model->raw_uvs = NULL;
  model->fin_vertice = NULL;
  model->fin_normal = NULL;
  model->fin_uvs = NULL;
  model->fin_size_vertice = 0;
  model->fin_size_normal = 0;
  model->fin_size_uvs = 0;
  model->raw_size_vertice = 0;
  model->raw_size_normal = 0;
  model->raw_size_uvs = 0;
}
