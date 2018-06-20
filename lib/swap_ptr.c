/*
** EPITECH PROJECT, 2018
** swap_ptr
** File description:
** swap_ptr
*/

void swap_ptr(char **ptr1, char **ptr2)
{
	char *tmp = *ptr1;

	*ptr1 = *ptr2;
	*ptr2 = tmp;
}
