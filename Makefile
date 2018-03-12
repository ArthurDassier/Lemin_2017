##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## A Makefile for projetcs
##

CC	=	gcc -g3

RM	=	rm -rf

CFLAGS	+=	-Wall -Wextra

CPPFLAGS	+=	-I./include

NAME	=	lem_in

SRCS	=	srcs/main.c

OBJS	=	$(SRCS:.c=.o)

LDFLAGS =		-L./lib -lmy

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./lib/my
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)
	make -C ./lib/my clean

fclean: clean
	$(RM) $(NAME)
	$(RM) lib/libmy.a
	make -C ./lib/my fclean


re: fclean all

.PHONY: all clean fclean re
