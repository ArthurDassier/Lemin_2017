/*
** EPITECH PROJECT, 2018
** error_gest.c
** File description:
** Arthur
*/

#include "define.h"

int check_params(char **tab)
{
	if (!tab[0] || !tab[1] || !tab[2])
		return (FAILURE);
	return (SUCCESS);
}
