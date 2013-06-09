##
## Makefile for makefile in /home/izissise/work/tek1/epistuff/igraph/rt
## 
## Made by Hugues
## Login   <izissise@epitech.net>
## 
## Started on  Sun Jun  9 13:07:58 2013 Hugues
## Last update Sun Jun  9 13:39:43 2013 Hugues
##

NAME= rt/generator

PATHRT= rt
PATHGEN= generator

all:	$(NAME)

$(NAME):
	@make --no-print-directory -C $(PATHRT)
	@make --no-print-directory -C $(PATHGEN)

clean:
	@make --no-print-directory clean -C $(PATHRT)
	@make --no-print-directory clean -C $(PATHGEN)

fclean:
	@make --no-print-directory fclean -C $(PATHRT)
	@make --no-print-directory fclean -C $(PATHGEN)

re:	fclean all

.PHONY:	all clean fclean re
