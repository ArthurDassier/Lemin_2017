/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** test_comment
*/
#include <criterion/criterion.h>
#include "lemin.h"

int analyse_command(char *line, int *type_next_room);

Test(analyse_command, return_value_is_good)
{
	cr_assert_eq(analyse_command("##start\n", 0), 1);
	cr_assert_eq(analyse_command("##end\n", 0), 1);
	cr_assert_eq(analyse_command("#kitchen\n", 0), 1);
	cr_assert_eq(analyse_command("2 3 5\n", 0), 0);
	cr_assert_eq(analyse_command("bonjour\n", 0), 0);
}