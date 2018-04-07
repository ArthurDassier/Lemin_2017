/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** algo
*/
#include "lemin.h"

// Returns the node of the end
static t_node	*get_end_room(t_node *node)
{
	t_node	*tmp = node;
	t_room	*room;

	do {
		room = (t_room *)tmp->data;
		if (room->type == END)
			return (tmp);
		tmp = tmp->next;
	} while (tmp != node);
	return (NULL);
}

static void	display_room_info(t_node *end, t_room *room)
{
	printf("nb_room = %d & type = %d & path = %d\n", room->nb_room, room->type, end->path);
}

static void	algo(t_node *end, int *i, int *save)
{
	t_room	*room;
	t_room	*room_save;
	int	count = 1;
	t_node *tmp;

	room_save = (t_room *)end->graph[*i]->data;
	printf("nb room = d\n", room_save->nb_room);
	if (end->graph[*i] != NULL)
		tmp = end->graph[*i];
	else
		return;
	do {
		display_room_info(tmp, room);
		room_save = (t_room *)tmp->data;
		for (int j = 0; tmp->graph && tmp->graph[j] != NULL; ++j) {
			room = (t_room *)tmp->graph[j]->data;
			display_room_info(tmp, room);
			if (room->nb_room == room_save->nb_room) {
				if (tmp->graph[j + 1] == NULL) {
					break;
				}
				else
					++j;
			}
			tmp = tmp->graph[j];
			if (tmp->path == -1)
				tmp->path = 0;
			++count;
			room = (t_room *)tmp->data;
			tmp->path += count;
			if (room->type == START || room_save->type == START)
				break;
		}
		if (room->type == START || room_save->type == START)
			break;
	} while (tmp != end);
	save[*i] = tmp->path;
	printf("save[%d] = %d\n", *i, save[*i]);
	*i = *i + 1;
	display_room_info(tmp, room);
}

void	repeat(t_node *node)
{
	int	i = 0;
	t_node	*end = get_end_room(node);
	int	*save = malloc(sizeof(*save) * get_graph_len(end->graph));

	while (end->graph && end->graph[i] != NULL)
		algo(end, &i, save);
}