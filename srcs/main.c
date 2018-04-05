/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function
*/
#include "lemin.h"

int main()
{
	char	**tab = NULL;
	t_infos	*infos = NULL;
	t_node	*graph = malloc(sizeof(t_node));

	tab = recup_anthill(&infos, tab);
	gen_graph(graph, infos, tab);
//	print_graph(graph);
}