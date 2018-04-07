/*
** EPITECH PROJECT, 2018
** error_gest.c
** File description:
** Arthur
*/

#include "define.h"
#include "lemin.h"

//check if the line is a valid information
int check_params(char **tab)
{
	if (!tab[0] || !tab[1] || !tab[2]) {
		my_print_err("ERROR : Bad folder\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

//check if there is one start and one end
int end_n_start(t_node *rooms)
{
	t_node	*tmp_node = rooms;
	int	start = 0;
	int	end = 0;
	t_room	*tmp_room = NULL;

	do {
		tmp_room = (t_room*)tmp_node->data;
		if (tmp_room->type == 1)
			++start;
		if (tmp_room->type == 2)
			++end;
		tmp_node = tmp_node->next;
	} while (tmp_node != rooms);
	if (start != 1 || end != 1) {
		my_print_err("ERROR : No start / end\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

static int check_all_names(char **names, int i)
{
	int	j = 0;

	while (names[j]) {
		if (j != i && my_strcmp(names[i], names[j]) == 0) {
			my_print_err("ERROR : 2 rooms with the same name\n");
			return (FAILURE);
		}
		++j;
	}
	return (SUCCESS);
}

int check_for_double_names(char **names)
{
	int	i = 0;

	while (names[i]) {
		if (check_all_names(names, i) == FAILURE)
			return (FAILURE);
		++i;
	}
	return (SUCCESS);
}
