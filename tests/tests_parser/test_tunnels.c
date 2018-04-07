/*
** EPITECH PROJECT, 2018
** Lemin
** File description:
** Arthur
*/

#include <criterion/criterion.h>
#include "lemin.h"

int found_tunnels(char *line);
int analyse_command(char *line, int *type_next_room);

Test(found_tunnels, return_value_is_good)
{
	cr_assert_eq(found_tunnels("2-3\n"), 1);
	cr_assert_eq(found_tunnels("4-3\n"), 1);
	cr_assert_eq(found_tunnels("34 55 2\n"), 0);
	cr_assert_eq(found_tunnels("5-1\n"), 1);
	cr_assert_eq(found_tunnels("salut\n"), 0);
}

Test(analyse_command, return_value_is_good)
{
	cr_assert_eq(analyse_command("##start\n", 0), 1);
	cr_assert_eq(analyse_command("##end\n", 0), 1);
	cr_assert_eq(analyse_command("#kitchen\n", 0), 1);
	cr_assert_eq(analyse_command("2 3 5\n", 0), 0);
	cr_assert_eq(analyse_command("bonjour\n", 0), 0);
}
