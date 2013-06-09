##
## Makefile for copylib in /home/sinet_l//jour58
##
## Made by luc sinet
## Login   <sinet_l@epitech.net>
##
## Started on  Mon Oct 22 10:27:19 2012 luc sinet
## Last update Sun Jun  9 03:54:59 2013 luc sinet
##

SRC =	actu_textbox.c \
	add_object.c \
	check_saisi.c \
	detect_box.c \
	draw_conf.c \
	draw_form.c \
	draw_ui.c \
	erease_textbox.c \
	fct_exit.c \
	free.c \
	gere_cancel.c \
	gere_delete.c \
	gere_expose.c \
	gere_keyboard.c \
	gere_mouse.c \
	get_name_file_object.c \
	get_new_type.c \
	get_object.c \
	get_texture.c \
	init_window.c \
	main.c \
	main_loop.c \
	my_getnbr.c \
	my_pixel_put_to_image.c \
	my_putstr.c \
	my_strlen.c \
	rempl_struct.c \
	return_char.c \
	str_cmp.c \
	strcpy.c \
	texture.c \
	validate_buffer.c \
	validate_saisi.c \
	write_center.c \
	write_file.c \
	write_light.c \
	write_struct.c

CC = gcc

RM = rm -f

NAME = generator

TARGET =

OBJDIR = obj/
SRCDIR = src/
INCDIR = inc/

ifeq ($(TARGET), debug)
CFLAGS	+= -ggdb3 -pg
endif
ifeq ($(TARGET), opti2)
CFLAGS	+= -O3 -march=native
endif
ifeq ($(TARGET), opti1)
CFLAGS	+= -ffast-math
endif
CFLAGS	+= -Wall -Wextra
CFLAGS	+= -I${INCDIR}

LDFLAGS += -L/usr/lib64 -lmlx_$$HOSTTYPE -L/usr/lib64/X11 -lXext -lX11 -lm

VPATH = ${SRCDIR}

OBJ = $(patsubst %.c,${OBJDIR}%.o,$(SRC))

dummy:=	$(shell test -d $(OBJDIR) || mkdir -p $(OBJDIR))
dummy:= $(shell test -d $(INCDIR) || mkdir -p $(INCDIR))
dummy:= $(shell test -d $(SRCDIR) || mkdir -p $(SRCDIR))

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
