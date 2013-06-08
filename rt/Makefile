##
## Makefile for copylib in /home/sinet_l//jour58
##
## Made by luc sinet
## Login   <sinet_l@epitech.net>
##
## Started on  Mon Oct 22 10:27:19 2012 luc sinet
## Last update Sun Jun  9 01:51:24 2013 Hugues
##

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

SRC = $(wildcard ${SRCDIR}*.c)

OBJ = $(patsubst ${SRCDIR}%.c,${OBJDIR}%.o,$(SRC))

dummy:=	$(shell test -d $(OBJDIR) || mkdir -p $(OBJDIR))
dummy:= $(shell test -d $(INCDIR) || mkdir -p $(INCDIR))
dummy:= $(shell test -d $(SRCDIR) || mkdir -p $(SRCDIR))

$(OBJDIR)%.o:	%.c
		@echo "\033[33mCompiling $*\033[00m"
		@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):	$(OBJ)
		@echo "\033[34mLinking $@ !\033[00m"
		@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

all:	$(NAME)

clean:
	@echo "\033[35mRemoving object !\033[00m"
	@$(RM) $(OBJ)

fclean:	clean
	@echo "\033[36mRemoving ${NAME} !\033[00m"
	@$(RM) $(NAME)

re:	fclean all

help:
	@echo "\033[37mTarget available: all, install, clean, fclean\033[00m"

.PHONY:	all clean fclean re help
