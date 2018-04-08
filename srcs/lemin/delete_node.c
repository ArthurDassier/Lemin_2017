/*
** EPITECH PROJECT, 2018
** delete_node.c
** File description:
** function to delete a given node
*/
#include "lemin.h"

static t_node *find_node(t_node *node, int id)
{
	t_node *tmp = node;
	t_ant	*ant;

	do {
		ant = (t_ant *)tmp->data;
		if (ant->ant_nb == id)
			return (tmp);
		tmp = tmp->next;
	} while (tmp != node);
	return (NULL);
}

void	delete_node(t_node **head, int id)
{
	t_node *curr = *head;

	if (*head == NULL)
		return;
	curr = find_node(*head, id);
	if (curr->next == *head && curr->prev == *head) {
		free(*head);
		*head = NULL;
		return;
	}
	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;
	if (curr == *head)
		(*head) = curr->next;
	free(curr);
	return;
}