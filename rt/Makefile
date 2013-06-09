##
## Makefile for copylib in /home/sinet_l//jour58
##
## Made by luc sinet
## Login   <sinet_l@epitech.net>
##
## Started on  Mon Oct 22 10:27:19 2012 luc sinet
## Last update Sun Jun  9 02:11:08 2013 Hugues
##

SRC = 	ambient_light.c \
	antialiasing.c \
	bmp_loader.c \
	bmp_output.c \
	bump_mapping.c \
	calc_inter.c \
	change_color.c \
	checkerboard.c \
	check_passages.c \
	copy.c \
	detect_edge.c \
	detect_shadows.c \
	error.c \
	exotique.c \
	filter.c \
	init_shadows.c \
	init_texture_surface.c \
	inter.c \
	interpolation.c \
	light.c \
	light_calcul.c \
	limit.c \
	limit_depth.c \
	limited_plan.c \
	limit_sides.c \
	main.c \
	math_coef.c \
	math_coor.c \
	math_vec.c \
	mem.c \
	modif_cam.c \
	move_cam.c \
	normals.c \
	normals_exotique.c \
	other_filter.c \
	other_perlin_effect.c \
	pars_convert_model_tri.c \
	pars_error.c \
	pars_fill_cam.c \
	pars_fill_elem.c \
	pars_fill_light.c \
	pars_fill_model.c \
	pars_fill_obj_color.c \
	pars_fill_opt.c \
	pars_fill_texture.c \
	pars_get_carac.c \
	pars_get_config_file.c \
	pars_get_limit.c \
	pars_get_next_line.c \
	pars_get_obj_model.c \
	pars_get_obj_model_indice_exp.c \
	pars_get_pert.c \
	pars_init.c \
	pars_init_cam.c \
	pars_init_elem.c \
	pars_init_elem_indice.c \
	pars_init_opt.c \
	pars_init_pars.c \
	pars_init_triangle_size.c \
	pars_light_carac.c \
	pars_my_atof.c \
	pars_my_getnbr_base.c \
	pars_nb.c \
	pars_pars.c \
	pars_pars_color.c \
	pars_pars_contrast.c \
	pars_pars_disformations.c \
	pars_parse_argv.c \
	pars_pars_indice.c \
	pars_pars_opt.c \
	pars_pars_other_indice.c \
	pars_pars_perlin.c \
	pars_pars_seed.c \
	pars_pars_size.c \
	pars_str.c \
	pars_strfunc.c \
	perlin.c \
	perlin_effect.c \
	perlin_permutation.c \
	pp_image.c \
	reflection.c \
	refraction.c \
	reset_calc.c \
	shadows.c \
	shadows_supersampling.c \
	shadows_transparency.c \
	solve_cubic.c \
	solve_quadratic.c \
	solve_quartic.c \
	solve_second.c \
	supersampling.c \
	tangle.c \
	texture.c \
	tga_output.c \
	tore.c \
	transform_vec.c \
	transparency.c \
	utils_color.c

CC = gcc

RM = rm -f

NAME = rt

OBJDIR = obj/
SRCDIR = src/
INCDIR = inc/

CFLAGS	+= -O3 -march=native
CFLAGS	+= --fast-math -ffast-math
CFLAGS	+= -Wall -Wextra
CFLAGS	+= -I${INCDIR}

LDFLAGS += -L/usr/lib64 -lmlx_x86_64-linux -L/usr/lib64/X11 -lXext -lX11 -lm

VPATH = ${SRCDIR}

OBJ = $(patsubst %.c,${OBJDIR}%.o,$(SRC))

dummy:=	$(shell test -d $(OBJDIR) || mkdir -p $(OBJDIR))
dummy:= $(shell test -d $(INCDIR) || mkdir -p $(INCDIR))
dummy:= $(shell test -d $(SRCDIR) || mkdir -p $(SRCDIR))

%.depends:	%.c
		$(CC) -M $(CFLAGS) $< > $@

$(OBJDIR)%.o:	%.c
		@echo -e "\033[33mCompiling $*\033[00m"
		@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):	$(OBJ)
		@echo -e "\033[34mLinking $@ !\033[00m"
		@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

all:	$(NAME)

clean:
	@echo -e "\033[35mRemoving object !\033[00m"
	@$(RM) $(OBJ)

fclean:	clean
	@echo -e "\033[36mRemoving ${NAME} !\033[00m"
	@$(RM) $(NAME)

re:	fclean all

help:
	@echo -e "\033[37mTarget available: all, ${NAME}, clean, fclean\033[00m"

.PHONY:	all clean fclean re help
