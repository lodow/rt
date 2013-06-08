/*
** function_c.h for functionc1 in /home/sinet_l//minishell
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Dec 13 13:54:48 2012 luc sinet
** Last update Sat Jun  8 17:52:42 2013 adrien dellamaggiora
*/

#ifndef FUNCTION1_H_
# define FUNCTION1_H_

char	*my_strcpy(char *dest, char *src);
void	my_putstr(char *s1, int fd);
void	my_putchar(char c, int fd);
char	*my_strdup(char *src);
int	my_strlen(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strcat(char *dest, char *src);
void	free_tab(char **tab);

#endif /* !FUNCTION1_H_ */
