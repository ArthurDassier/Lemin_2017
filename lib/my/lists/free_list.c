/*
** EPITECH PROJECT, 2017
** free_list.c
** File description:
** function to free the list
*/
#include "list.h"

//Frees the list.
void	free_list(t_node *list, void (*ptr)(void *data))
{
	t_node	*tmp = list;

	tmp = tmp->next;
	while (tmp->next != list) {
		ptr(tmp->prev->data);
		free(tmp->prev);
		tmp = tmp->next;
	}
}