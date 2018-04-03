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

	create_graph(&node, 4);
	(void)ac;
	(void)av;
	add_edge(node, 1, 2);
	add_edge(node, 2, 3);
	add_edge(node, 1, 3);
	add_edge(node, 2, 1);
	add_edge(node, 3, 2);
	print_graph(node);
	//display_list(node, &print_list);
	return (0);
}