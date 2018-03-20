/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function
*/
#include "lemin.h"

int main(int ac, char **av)
{
	t_infos	*infos = malloc(sizeof(t_infos));
	infos->tunnels = malloc(sizeof(t_tunnels));
	t_graph	*graph = NULL;

	(void)ac;
	(void)av;
	if (recup_anthill(infos, 4) == 84)
		return (84);
	graph = gen_graph(infos);
	print_graph(graph);
	return (0);
}
