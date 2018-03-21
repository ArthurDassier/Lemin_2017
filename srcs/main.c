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
<<<<<<< HEAD
	add_edge(graph, 0, 1);
	add_edge(graph, 1, 3);
	add_edge(graph, 1, 4);
	add_edge(graph, 4, 3);
	add_edge(graph, 2, 1);
=======
	if (recup_anthill(infos, 4) == 84)
		return (84);
	graph = gen_graph(infos);
>>>>>>> f95c1e8201b2e19a46588525d2dcb9415ba1a397
	print_graph(graph);
	return (0);
}
