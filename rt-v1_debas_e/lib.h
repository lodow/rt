/*
** lib.h for lib in /home/debas_e//minishell1-2017-debas_e/lib
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Thu Mar  7 14:24:11 2013 etienne debas
** Last update Sun Mar 17 03:45:13 2013 etienne debas
*/

#ifndef LIB_H_
# define LIB_H_

# define PBALLOC "Allcotion failed\n"
# include <stdlib.h>

char		**my_str_to_word_tab(char *, char);
int		count_word(char *, char);
char		*get_word(int, int, char *);
void		supress_space(char *, char **, char);
int		epur_and_check(char *);
void		epur_tab(char **);
int		my_strncmp(char *, char *, int);
void		my_putchar(char);
int		my_putnbr(int);
int		my_putstr(char *, int);
int		my_putstr2(char *, char *, int);
int		my_putstr3(char *, char *, char *, int);
char		*my_strcat(char *, char *);
int		my_strcmp(char *, char *);
char		*my_strdup(char *);
int		my_strlen(char *);
char		*get_next_line(int);
int		my_getnbr_base(char *, char *);
float		my_getnbr_float(char *);
int		my_pow(int, int);
#endif
