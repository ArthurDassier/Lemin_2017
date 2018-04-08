/*
** EPITECH PROJECT, 2018
** init_infos.c
** File description:
** Arthur
*/

#include "lemin.h"

int found_l_problem(char *str)
{
	int	i = 0;

	while (str[i] != '\n' && str[i] != '#'
	&& str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		++i;
	return (i);
}

void init_inf(t_infos **infos)
{
	if (infos == NULL)
		return;
	(*infos)->rooms = NULL;
	(*infos)->tunnels = NULL;
	(*infos)->t_display = NULL;
}
