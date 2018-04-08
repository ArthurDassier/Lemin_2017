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

void	display_room_info(t_node *end, t_room *room)
{
	t_room *lol;

	if (end->shortest) {
		lol = (t_room *)end->shortest->data;
		printf("nb_room = %d & type = %d & path = %d shortest = %d\n", room->nb_room, room->type, end->path, lol->nb_room);
	}
	else
		printf("nb_room = %d & type = %d & path = %d shortest = -1\n", room->nb_room, room->type, end->path);
	
}

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

static void	find_path(t_node *curr)
{
	t_node	*tmp;

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
}

static void	display_rooms(t_node *node)
{
	t_node *tmp = node;
	t_room *room;

	do {
		room = (t_room *)tmp->data;
		display_room_info(tmp, room);	
		tmp = tmp->next;
	} while (tmp != node);
}

void	djikstra(t_node *node)
{
	t_node	*end = get_room(node, END);

	end->path = 0;
	find_path(end);
	while (check_visited_nodes(node) == false)
		find_path(get_smallest_distance(node));
}