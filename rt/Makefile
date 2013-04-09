##
## Makefile for copylib in /home/sinet_l//jour11
## 
## Made by luc sinet
## Login   <sinet_l@epitech.net>
## 
## Started on  Mon Oct 22 10:27:19 2012 luc sinet
## Last update Tue Apr  9 18:57:33 2013 luc sinet
##

SRCS	= main.c \
	  pars.c \
	  fill_obj_color.c \
	  fill_elem.c \
	  fill_light.c \
	  fill_cam.c \
	  light_carac.c \
	  get_carac.c \
	  get_next_line.c \
	  my_getnbr_base.c \
	  calc_inter.c \
	  pp_image.c \
	  strfunc.c \
	  str.c \
	  nb.c \
	  my_atof.c \
	  inter.c \
	  move_cam.c \
	  error.c \
	  light.c \
	  change_color.c \
	  init.c \
	  init_cam.c \
	  deref.c \
	  math_coor.c \
	  normals.c \
	  modif_cam.c \
	  refraction.c \
	  reflection.c \
	  antialiasing.c \
	  ambient_light.c \
	  detect_edge.c \
	  solve_second.c \
	  limit.c \
	  supersampling.c

OBJS	= $(SRCS:.c=.o)

OPT     = -L/usr/lib64 -lmlx_x86_64-linux -L/usr/lib64/X11 -lXext -lX11 -lm

CC	= gcc -O2 -march=native -g -Wall -Wmissing-include-dirs

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
