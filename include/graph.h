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
typedef struct	adj_node_s
{
	int	dest;
	struct	adj_node_s *next;
}		adj_node_t;

// A structure to represent an adjacency list
typedef struct	adj_list_s
{
	adj_node_t	*head;
}		adj_list_t;

// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be vertices (number of vertices in graph)
typedef struct	graph_s
{
	int		vertices;
	adj_list_t	*array;
}		graph_t;

void add_edge(graph_t *graph, int src, int dest);
void print_graph(graph_t *graph);
void print_graph(graph_t *graph);
graph_t	*create_graph(int vertices);
struct adj_node_t*	add_node_list(int dest);

#endif /* !GRAPH_H_ */