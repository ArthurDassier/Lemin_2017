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

static void	first_ant(t_room *room, t_node **ant_list, t_node *tmp)
{
	static int nb_ant = 0;
	t_ant	*ant = malloc(sizeof(*ant));
	
	if (tmp) {
		ant->room = tmp;
		((t_room *)tmp->data)->ant = true;
		ant->ant_nb = ++nb_ant;
		display_moves(ant->ant_nb,
		((t_room *)ant->room->data)->name_room);
		room->ant_total -= 1;
		if (((t_room *)ant->room->data)->type != END)
			insert_end(ant_list, ant);
		else
			((t_room *)ant->room->data)->ant_total += 1;
	}
}

static void	move_ants(t_node *node, t_node **ant_list)
{
	t_node	*tmp;
	t_node	*path;
	t_ant	*ant = malloc(sizeof(*ant));
	t_room	*room =(t_room *)node->data;

	while (*ant_list != NULL && (tmp = check_ants(*ant_list)) != NULL) {
		path = get_right_path(((t_ant*)tmp->data)->room);
		if (path)
			update_ants(path, tmp, ant_list);
	}
	if (room->ant_total != 0) {
		tmp = get_right_path(node);
		first_ant(room, ant_list, tmp);
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

void	send_ants(t_node **node)
{
	int	total = get_total(get_room(*node, START));
	t_node	*ant_list = NULL;
	t_node	*end;

	djikstra(node);
	*node = get_room(*node, START);
	end = get_room(*node, END);
	while (get_total_end(end) != total) {
		move_ants(*node, &ant_list);
		reset_move(ant_list);
		my_printf("\n");
	}
}