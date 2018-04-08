/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function
*/
#include "lemin.h"

int main(void)
{
	char	**tab = NULL;
	t_infos	*infos = NULL;
	t_node	*node = NULL;

	tab = recup_anthill(&infos, tab);
	if (tab == NULL) {
		if (print_err_rooms(infos->err_ant, infos->rooms,
			infos->tunnels) == FAILURE)
			return (FAILURE);
		return (0);
	}
	if (end_to_start(infos, tab) == FAILURE)
		return (FAILURE);
	init_graph(&node, infos, tab);
	display_infos(infos);
	send_ants(&node);
	return (0);
}
