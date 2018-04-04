/*
** EPITECH PROJECT, 2018
** error_gest.c
** File description:
** Arthur
*/

#include "define.h"
#include "lemin.h"

int check_params(char **tab)
{
	if (!tab[0] || !tab[1] || !tab[2]) {
		my_print_err("ERROR : Bad folder\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

int end_n_start(t_node *rooms)
{
	t_node	*tmp = rooms->next;
	int	start = 0;
	int	end = 0;
	t_room	*tmp2 = NULL;

	while (tmp != rooms) {
		tmp2 = (t_room*)tmp->data;
		if (tmp2->type == 1)
			++start;
		if (tmp2->type == 2)
			++end;
		tmp = tmp->next;
	}
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
