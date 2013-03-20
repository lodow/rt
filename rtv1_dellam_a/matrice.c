/*
** matrice.c for matrice in /home/dellam_a/Projet/Igraph/RT_V1
** 
** Made by Adrien dellamaggiora
** Login   <dellam_a@epitech.eu>
** 
** Started on  Sun Feb 10 12:24:57 2013 Adrien dellamaggiora
** Last update Wed Mar 13 15:36:19 2013 Adrien
*/

#include "include.h"

void	rotate_x(float angle, t_coord *pos)
{
  float	x;
  float	y;
  float	z;

  x = pos->x;
  y = (pos->y * COS(angle)) - (pos->z * SIN(angle));
  z = (pos->y * SIN(angle)) + (pos->z * COS(angle));
  pos->x = x;
  pos->y = y;
  pos->z = z;
}

void	rotate_y(float angle, t_coord *pos)
{
  float	x;
  float	y;
  float	z;

  x = (pos->x * COS(angle)) + (pos->z * SIN(angle));
  y = pos->y;
  z = (pos->x * (- SIN(angle))) + (pos->z * COS(angle));
  pos->x = x;
  pos->y = y;
  pos->z = z;
}

void	rotate_z(float angle, t_coord *pos)
{
  float	x;
  float	y;
  float	z;

  x = (pos->x * COS(angle)) - (pos->y * SIN(angle));
  y = (pos->x * SIN(angle)) + (pos->y * COS(angle));
  z = pos->z;
  pos->x = x;
  pos->y = y;
  pos->z = z;
}
