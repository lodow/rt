##
## Makefile for RT_V1 in /home/dellam_a/Projet/Igraph/RT_V1
##
## Made by Adrien dellamaggiora
## Login   <dellam_a@epitech.net>
##
## Started on  Mon Feb  4 16:17:09 2013 Adrien dellamaggiora
## Last update Fri Mar 15 18:56:25 2013 Adrien
##

SRC=	main.c \
	image.c \
	get_next_line.c \
	calcscene.c \
	parseur.c \
	eq_droit.c \
	form.c \
	checkform.c \
	strfunc.c \
	matrice.c \
	light.c \
	shadow.c \
	normal.c \
	parseobj.c \
	getlight.c \
	my_get_nbr.c \
	parse.c \
	exotique.c

OBJ=	$(SRC:.c=.o)

CFLAGS=	-g -Wall -Wextra

NAME=	rtv1

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) -I. -L/usr/lib -lmlx_$(HOSTTYPE) -L/usr/lib/X11 -lXext -lX11 -lm

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean	all
