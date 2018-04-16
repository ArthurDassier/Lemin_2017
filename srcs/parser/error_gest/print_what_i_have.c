/*
** EPITECH PROJECT, 2018
** print.c
** File description:
** Arthur
*/

#include "lemin.h"

void test_first(void)
{
	static int	first = 0;

	if (first == 0) {
		my_putstr("#rooms\n");
		first = 1;
	}
}

int print_err_rooms(int nb_ants)
{
	if (nb_ants <= 0)
		return (FAILURE);
}
