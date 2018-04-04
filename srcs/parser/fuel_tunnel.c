/*
** EPITECH PROJECT, 2018
** fuel_tunnel.c
** File description:
** Arthur
*/

#include "lemin.h"
#include "define.h"
#include <stdio.h>

char **fuel_room_name(t_infos *infos)
{
	int	i = 0;
	t_node	*tmp = infos->rooms;
	char	**tab;
	t_room	*tmp3 = NULL;

	while (i == 0 || tmp != infos->rooms) {
		++i;
		tmp = tmp->next;
	}
	tab = malloc(sizeof(char *) * (i + 1));
	tmp = infos->rooms;
	i = 0;
	while (i == 0 || tmp != infos->rooms) {
		tmp3 = (t_room *)tmp->data;
		tab[i] = tmp3->name_room;
		++i;
		tmp = tmp->next;
	}
	tab[i] = NULL;
	if (check_for_double_names(tab) == FAILURE)
		return (NULL);
	return (tab);
}

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

static int look_for_index(char **line, t_infos *infos)
{
	t_node		*tmp = infos->rooms;
	int		*tab = malloc(sizeof(int) * 3);
	int		room = 0;
	t_room		*tmp2 = NULL;

	line[1][my_strlen(line[1]) - 1] = '\0';
	for (int i = 0; i == 0 || tmp != infos->rooms; ++i) {
		tmp2 = (t_room *)tmp->data;
		if (my_strcmp(tmp2->name_room, line[0]) == 0) {
			tab[0] = i;
			++room;
		}
		if (my_strcmp(tmp2->name_room, line[1]) == 0) {
			tab[1] = i;
			++room;
		}
		tmp = tmp->next;
	}
	if (room != 2)
		return (FAILURE);
	tab[2] = -1;
	insert_end(&infos->tunnels, tab);
	return (SUCCESS);
}

int fuel_tnl(char **line, t_infos *infos)
{
	if (!line[0] || !line[1] || line[2])
		return (FAILURE);
	if (look_for_index(line, infos) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
