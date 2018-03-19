/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** gen_graph
*/

#include "lemin.h"

static int find_nb_tunnels(int **tunnels)
{
	int	i = 0;

	while (tunnels[i])
		++i;
	return (i);
}

t_graph	*gen_graph(int **tunnels)
{
	t_graph	*graph = create_graph(find_nb_tunnels(tunnels));
	int	i = 0;

	while (tunnels[i]) {
		add_edge(graph, tunnels[i][0], tunnels[i][1]);
		++i;
	}
	return (graph);
}