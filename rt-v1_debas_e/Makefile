##
## Makefile for wolf3d in /home/debas_e//projet/wolf3d
## 
## Made by etienne debas
## Login   <debas_e@epitech.net>
## 
## Started on  Sun Jan 13 02:42:26 2013 etienne debas
## Last update Sun Mar 17 22:50:31 2013 etienne debas
##

CC	= cc

NAME	= rtv1

RM	= rm -f

SRCS	= ./lib/my_putstr.c \
	  ./lib/my_putchar.c \
	  ./lib/my_getnbr_base.c \
	  ./lib/my_get_nbr_float.c \
	  ./lib/my_getnbr.c \
	  ./lib/my_pow.c \
	  ./lib/my_strlen.c \
	  ./lib/my_strcmp.c \
	  ./lib/my_strncmp.c \
	  ./lib/get_next_line.c \
	  ./lib/my_str_to_wordtab.c \
	  ./lib/my_str_to_wordtab2.c \
	  ./parse/fill.c \
	  ./parse/get_obj.c \
	  ./src/main.c \
	  ./src/my_pixel_put_to_img.c \
	  ./src/error.c \
	  ./src/object.c \
	  ./src/rotate.c \
	  ./src/init.c \
	  ./src/draw.c \
	  ./src/get_normal.c \
	  ./src/calc.c \
	  ./src/make_k.c \
	  ./src/event.c \

OBJS	= $(SRCS:.c=.o)

all: 	 $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -L/usr/lib64 -lmlx_$$HOSTTYPE -L/usr/lib64/X11 -lXext -lX11 -lm -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:
	 $(RM) $(OBJS)
	 $(RM) $(NAME)

re: fclean all