##
## Makefile for copylib in /home/sinet_l//jour11
## 
## Made by luc sinet
## Login   <sinet_l@epitech.net>
## 
## Started on  Mon Oct 22 10:27:19 2012 luc sinet
## Last update Mon May  6 10:38:19 2013 Adrien
##

SRCS	= main.c \
	  parseur/pars.c \
	  parseur/get_config_file.c \
	  parseur/fill_obj_color.c \
	  parseur/fill_elem.c \
	  parseur/fill_light.c \
	  parseur/fill_cam.c \
	  parseur/fill_opt.c \
	  parseur/init.c \
	  parseur/init_elem.c \
	  parseur/init_cam.c \
	  parseur/get_carac.c \
	  parseur/get_pert.c \
	  parseur/get_limit.c \
	  parseur/get_next_line.c \
	  parseur/my_getnbr_base.c \
	  parseur/error.c \
	  parseur/strfunc.c \
	  parseur/str.c \
	  parseur/nb.c \
	  parseur/my_atof.c \
	  parseur/light_carac.c \
	  parseur/obj_carac.c \
	  calc_inter.c \
	  pp_image.c \
	  inter.c \
	  move_cam.c \
	  light.c \
	  change_color.c \
	  math_coor.c \
	  math_vec.c \
	  normals.c \
	  modif_cam.c \
	  refraction.c \
	  reflection.c \
	  transparency.c \
	  antialiasing.c \
	  ambient_light.c \
	  shadows.c \
	  detect_edge.c \
	  detect_shadows.c \
	  solve_second.c \
	  limit.c \
	  limit_sides.c \
	  limit_depth.c \
	  supersampling.c \
	  solve_third.c \
	  inter_third.c \
	  limited_plan.c \
	  exotique.c

OBJS	= $(SRCS:.c=.o)

OPT     = -L/usr/lib64 -lmlx_x86_64-linux -L/usr/lib64/X11 -lXext -lX11 -lm

CC	= gcc -g -Wall -Wextra

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
