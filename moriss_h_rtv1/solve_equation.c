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

int	equa_deg2(float a, float b, float c, float res[2])
{
  float	beta;

  beta = (b * b) - (4 * a * c);
  if (beta > 0.0001)
  {
    res[0] = (-b - sqrt(beta)) / (2 * a);
    res[1] = (-b + sqrt(beta)) / (2 * a);
    return (2);
  }
  else if (ABS(beta) < 0.0001)
  {
    res[0] = (-b) / (2 * a);
    return (1);
  }
  else
    return (0);
}
