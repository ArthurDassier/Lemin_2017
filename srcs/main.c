/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function
*/

#include <stdio.h>
#include "lemin.h"
#include "define.h"

int main(int ac, char **av)
{
	//t_graph	*graph = create_graph(5);

	(void)ac;
	(void)av;
	t_infos	*infos = malloc(sizeof(t_infos));
	infos->tunnels = malloc(sizeof(t_tunnels));
	if (recup_anthill(infos, 4) == FAILURE)
		return (FAILURE);
	printf("%d\n", infos->rooms[0]->type);
	printf("%d\n", infos->rooms[1]->type);
	printf("%d\n", infos->rooms[2]->type);
	printf("%d\n", infos->rooms[3]->type);
	/*add_edge(graph, 0, 1);
	add_edge(graph, 0, 4);
	add_edge(graph, 1, 2);
	add_edge(graph, 1, 3);
	add_edge(graph, 1, 4);
	add_edge(graph, 2, 3);
	add_edge(graph, 3, 4);
	print_graph(graph);*/
//	t_graph	*graph = gen_graph(tunnels);
	(void)ac;
	(void)av;
//	print_graph(graph);
	return (0);
}
