/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** display
*/

#include "lemin.h"

void diaplay_infos(s_infos *infos, char **tab)
{
	t_room	*head = infos->rooms;
	t_room	*i_room = NULL;

	my_printf("#number_of_ants\n");
	my_printf("#rooms\n");
	do {
		i_room = (t_room *)infos->data;
		my_printf("%s", i_room->name_room);
		my_printf("%d %d\n", i_room->x, i_room->y);
	} while (infos->rooms != head);
}