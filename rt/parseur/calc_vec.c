/*
** calc_vec.c for calc_vec in /home/adrien/Projet/rt/rt/parseur
** 
** Made by Adrien Della Maggiora
** Login   <adrien@mint>
** 
** Started on  Wed May  8 18:10:25 2013 Adrien Della Maggiora
** Last update Wed May  8 18:13:52 2013 Adrien Della Maggiora
*/

void	calc_vec(double *pt, double *v1, double *v2)
{
  v1[0] = pt[0] - pt[3];
  v1[1] = pt[1] - pt[4];
  v1[2] = pt[2] - pt[5];
  v2[0] = pt[6] - pt[3];
  v2[1] = pt[7] - pt[4];
  v2[2] = pt[8] - pt[5];
}
