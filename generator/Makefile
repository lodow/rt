## Makefile for Makefile in /home/robert_r//BSQ
## 
## Made by remi robert
## Login   <robert_r@epitech.net>
## 
## Started on  Fri Nov 30 10:59:19 2012 remi robert
## Last update Fri Jun  7 13:14:49 2013 remi robert
##

SRCPATH	=	src/

SRC	=	$(SRCPATH)main.c \
		$(SRCPATH)init_window.c \
		$(SRCPATH)gere_keyboard.c \
		$(SRCPATH)main_loop.c \
		$(SRCPATH)fct_exit.c \
		$(SRCPATH)my_pixel_put_to_image.c \
		$(SRCPATH)draw_ui.c \
		$(SRCPATH)gere_mouse.c \
		$(SRCPATH)add_object.c \
		$(SRCPATH)my_putstr.c \
		$(SRCPATH)gere_expose.c \
		$(SRCPATH)get_object.c \
		$(SRCPATH)get_texture.c \
		$(SRCPATH)texture.c \
		$(SRCPATH)return_char.c \
		$(SRCPATH)my_strlen.c \
		$(SRCPATH)draw_conf.c \
		$(SRCPATH)write_file.c \
		$(SRCPATH)get_name_file_object.c \
		$(SRCPATH)str_cmp.c \
		$(SRCPATH)detect_box.c \
		$(SRCPATH)my_getnbr.c \
		$(SRCPATH)strcpy.c \
		$(SRCPATH)validate_buffer.c \
		$(SRCPATH)free.c \
		$(SRCPATH)gere_cancel.c \
		$(SRCPATH)write_struct.c \
		$(SRCPATH)rempl_struct.c \
		$(SRCPATH)draw_form.c \
		$(SRCPATH)write_center.c \
		$(SRCPATH)actu_textbox.c \
		$(SRCPATH)validate_saisi.c \
		$(SRCPATH)get_new_type.c \
		$(SRCPATH)erease_textbox.c \

OBJ	=	$(SRC:.c=.o)

LIB	=	-L/usr/lib64 -lmlx_$$HOSTTYPE -L/usr/lib64/X11 -lXext -lX11

NAME	=	rtv1

CFLAGS	=	-g -Iinclude -Wall -Wextra

$(NAME):	$(OBJ)
		cc  -o $(NAME) $(OBJ) $(LIB) -lm

all:		$(NAME)

clean:
		rm -f *~
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
