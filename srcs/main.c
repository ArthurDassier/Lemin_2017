/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function
*/
#include "lemin.h"

int main(int ac, char **av)
{
	t_graph	*graph = create_graph(5);

	(void)ac;
	(void)av;
	t_infos	*infos = malloc(sizeof(t_infos));
	infos->tunnels = malloc(sizeof(t_tunnels));
	if (recup_anthill(infos, 4) == 84)
		return (84);
	printf("%d\n", infos->rooms[0]->ant);
	/*add_edge(graph, 0, 1);
	add_edge(graph, 0, 4);
	add_edge(graph, 1, 2);
	add_edge(graph, 1, 3);
	add_edge(graph, 1, 4);
	add_edge(graph, 2, 3);
	add_edge(graph, 3, 4);
	add_edge(graph, 4, 3);
	add_edge(graph, 2, 1);
	print_graph(graph);
	return (0);*/
}
