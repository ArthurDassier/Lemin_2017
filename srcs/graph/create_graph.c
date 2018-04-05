/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** create_graph
*/
#include "list.h"
#include "lemin.h"

static void print_room(t_room *tmp)
{
//	my_printf("NB_R ==> %d\n", tmp->nb_room);
	my_printf("\nNAME ==> %s\n", tmp->name_room);
	my_printf("POSX ==> %d\n", tmp->x);
	my_printf("POSY ==> %d\n\n", tmp->y);	
}

static void check_pointers(t_node *room_list)
{
	t_node	*prev = NULL;
	t_node	*next = NULL;
	t_room	*prev_r = NULL;
	t_room	*next_r = NULL;

	my_printf("ENTER CHECK\n");
	if ((prev = room_list->prev) == NULL)
		my_printf("NULL PREV\n");
	prev_r = (t_room *)prev->data;
	print_room(prev_r);
	if ((next = room_list->next) == NULL)
		my_printf("NULL NEXT\n");
	next_r = (t_room *)next->data;
	print_room(next_r);
	my_printf("EXIT CHECK\n");
}

static void remp_rooms_info(t_room *room, t_node *room_list, int i)
{
	t_room	*info = NULL;

	info = (t_room *)room_list->data;
	room->type = info->type;
	room->name_room = info->name_room;
	room->ant_total = info->ant_total;
	room->x = info->x;
	room->y = info->y;	
	room->nb_room = i + 1;
	room->ant = false;
}

// A utility function that creates a graph of V vertices
void	create_graph(t_node **node, t_infos *infos, int vertices)
{
	t_room	*room = NULL;
	t_node	*head_room_list = infos->rooms;

	for (int i = 0; i < vertices; ++i) {
		room = malloc(sizeof(*room));
		if (room == NULL)
			return;
		check_pointers(infos->rooms);
		remp_rooms_info(room, infos->rooms, i);
		print_room(room);
		insert_end(node, room);
		infos->rooms = infos->rooms->next;
	}
	infos->rooms = head_room_list;
}