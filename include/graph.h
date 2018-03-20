/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** graph
*/
#ifndef GRAPH_H_
#define GRAPH_H_

#include "my.h"

// A structure to represent an adjacency list node
typedef struct	s_adj_node
{
	int			dest;
	void			*data;
	struct	s_adj_node	*next;
	struct	s_adj_node	*head;
	struct	s_adj_node	*prev;
}		t_adj_node;

// A structure to represent an adjacency list
typedef struct	s_adj_list
{
	t_adj_node	*head;
}		t_adj_list;

// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be vertices (number of vertices in graph)
typedef struct	s_graph
{
	int		vertices;
	t_adj_node	*array;
}		t_graph;

void			add_edge(t_graph *graph, int, int);
void			print_graph(t_graph *);
t_graph			*create_graph(int);
t_adj_node*	add_node_list(int);

#endif /* !GRAPH_H_ */