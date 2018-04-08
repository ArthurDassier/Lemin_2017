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

	tab = recup_anthill(&infos, tab);
	if (tab == NULL)
		return (FAILURE);
	if (end_to_start(infos, tab) == FAILURE)
		return (FAILURE);
	init_graph(&node, infos, tab);
	display_infos(infos);
	send_ants(&node);
	return (SUCCESS);
}
