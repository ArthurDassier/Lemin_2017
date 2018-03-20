/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function
*/
#include "lemin.h"

int main(int ac, char **av)
{
	//t_graph	*graph = create_graph(5);

	(void)ac;
	(void)av;
	t_tunnels *tun = malloc(sizeof(t_tunnels));
	t_room **room = recup_anthill(tun, 4);

	(void)ac;
	(void)av;
//	print_graph(graph);
	return (0);
}
