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
	t_graph	*graph = create_graph(5);

	(void)ac;
	(void)av;
	t_infos	*infos = malloc(sizeof(t_infos));
	infos->tunnels = malloc(sizeof(t_tunnels));
	if (recup_anthill(infos, 4) == FAILURE)
		return (FAILURE);
	print_graph(graph);
	return (0);
}
