/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** algo
*/
#include "lemin.h"

// Returns the node of the end
t_node	*get_room(t_node *node, int type)
{
	t_node	*tmp = node;
	t_room	*room;

	do {
		room = (t_room *)tmp->data;
		if (room->type == type)
			return (tmp);
		tmp = tmp->next;
	} while (tmp != node);
	return (NULL);
}

// Returns true if there are no univisted nodes
static bool	check_visited_nodes(t_node *node)
{
	t_node	*tmp = node;

	do {
		if (tmp->visited == false)
			return (false);
		tmp = tmp->next;
	} while (tmp != node);
	return (true);
}

// Returns the smallest distance
static t_node	*get_smallest_distance(t_node *node)
{
	t_node *tmp = node;
	t_node *save = NULL;

	do {
		if ((save == NULL || (tmp->path < save->path && save))
		&& !tmp->visited && tmp->path != -1)
			save = tmp;
		tmp = tmp->next;
	} while (tmp != node);
	return (save);
}

static int	find_path(t_node *curr)
{
	t_node	*tmp;

	if (curr == NULL)
		return (FAILURE);
	for (int i = 0; curr->graph && curr->graph[i]; ++i) {
		tmp = curr->graph[i];
		if (tmp->visited)
			continue;
		if (tmp->path == -1 || tmp->path > curr->path + 1) {
			tmp->path = curr->path + 1;
			tmp->shortest = curr;
		}
	}
	curr->visited = true;
	return (SUCCESS);
}

// Implementation of djikstra algorithm
void	djikstra(t_node **node)
{
	t_node	*end = get_room(*node, END);

	end->path = 0;
	find_path(end);
	while (check_visited_nodes(*node) == false)
		if (find_path(get_smallest_distance(*node)) == FAILURE)
			break;
	clean_up(node);
}