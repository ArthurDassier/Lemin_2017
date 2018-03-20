/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function
*/
#include "lemin.h"

int main(int ac, char **av)
{
	//t_graph	*graph = create_graph(5);

	(void)ac;
	(void)av;
	t_tunnels *tun = malloc(sizeof(t_tunnels));
	t_room **room = recup_anthill(tun, 4);

	printf("%d\n", room[0]->type);
	printf("%d\n", room[1]->type);
	printf("%d\n", room[2]->type);
	printf("%d\n", room[3]->type);
	/*add_edge(graph, 0, 1);
	add_edge(graph, 0, 4);
	add_edge(graph, 1, 2);
	add_edge(graph, 1, 3);
	add_edge(graph, 1, 4);
	add_edge(graph, 2, 3);
	add_edge(graph, 3, 4);
	print_graph(graph);*/
	return (0);
}
