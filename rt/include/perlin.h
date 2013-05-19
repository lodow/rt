/*
** perlin.h for perlin in /home/sinet_l//rt/rt
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun May 19 10:03:06 2013 luc sinet
** Last update Sun May 19 18:08:33 2013 luc sinet
*/

#ifndef PERLIN_H_
# define PERLIN_H_

# define C1_R col[0]
# define C1_G col[1]
# define C1_B col[2]
# define C2_R col[3]
# define C2_G col[4]
# define C2_B col[5]
# define C3_R col[6]
# define C3_G col[7]
# define C3_B col[8]

typedef struct s_perlin
{
  double	sval[3];
  double	col[9];
  double	pn;
}		t_perlin;

#endif
