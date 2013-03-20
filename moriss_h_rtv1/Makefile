##
## Makefile for Make in /home/moriss_h//afs/rendu/lib/my
##
## Made by hugues morisset
## Login   <moriss_h@epitech.net>
##
## Started on  Mon Oct 22 09:20:28 2012 hugues morisset
## Last update Mon Oct 22 10:39:42 2012 hugues morisset
##

SRC= 	main.c \
	get_next_line.c \
	mlx_key_hook.c \
	get_file.c \
	form.c \
	draw_line.c \
	free.c \
	vector.c \
	obj.c \
	stc.c \
	vector_bis.c \
	solve_equation.c \
	trace.c \
	handle_mlx.c \
	my_memset.c \
	my_str_to_wordtab.c \
	put_pixel.c

OBJ= $(SRC:.c=.o)

NAME= rtv1

CFLAGS= -g -pg -Wall -Wfloat-equal \
	-Wclobbered -Wempty-body -Wignored-qualifiers \
	-Wmissing-field-initializers -Wmissing-parameter-type \
	-Wold-style-declaration -Woverride-init -Wsign-compare \
	-Wtype-limits -Wuninitialized

	# -ffast-math -O2 -march=native

INVOCATION= cc

OBJ= $(SRC:.c=.o)

LIBS= -L/usr/lib64 -lmlx_${HOSTTYPE} -L/usr/lib64/X11 -lXext -lX11 -lm

ubuntu:
	cc $(CFLAGS) -c $(SRC) -I/usr/X11/include/
	$(INVOCATION) $(CFLAGS) $(OBJ) ${LIBSUB} -o $(NAME)

$(NAME):	$(OBJ)
		$(INVOCATION) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
