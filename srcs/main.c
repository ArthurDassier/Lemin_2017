/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function
*/
#include "lemin.h"

int main(int ac, char **av)
{
	t_node *node = NULL;

	create_graph(&node, 7);
	(void)ac;
	(void)av;
	add_edge(node, 1, 2);
	add_edge(node, 1, 6);
	add_edge(node, 2, 1);
	add_edge(node, 2, 3);
	add_edge(node, 3, 2);
	add_edge(node, 3, 4);
	add_edge(node, 4, 3);
	add_edge(node, 4, 5);
	add_edge(node, 5, 4);
	add_edge(node, 5, 7);
	add_edge(node, 7, 5);
	add_edge(node, 7, 6);
	add_edge(node, 6, 1);
	add_edge(node, 6, 7);
	//pathfinding(node);
	repeat(node);
	//print_graph(node);
//	display_list(node, &print_list);
	return (0);
}