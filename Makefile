##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## A Makefile for projetcs
##

CC	=	gcc -g3

RM	=	rm -rf

TEST_CC	=	gcc -Wall -Wextra -I./include -I./lib/my/include --coverage

CFLAGS	+=	-Wall -Wextra

CPPFLAGS	+=	-I./include -I./lib/my/include

NAME	=	lem_in

SRCS	=	srcs/main.c					\
		srcs/graph/add_edge.c				\
		srcs/graph/print_graph.c			\
		srcs/graph/create_graph.c			\
		srcs/gen_graph/gen_graph.c			\
		srcs/lemin/algo.c				\
		srcs/lemin/get_total.c				\
		srcs/lemin/ant.c				\
		srcs/lemin/lem_in.c				\
		srcs/lemin/display.c				\
		srcs/lemin/delete_node.c			\
		srcs/parser/recup_anthill.c			\
		srcs/parser/fuel_tunnel.c			\
		srcs/parser/analyse_commands.c			\
		srcs/parser/error_gest/error_gest.c		\
		srcs/parser/init_infos.c			\
		srcs/parser/error_gest/error_coordinates.c	\
		srcs/parser/error_gest/end_to_start.c		\
		srcs/display/display.c

SRCS_UT	=	srcs/graph/add_edge.c				\
		srcs/graph/create_graph.c			\
		srcs/graph/print_graph.c			\
		srcs/parser/recup_anthill.c			\
		srcs/display/display.c				\
		srcs/parser/fuel_tunnel.c			\
		srcs/parser/analyse_commands.c			\
		srcs/parser/error_gest/error_gest.c		\
		srcs/gen_graph/gen_graph.c			\
		srcs/parser/error_gest/error_coordinates.c	\
		srcs/parser/init_infos.c			\

SRCS_TESTS=	tests/test_my_printf.c			\
		tests/lib/test_my_strcat.c		\
		tests/lib/test_my_fact_it.c		\
		tests/lib/test_my_fact_rec.c		\
		tests/lib/test_my_find_prime_sup.c	\
		tests/lib/test_my_is_prime.c		\
		tests/lib/test_my_power_it.c		\
		tests/lib/test_my_power_rec.c		\
		tests/lib/test_my_putnbr_base.c		\
		tests/lib/test_my_revstr.c		\
		tests/lib/test_my_getnbr.c		\
		tests/lib/test_my_str_isalpha.c		\
		tests/lib/test_my_str_islower.c		\
		tests/lib/test_my_str_isnum.c		\
		tests/lib/test_my_str_isupper.c		\
		tests/lib/test_my_strcpy.c		\
		tests/lib/test_my_strlowcase.c		\
		tests/lib/test_my_strncpy.c		\
		tests/lib/test_my_strstr.c		\
		tests/lib/test_my_strupcase.c		\
		tests/lib/test_my_char_is_alpha.c	\
		tests/lib/test_my_char_is_alphanum.c	\
		tests/lib/test_my_char_is_num.c		\
		tests/lib/test_my_putstr.c		\
		tests/lib/test_my_strdup.c		\
		tests/lib/test_my_strlen.c		\
		tests/lib/test_my_strncat.c		\
		tests/lib/test_my_strncmp.c		\
		tests/lib/test_my_swap.c		\
		tests/tests_parser/test_tunnels.c	\
		tests/tests_parser/test_comment.c

LDFLAGS=	-lcriterion --coverage -lncurses -L./lib -lmy

TEST_NAME=	units

OBJS	=	$(SRCS:.c=.o)

LIB = libmy.a


all: $(LIB) $(NAME)


tests_run:	EXEC
		./$(TEST_NAME)

./lib/my/libmy.a:
	make -C ./lib/my

EXEC:		./lib/my/libmy.a
		$(TEST_CC) -o $(TEST_NAME) $(SRCS_UT) $(SRCS_TESTS) $(LDFLAGS)


$(LIB):
	make -C ./lib/my

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
	make -C ./lib/my

clean:
	$(RM) $(OBJS)
	find . -type f -name '*.gc*' -delete
	make -C ./lib/my clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(TEST_NAME)
	$(RM) lib/libmy.a
	make -C ./lib/my fclean


re: fclean all

.PHONY:		all exec tests_run clean fclean re
