/*
** model.h for jqsl in /home/izissise/work/rt/rt/include
**
** Made by moriss_h
** Login   <moriss_h@epitech.net>
**
** Started on  Tue May  7 14:55:53 2013 Hugues
** Last update Tue May  7 14:56:13 2013 Hugues
*/

#ifndef MODEL_H_
# define MODEL_H_

# include "main.h"

typedef struct	s_model
{
  double	*raw_vertice;
  double	*raw_normal;
  double	*raw_uvs;
  int		raw_size_vertice;
  int		raw_size_normal;
  int		raw_size_uvs;
  double	*fin_vertice;
  double	*fin_normal;
  double	*fin_uvs;
  int		fin_size_vertice;
  int		fin_size_normal;
  int		fin_size_uvs;
}		t_model;

t_model	*get_file_obj_model(const char *filename);
void		model_sizeup_fin_tab(t_model *obj);
void		fill_model_tabs(t_model *obj, int *vert, int *uvv, int *norm);
void		raw_model_t_obj(t_obj **objtab, t_model *model, t_obj *baseobj);

#endif
