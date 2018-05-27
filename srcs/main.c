/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function
*/
#include "lemin.h"

int main(int ac, char **av)
{
	char	**tab = NULL;
	t_infos	*infos = NULL;
	t_node	*node = NULL;

	(void) av;
	if (ac > 1)
		return (FAILURE);
	tab = recup_anthill(&infos, tab);
	if (tab == NULL) {
		if (infos == NULL)
			return (FAILURE);
		if (print_err_rooms(infos->err_ant) == FAILURE)
			return (FAILURE);
		return (SUCCESS);
	}
	my_putstr("#moves\n");
	init_graph(&node, infos, tab);
	send_ants(&node);
	return (SUCCESS);
}
