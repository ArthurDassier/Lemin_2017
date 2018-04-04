/*
** EPITECH PROJECT, 2018
** fuel_tunnel.c
** File description:
** Arthur
*/

#include "lemin.h"
#include "define.h"
#include <stdio.h>

//place index for each room name
char **fuel_room_name(t_infos *infos)
{
	int	i = 0;
	char	**tab;
	t_node	*tmp_node = infos->rooms;
	t_room	*tmp_room = NULL;

	for (i = 0; i == 0 || tmp_node != infos->rooms; ++i)
		tmp_node = tmp_node->next;
	tab = malloc(sizeof(char *) * (i + 1));
	tmp_node = infos->rooms;
	for (i = 0; i == 0 || tmp_node != infos->rooms; ++i) {
		tmp_room = (t_room *)tmp_node->data;
		tab[i] = tmp_room->name_room;
		tmp_node = tmp_node->next;
	}
	tab[i] = NULL;
	if (check_for_double_names(tab) == FAILURE)
		return (NULL);
	return (tab);
}

//check if the line is a tunnel
int found_tunnels(char *line)
{
	int	i = 0;

	while (line[i] != '\0') {
		if (line[i] == '-')
			return (1);
		++i;
	}
	return (0);
}

//protect against double declaration of tunnels
static void check_existing_tunnels(t_infos *infos, int *tab)
{
	t_node	*tmp_node = infos->tunnels;
	int	*tmp_tunnel = NULL;

	if (tab[0] == tab[1])
		return;
	if (infos->tunnels == NULL) {
		insert_end(&infos->tunnels, tab);
		return;
	}
	for (int i = 0; i == 0 || tmp_node != infos->tunnels; ++i) {
		tmp_tunnel = (int *)tmp_node->data;
		if (tab[0] == tmp_tunnel[0] && tab[1] == tmp_tunnel[1])
			return;
		tmp_node = tmp_node->next;
	}
	insert_end(&infos->tunnels, tab);
}

//check if tunnels connect existing rooms
static int look_for_index(char **line, t_infos *infos,
int room, t_room *tmp_room)
{
	t_node		*tmp_node = infos->rooms;
	int		*tab = malloc(sizeof(int) * 3);

	for (int i = 0; i == 0 || tmp_node != infos->rooms; ++i) {
		tmp_room = (t_room *)tmp_node->data;
		if (my_strcmp(tmp_room->name_room, line[0]) == 0) {
			tab[0] = i;
			++room;
		}
		if (my_strcmp(tmp_room->name_room, line[1]) == 0) {
			tab[1] = i;
			++room;
		}
		tmp_node = tmp_node->next;
	}
	if (room != 2)
		return (FAILURE);
	tab[2] = -1;
	check_existing_tunnels(infos, tab);
	return (SUCCESS);
}

//get tunnel infos
int fuel_tnl(char **line, t_infos *infos)
{
	if (!line[0] || !line[1] || line[2])
		return (FAILURE);
	line[1][my_strlen(line[1]) - 1] = '\0';
	if (look_for_index(line, infos, 0, NULL) == FAILURE) {
		my_print_err("ERROR : Invalid tunnel\n");
		return (FAILURE);
	}
	return (SUCCESS);
}
