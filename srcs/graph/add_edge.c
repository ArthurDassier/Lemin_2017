/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** add_edge
*/
#include "lemin.h"

// Returns the node of a given index
t_node	*get_graph_index(t_node *node, int index)
{
	t_node	*tmp = node;
	t_lemin	*lemin;

	do {
		lemin = (t_lemin *)tmp->data;
		if (lemin->nb_room == index)
			return (tmp);
		tmp = tmp->next;
	} while (tmp != node);
	return (NULL);
}

static int	get_graph_len(t_node **node)
{
	int	i;

	if (node == NULL)
		return (0);
	for (i = 0; node[i] != NULL; ++i);
	return (i);
}

//Adds an edge to an undirected graph
int add_edge(t_node *node, int src, int dest)
{
	t_node *tmp = get_graph_index(node, src);
	int	len = get_graph_len(tmp->graph);
	t_node	*tmp_dest = get_graph_index(node, dest);

	if (tmp == NULL || tmp_dest == NULL) {
		my_print_err("Index not found\n");
		return (FAILURE);
	}
	if (len == 0) {
		tmp->graph = malloc(sizeof(t_node *) * 2);
		if (tmp->graph == NULL)
			return (FAILURE);
		tmp->graph[1] = NULL;
		tmp->graph[0] = tmp_dest;
	} else {
		my_realloc(tmp->graph, sizeof(t_node *) * (len + 2));
		if (tmp->graph == NULL)
			return (FAILURE);
		tmp->graph[len + 1] = NULL;
		tmp->graph[len] = tmp_dest;
	}
	return (SUCCESS);
}