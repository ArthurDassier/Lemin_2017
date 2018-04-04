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

	create_graph(&node, 6);
	(void)ac;
	(void)av;
	add_edge(node, 1, 5);
	add_edge(node, 6, 4);
	add_edge(node, 4, 6);
	print_graph(node);
	//display_list(node, &print_list);
	return (0);
}