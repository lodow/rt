##
## Makefile for copylib in /home/sinet_l//jour11
## 
## Made by luc sinet
## Login   <sinet_l@epitech.net>
## 
## Started on  Mon Oct 22 10:27:19 2012 luc sinet
## Last update Wed Mar 27 18:02:08 2013 luc sinet
##

SRCS	= main.c \
	  pars.c \
	  fill_obj_color.c \
	  fill_elem.c \
	  fill_light.c \
	  get_carac.c \
	  get_next_line.c \
	  my_getnbr_base.c \
	  calc_inter.c \
	  pp_image.c \
	  strfunc.c \
	  str.c \
	  nb.c \
	  inter.c \
	  move_cam.c \
	  error.c \
	  light.c \
	  change_color.c \
	  init.c \
	  deref.c \
	  modif_cam.c

OBJS	= $(SRCS:.c=.o)

OPT     = -L/usr/lib64 -lmlx_x86_64-linux -L/usr/lib64/X11 -lXext -lX11 -lm

CC	= gcc -g -Wall -Wmissing-include-dirs -pg

RM	= rm -f

NAME	= rt

$(NAME): 	$(OBJS)
	$(CC) $(SRCS) -o $(NAME) $(OPT)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all clean
