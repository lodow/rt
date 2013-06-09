/*
** transform_vec.c for transform_vec in /home/adrien/Projet/rt/rt
**
** Made by Adrien Della Maggiora
** Login   <adrien@mint>
**
** Started on  Wed May  8 18:02:00 2013 Adrien Della Maggiora
** Last update Sat Jun  8 18:04:01 2013 etienne debas
*/

void	invert_vec(double *vec)
{
  vec[0] = -vec[0];
  vec[1] = -vec[1];
  vec[2] = -vec[2];
}
