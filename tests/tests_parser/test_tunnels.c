/*
** EPITECH PROJECT, 2018
** Lemin
** File description:
** Arthur
*/

#include <criterion/criterion.h>
#include "lemin.h"

int found_tunnels(char *line);

Test(found_tunnels, return_value_is_good)
{
	cr_assert_eq(found_tunnels("2-3\n"), 1);
	cr_assert_eq(found_tunnels("4-3\n"), 1);
	cr_assert_eq(found_tunnels("34 55 2\n"), 0);
	cr_assert_eq(found_tunnels("5-1\n"), 1);
	cr_assert_eq(found_tunnels("salut\n"), 0);
}