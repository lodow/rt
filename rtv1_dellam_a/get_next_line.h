/*
** get_next_line.h for get_next_line in /home/dellam_a//Projet/Programmation Elementaire/Get Next Line
**
** Made by adrien dellamaggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Mon Nov 19 13:15:48 2012 adrien dellamaggiora
** Last update Fri Feb  8 16:10:17 2013 Adrien dellamaggiora
*/

#ifndef GET_NEXT_LINE_H__
#define GET_NEXT_LINE_H__

#include <stdlib.h>
#include <unistd.h>

#define READ 4096

char    *get_next_line(const int fd);

#endif
