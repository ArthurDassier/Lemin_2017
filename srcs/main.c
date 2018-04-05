/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function
*/
#include "lemin.h"

int main()
{
	char	**tab = NULL;
	t_infos	*infos = NULL;
	t_node	*node = NULL;

	tab = recup_anthill(&infos, tab);
	init_graph(&node, infos, tab);
}