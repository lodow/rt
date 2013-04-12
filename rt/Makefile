##
## Makefile for copylib in /home/sinet_l//jour11
## 
## Made by luc sinet
## Login   <sinet_l@epitech.net>
## 
## Started on  Mon Oct 22 10:27:19 2012 luc sinet
## Last update Fri Apr 12 14:54:09 2013 Adrien Della Maggiora
##

SRCS	= main.c \
	  parseur/pars.c \
	  parseur/fill_obj_color.c \
	  parseur/fill_elem.c \
	  parseur/fill_light.c \
	  parseur/fill_cam.c \
	  parseur/init.c \
	  parseur/init_elem.c \
	  parseur/init_cam.c \
	  parseur/get_carac.c \
	  parseur/get_next_line.c \
	  parseur/my_getnbr_base.c \
	  parseur/error.c \
	  parseur/strfunc.c \
	  parseur/str.c \
	  parseur/nb.c \
	  parseur/my_atof.c \
	  light_carac.c \
	  calc_inter.c \
	  pp_image.c \
	  inter.c \
	  move_cam.c \
	  light.c \
	  change_color.c \
	  deref.c \
	  math_coor.c \
	  normals.c \
	  modif_cam.c \
	  refraction.c \
	  reflection.c \
	  antialiasing.c \
	  ambient_light.c \
	  shadows.c \
	  detect_edge.c \
	  detect_shadows.c \
	  solve_second.c \
	  limit.c \
	  limit_sides.c \
	  limit_depth.c \
	  supersampling.c

OBJS	= $(SRCS:.c=.o)

OPT     = -L/usr/lib64 -lmlx_x86_64-linux -L/usr/lib64/X11 -lXext -lX11 -lm

CC	= gcc -Wall -Wextra

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
