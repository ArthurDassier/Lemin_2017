/*
** EPITECH PROJECT, 2018
**1 CPE_lemin_2017
** File description:
** lem_in
*/
#include "lemin.h"

static t_node *get_right_path(t_node *node)
{
	t_node	*save = NULL;
	t_node	*tmp = node;
	t_room	*room;

	for (int i = 0; tmp->graph && tmp->graph[i]; ++i) {
		room = (t_room *)tmp->graph[i]->data;
		if (((save == NULL || tmp->graph[i]->path < save->path)
		&& (room->ant == false || room->type == END))
		&& ((t_room *)node->data)->type != END)
			save = tmp->graph[i];
	}
	return (save);
}

static int get_total(t_node *node)
{
	t_room *room = (t_room *)node->data;

	return (room->ant_total);
}

static	t_node	*check_ants(t_node *ant_list)
{
	t_node	*tmp = ant_list;
	t_ant	*ant;

	do {
		ant = (t_ant *)tmp->data;
		if (ant->moved == false)
			return (tmp);
		tmp = tmp->next;
	} while (tmp != ant_list);
	return (NULL);
}

static void	update_ants(t_node *path, t_node *tmp, t_node **ant_list)
{
	t_ant *ant= (t_ant *)tmp->data;
	t_room	*room = (t_room *)ant->room->data;

	ant->moved = true;
	room->ant = false;
	ant->room = path;
	room = (t_room *)path->data;
	if (room->type == END) {
		delete_node(ant_list, ant->ant_nb);
		room->ant_total += 1;
	}
	else
		room->ant = true;
	printf("Ant id : %d is moving to room : %s\n", ant->ant_nb, room->name_room);
}

static void	move_ants(t_node *node, t_node **ant_list)
{
	t_node	*tmp;
	t_node	*path;
	t_ant	*ant = malloc(sizeof(*ant));
	t_room	*room =(t_room *)node->data;
	t_ant	*save;

	while (*ant_list != NULL && (tmp = check_ants(*ant_list)) != NULL) {
		printf("path = %p\n", path);
		path = get_right_path(((t_ant*)tmp->data)->room);
		printf("path  after= %p\n", path);		
		if (path) {
			display_room_info(path, (t_room *)path->data);
			update_ants(path, tmp, ant_list);
		}
	}
	if (room->ant_total != 0) {
		tmp = get_right_path(node);
		display_room_info(tmp, (t_room *)tmp->data);
		if (tmp) {
			ant->room = tmp;
			ant->moved = false;
			((t_room *)tmp->data)->ant = true;
			if (*ant_list == NULL)
				ant->ant_nb = 1;
			else {
				save = (t_ant *)((*ant_list)->prev->data);
				ant->ant_nb = save->ant_nb + 1;
			}
			room->ant_total -= 1;
			insert_end(ant_list, ant);
		}
	}
}

static void	reset_move(t_node *ant_list)
{
	t_node	*tmp = ant_list;
	t_ant	*ant;

	if (tmp == NULL)
		return;
	do {
		ant = (t_ant *)tmp->data;
		ant->moved = false;
		tmp = tmp->next;
	} while (tmp != ant_list);
}

static int	get_total_end(t_node *node)
{
	t_room *room = (t_room *)node->data;

	return (room->ant_total);
}

void	send_ants(t_node *node)
{
	int	total = get_total(get_room(node, START));
	t_node	*ant_list = NULL;
	t_node	*end;

	djikstra(node);
	node = get_room(node, START);
	end = get_room(node, END);
	while (get_total_end(end) != total) {
		move_ants(node, &ant_list);
		reset_move(ant_list);
	}
}